#include <math.h>
#include <iostream>
#include <tuple>

// function to perform state prediction step of kalman filter

double newMean, newVar; 

std::tuple<double,double> statePrediction(double mu1, double var1, double mu2, double var2){
    // add the two beliefs in order to get the posterior belief

    newMean = mu1 + mu2;
    newVar = var1 + var2;

    return std::make_tuple(newMean,newVar);
}

int main(int argc, char** argv){
    std::tie(newMean, newVar) = statePrediction(10, 4, 12, 4);
    printf("[%f, %f]", newMean, newVar);

    return 0;
}