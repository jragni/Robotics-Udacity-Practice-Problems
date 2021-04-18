#include <math.h>
#include <tuple>
#include <iostream>
#include <iostream>
#include <tuple>
#include "math.h"
#include "eigen"
#include "Core"
#include "LU"


/* Task:
    Given position and velocity states, odometry measurements, and the variances of both. determine the Posterior State and Covariance
*/
using namespace std;
using namespace eigen;

float measurements[3] = {1,2,3};  // measurements from fake odometry

tuple<matrixXf, matrixXf> kalmanFilter(matrixXf x, matrixXf P, matrixXf u, matrixXf F, matrixXf H, matrixXf R, matrixXf I){
    /*
        input:
            x -> state vector  [n x 1]
            P -> state covariance [n x n]
            u -> input vector   [n x 1]
            F -> state function [n x n] 
            H -> measurement function [n x 1]
            R -> measurement noise [1 x 1] 

        output:
            x -> posterior state vector
            p -> posterior state covariance

        the kalman filter will take in the initial state, perform a measurement update of the states, perform the motion update, calculate the kalman gain, and then determine the posterior state and state covariance. 
    */

    // initialize variables
    for(int i; i<sizeof(measurements)/sizeof(measurements[0]); i++){
        matrixXf z(1,1) 
        
        z << measurements[i];
        
        matrixXf y(1,1);  // measurement update
        y << x - H*z; 
        
        matrixXf S(1,1);  // measurement covariance
        S << H*P*H.transpose() + R;

        // calculate Kalman gain
        MatrixXf K(2,1);
        K << P*H.transpose()*S.inverse();

        // calculate the motion update
        
        x << x + K*y;
        P << (I - K*H)*P;

        // calculate posterior state and Covariance
        x << F*x;
        P << F*P*F.transpose();
    }
    return make_tuple(x,P);

}       


int main(int argc, char** argv){
    MatrixXf x(2, 1);// Initial state (location and velocity) 
    x << 0,
    	 0; 
    MatrixXf P(2, 2);//Initial Uncertainty
    P << 100, 0, 
    	 0, 100; 
    MatrixXf u(2, 1);// External Motion
    u << 0,
    	 0; 
    MatrixXf F(2, 2);//Next State Function
    F << 1, 1,
    	 0, 1; 
    MatrixXf H(1, 2);//Measurement Function
    H << 1,
    	 0; 
    MatrixXf R(1, 1); //Measurement Uncertainty
    R << 1;
    MatrixXf I(2, 2);// Identity Matrix
    I << 1, 0,
    	 0, 1; 

    tie(x, P) = kalman_filter(x, P, u, F, H, R, I);
    cout << "x= " << x << endl;
    cout << "P= " << P << endl;

    return  0;
}