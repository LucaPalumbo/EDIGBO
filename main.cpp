#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "Star.hpp"  
#include "Constants.hpp"
int main() {
    // Create two stars
    std::vector<double> initialPosition1 = {0.0, 0.0, 0.0};
    std::vector<double> initialVelocity1 = {C, 0.0, 0.0};
    Star bullet(initialPosition1, initialVelocity1, M0);

    std::vector<double> initialPosition2 = {LY, LY/100, 0.0};
    std::vector<double> initialVelocity2 = {0.0, 0.0, 0.0};
    Star target(initialPosition2, initialVelocity2, M0 / 1e3) ;


    for (size_t i = 0; i < 200; ++i) {
        bullet.computeForce(target);
        target.computeForce(bullet);
        bullet.computeAcceleration();
        target.computeAcceleration();
        bullet.updatePosition(SEC_PER_YEAR / 100);
        target.updatePosition(SEC_PER_YEAR / 100);
        
        // write to a file position of bullet and target
        std::ofstream myfile;
        myfile.open ("bullet_target.txt", std::ios_base::app);
        myfile << bullet.getPosition()[0] << " " << bullet.getPosition()[1] << " " << bullet.getPosition()[2] << " " << target.getPosition()[0] << " " << target.getPosition()[1] << " " << target.getPosition()[2] << "\n";
        myfile.close();

        // write to a file velocity of bullet and target
        std::ofstream myfile2;
        myfile2.open ("bullet_target_velocity.txt", std::ios_base::app);
        myfile2 << bullet.getVelocity()[0] << " " << bullet.getVelocity()[1] << " " << bullet.getVelocity()[2] << " " << target.getVelocity()[0] << " " << target.getVelocity()[1] << " " << target.getVelocity()[2] << "\n";
        myfile2.close();

    }


    return 0;
}