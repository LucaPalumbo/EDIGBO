import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.animation import FuncAnimation
from scipy.constants import speed_of_light, year

# a function that show 3 plots, X-t, Y-t, Z-t
def show_plots(x,y,z,t):
    fig, (ax1, ax2, ax3) = plt.subplots(3, sharex=True)
    ax1.plot(t, x)
    ax1.set_title('X-t')
    ax2.plot(t, y)
    ax2.set_title('Y-t')
    ax3.plot(t, z)
    ax3.set_title('Z-t')
    plt.show()

# a function to read the data from the file
def read_data(filename):
    bx,by,bz,tx,ty,tz = np.loadtxt(filename, delimiter=" ", unpack=True)
    return bx,by,bz,tx,ty,tz

if __name__ == "__main__":
    bx,by,bz,tx,ty,tz = read_data("bullet_target.txt")
    t = np.linspace(0, (31557600 / 1e6)*len(bx), len(bx))
    show_plots(bx,by,bz,t)