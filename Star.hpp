#include <iostream>
#include <vector>
#include <cmath>

#include "Constants.hpp"

class Star {
private:
    std::vector<double> position;  // Position in space (x, y, z)
    std::vector<double> velocity;  // Velocity components (vx, vy, vz)
    std::vector<double> acceleration;  // Acceleration components (ax, ay, az)
    std::vector<double> force;  // Force components (Fx, Fy, Fz)
    double mass;  // Mass of the star

public:
    // Constructor
    Star(const std::vector<double>& initialPosition, const std::vector<double>& initialVelocity, double starMass) :
        position(initialPosition), velocity(initialVelocity), mass(starMass) {
            // Initialize acceleration and force to zeros
            acceleration = {0.0, 0.0, 0.0};
            force = {0.0, 0.0, 0.0};
    }

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

    // Newton's law of gravitation
    void computeForce(const Star& otherStar) {
        // Compute the distance between the two stars
        double distance = 0.0;
        for (size_t i = 0; i < position.size(); ++i) {
            distance += pow(position[i] - otherStar.position[i], 2);
        }
        distance = sqrt(distance);


        // Compute the force
        double forceMagnitude = G * mass * otherStar.mass / pow(distance, 2);

        // Compute the force components
        for (size_t i = 0; i < position.size(); ++i) {
            force[i] = forceMagnitude * (otherStar.position[i] - position[i]) / distance;
        }
    }

    // Compute the acceleration based on the force
    void computeAcceleration() {
        for (size_t i = 0; i < position.size(); ++i) {
            acceleration[i] = force[i] / mass;
        }
    }

};