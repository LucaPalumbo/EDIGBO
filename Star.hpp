#include <iostream>
#include <vector>
#include <cmath>

class Star {
private:
    std::vector<double> position;  // Position in space (x, y, z)
    std::vector<double> velocity;  // Velocity components (vx, vy, vz)
    double mass;  // Mass of the star

public:
    // Constructor
    Star(const std::vector<double>& initialPosition, const std::vector<double>& initialVelocity, double starMass) :
        position(initialPosition), velocity(initialVelocity), mass(starMass) {}

    // Getters
    const std::vector<double>& getPosition() const { return position; }
    const std::vector<double>& getVelocity() const { return velocity; }
    double getMass() const { return mass; }

    // Function to update the star's position based on its velocity
    void updatePosition(double deltaTime) {
        for (size_t i = 0; i < position.size(); ++i) {
            position[i] += velocity[i] * deltaTime;
        }
    }

    // Function to calculate the mean angle deviation
    double calculateMeanAngleDeviation() const {
        return 0.0;
    }

    // Function to simulate energy loss over time
    void simulateEnergyLoss(double deltaTime, double energyLossRate) {
        return;
    }

};