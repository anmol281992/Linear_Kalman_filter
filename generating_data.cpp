#include "opencv2/core/core.hpp"
#include<fstream>
#include<iostream>
using cv::Mat;
int main()
{
	Mat input = Mat::ones(4,1,CV_32FC1);
    Mat noise = Mat::zeros(4,15,CV_32FC1);
    Mat output(4,1,CV_32FC1);
	Mat A_model =  Mat::eye(4,4,CV_32FC1); // data pattern
	A_model.at<float>(0,0) = 1;
	A_model.at<float>(1,1) = 0.2;
	A_model.at<float>(2,2) = 0.7;
	A_model.at<float>(3,3) = 0.1;
	
	std::ofstream outfile;
    cv::randn(noise,0,0.3); // generating noise
    
	outfile.open("random_generated_vector_series.txt");
	for(int i =0;i<15;i++)
	{
        
        output = input + noise.col(i);
        
		for(int j = 0; j<4 ; j++)
		{
			outfile<<output.at<float>(j)<<" ";
		}
		outfile<<"\n";
        input = A_model*input;
	}
	
	return 0;
}
