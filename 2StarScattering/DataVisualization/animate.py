import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.animation import FuncAnimation
from scipy.constants import speed_of_light, year

# a function to read the data from the file
def read_data(filename):
    data = np.loadtxt(filename, delimiter=" ")
    return data



def animate(pos_data):
    # Create a 3D plot
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    point1, = ax.plot([], [], [], 'bo', markersize=8)
    point2, = ax.plot([], [], [], 'ro', markersize=8)

    # Set axis limits
    ax.set_xlim([-2*speed_of_light*year, 2*speed_of_light*year])
    ax.set_ylim([-speed_of_light*year/50, speed_of_light*year/50])
    ax.set_zlim([-10, 10])

    # Initialization function for the animation
    def init():
        point1.set_data([], [])
        point1.set_3d_properties([])

        point2.set_data([], [])
        point2.set_3d_properties([])

        return point1, point2
    
    # Update function for the animation
    def update(frame):
        x1, y1, z1, x2, y2, z2 = frame

        point1.set_data(x1, y1)
        point1.set_3d_properties(z1)

        point2.set_data(x2, y2)
        point2.set_3d_properties(z2)

        return point1, point2

    
    animation = FuncAnimation(fig, update, frames=pos_data, init_func=init, interval=1, blit=True)
    plt.show()

if __name__ == "__main__":
    pos_data = read_data("bullet_target.txt")
    pos_data = pos_data[::100]
    animate(pos_data)