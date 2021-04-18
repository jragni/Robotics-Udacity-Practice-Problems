#include <iostream>
#include <math.h>


using namespace std;

double discreteProbability(double mu, double sigma2, double x){
    // given the mean of the pose, mu, the variance, sigma, and the belief of pose x
    // p(x) = 1 / sqrt(2*pi*sigma) * exp( -((x - mu)/(2*sigma2))   
    
    double prob; // probablity that unit is at x

    prob = 1/sqrt(2*M_PI *sigma2) * exp( -((x - mu)/(2*sigma2))); 

    return prob; 
}


int main(int argc, char** argv){
    cout << discreteProbability(10.0,4.0,8.0);
    return 0;
}