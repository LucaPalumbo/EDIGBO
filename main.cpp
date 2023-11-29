#include "Star.hpp"  // Assuming you have the RelativisticStar class in a separate header file

int main() {
    // Create two stars
    std::vector<double> initialPosition1 = {0.0, 0.0, 0.0};
    std::vector<double> initialVelocity1 = {0.8, 0.6, 0.0};
    Star star1(initialPosition1, initialVelocity1, 10.0);

    std::vector<double> initialPosition2 = {1.0, 2.0, 0.0};
    std::vector<double> initialVelocity2 = {-0.5, 0.3, 0.0};
    Star star2(initialPosition2, initialVelocity2, 8.0);

    // Simulate over time
    double totalTime = 10.0;  // You can adjust this based on your simulation requirements
    double deltaTime = 0.1;  // Adjust as needed

    for (double currentTime = 0; currentTime <= totalTime; currentTime += deltaTime) {
        // Simulate motion for both stars
        star1.updatePosition(deltaTime);
        star1.simulateEnergyLoss(deltaTime, 0.01);  // Adjust energy loss rate as needed

        star2.updatePosition(deltaTime);
        star2.simulateEnergyLoss(deltaTime, 0.01);  // Adjust energy loss rate as needed

        // Optionally, print information about the stars at each time step
        std::cout << "Time: " << currentTime << std::endl;
        std::cout << "Star 1 - Position: (" << star1.getPosition()[0] << ", " << star1.getPosition()[1] << ", " << star1.getPosition()[2] << ")"
                  << "  Velocity: (" << star1.getVelocity()[0] << ", " << star1.getVelocity()[1] << ", " << star1.getVelocity()[2] << ")"
                  << "  Mean Angle Deviation: " << star1.calculateMeanAngleDeviation()
                  << std::endl;

        std::cout << "Star 2 - Position: (" << star2.getPosition()[0] << ", " << star2.getPosition()[1] << ", " << star2.getPosition()[2] << ")"
                  << "  Velocity: (" << star2.getVelocity()[0] << ", " << star2.getVelocity()[1] << ", " << star2.getVelocity()[2] << ")"
                  << "  Mean Angle Deviation: " << star2.calculateMeanAngleDeviation()
                  << std::endl;

        std::cout << std::endl;  // Separate output for each time step
    }

    return 0;
}