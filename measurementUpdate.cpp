#include <math.h>
#include <iostream>
#include <tuple>

double newMean, newVar;

std::tuple<double,double> measurementUpdate(double mu1, double var1, double mu2, double var2){
    // calculate mean of prior belief 
    newMean = (mu1*var2 + mu2*var1)/(var1*var1 + var2*var2);
    newVar = 1 / (1/(var1*var1) + 1/(var2*var2));
    return std::make_tuple(newMean,newVar);
}


int main(int argc, char** argv){

    tie(newMean,newVar) = measurementUpdate(10, 3, 13, 2);

    printf("[%f,%f]");

    return 0;
}