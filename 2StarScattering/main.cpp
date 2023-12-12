#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "../Star.hpp"  
#include "../Constants.hpp"

long double estimatedEnergyLoss(){
    long double bulletMass = M0;
    long double targetMass = M0 / 1e3;
    long double bulletVelocity = C/10;
    long double impactParameter = LY / 100;
    long double impulse =  2 * G * bulletMass * targetMass / (bulletVelocity * impactParameter);
    long double energyLoss = pow(impulse,2) / (2 * targetMass);
    return energyLoss;
}

int main() {
    long double DeltaTime = SEC_PER_YEAR / 1000;
    // Create two stars
    std::vector<long double> initialPosition1 = {0.0, 0.0, 0.0};
    std::vector<long double> initialVelocity1 = {C/10, 0.0, 0.0};
    Star bullet(initialPosition1, initialVelocity1, M0);

    std::vector<long double> initialPosition2 = {LY, LY/100, 0.0};
    std::vector<long double> initialVelocity2 = {0.0, 0.0, 0.0};
    Star target(initialPosition2, initialVelocity2, M0 / 1e3) ;


    long double initialBulletKineticEnergy = bullet.getKineticEnergy();
    long double initialTargetKineticEnergy = target.getKineticEnergy();
    std::cout << "Initial kinetic energy of bullet: " << initialBulletKineticEnergy << std::endl;
    std::cout << "Initial kinetic energy of target: " << initialTargetKineticEnergy << std::endl;

    while( bullet.computeDistance(target) < 1.1*LY ) {
         // write to a file position of bullet and target
        std::ofstream myfile;
        myfile.open ("DataVisualization/bullet_target.txt", std::ios_base::app);
        myfile << bullet.getPosition()[0] << " " << bullet.getPosition()[1] << " " << bullet.getPosition()[2] << " " << target.getPosition()[0] << " " << target.getPosition()[1] << " " << target.getPosition()[2] << "\n";
        myfile.close();

        // write to a file velocity of bullet and target
        std::ofstream myfile2;
        myfile2.open ("DataVisualization/bullet_target_velocity.txt", std::ios_base::app);
        myfile2 << bullet.getVelocity()[0] << " " << bullet.getVelocity()[1] << " " << bullet.getVelocity()[2] << " " << target.getVelocity()[0] << " " << target.getVelocity()[1] << " " << target.getVelocity()[2] << "\n";
        myfile2.close();

        bullet.computeForce(target);
        target.computeForce(bullet);
        bullet.computeAcceleration();
        target.computeAcceleration();
        bullet.updatePosition(DeltaTime);
        target.updatePosition(DeltaTime);
        
        // std::cout << "kinetic energy : " << bullet.getKineticEnergy() << "\t" << target.getKineticEnergy() << std::endl;
       
    }

    long double finalBulletKineticEnergy = bullet.getKineticEnergy();
    long double finalTargetKineticEnergy = target.getKineticEnergy();
    long double energyLossBullet = finalBulletKineticEnergy - initialBulletKineticEnergy;
    long double energyLossTarget = finalTargetKineticEnergy - initialTargetKineticEnergy;
    std::cout << "Energy loss of bullet: \t" << energyLossBullet << std::endl;
    std::cout << "Energy loss of target: \t" << energyLossTarget << std::endl;
    std::cout << "Expected energy loss: \t" << estimatedEnergyLoss() << std::endl;
    return 0;
}