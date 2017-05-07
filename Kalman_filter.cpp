#include "opencv2/core/core.hpp"
#include <vector>
#include <iostream>

using cv::Mat
using std::cout;
using std::endl;
using std::vector;

//KGAIN CALCULATER - OPENCV
Mat Kalman_filter2(Mat s, Mat obs,Mat& M,Mat Ahat,Mat Bhat,Mat H,Mat varianceu,Mat variancew)
{
    
    Mat Khat;
    //prediction: based on the model estimating the next state and MSE
    // M: MSE between the true value and prediction in prediction step.
    M = Ahat*(M)*Ahat.t() + Bhat*(varianceu)*Bhat.t();
    //correction: Correcting the estimate based on the observed data.
    Khat = H*M*H.t() + variancew ;// Khat: is K-gain based on the correlation of the observation data to estimated data we define the weights of the weighted average to estimate true s.
    Mat Khat_inv = Khat.inv();
    Khat = M*H.t()* Khat_inv;
    std::cout<<Khat<<std::endl;
    
    // estimating the state value based on the observed data and state obtained using state transition matrix
    s = s +  Khat*(obs - H*s);
    std::cout<<" Khat: "<<Khat<<std::endl;
    M = M - Khat*H*M;// MSE in correction step
    
    return s;
}

int main()
{
	
}
