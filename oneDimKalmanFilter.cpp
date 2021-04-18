#include <math.h>
#include <tuple>
#include <iostream>


// TASK
/*
    Given a set of measurements and a set of inputs, estimate the pose that the robot is at

*/

double newMean, newVar;
//test measurements
double measurements[5] = {5,6,7,9,10};  // fake odometry measurements along x-axis
double mesurement_var = 2.0;  // fake variance
// test inputs
double u[5] = {1,1,2,1,1};  // fake motion actuator commands
double motion_var = 0.3;  



//    One dimensional kalman filter

std::tuple<double, double> measurementUpdate(double mu1, double var1, double mu2, double var2);
std::tuple<double, double> statePrediction(double mu1, double var1, double mu2, double var2);



int main(int argc, char** argv){
    // initial state
    double mu = 0.0;
    double variance = 1000;
    for(int i = 0; i< sizeof(measurements)/sizeof(measurements[0]);i++){
        // calculate the measurment update 
        std::tie(newMean,newVar) = measurementUpdate(mu,variance,measurements[i],measurement_var);
        std::cout<<std::endl<< newMean << " " << newVar<< std::endl;
        // calculate the state prediction
        std::tie(newMean,newVar) = statePrediction(newMean,newVar,motion[i],motion_var);
        std::cout<<std::endl<< newMean << " " << newVar<< std::endl;

    }

    return 0;
}


std::tuple<double, double> measurementUpdate(double mu1, double var1, double mu2, double var2){
    // input: mu1 [mean], var1 = sigma1 squared, mu2 [mean], var2 = sigma2 squared
    // output: new mean and new vwar 
    double mean;
    double variance;
    mean = (mu1*var1 + mu2*var2)/var1+var2;
    variance =  1/( (1/var1) + (1/var2) );

    return std::make_tuple(mean,variance);
}

std::tuple<double, double> statePrediction(double mu1, double var1, double mu2, double var2){
    return std::make_tuple( (mu1+mu2), (var1+var2));
}