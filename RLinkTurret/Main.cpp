#include <fstream>
#include <iostream>

#include "opencv2/opencv.hpp"
#include "FileHandler.h"

using namespace std;

const int fps = 20;

void renderStream(const string& rtspURL);

int main()
{
	IPCamera myCam;		// initialize device

	cout << "\n-------------------------------------\n"
		<< "[CAMERA]\nIP ADDRESS:\t"
		<< myCam.get_ip_address()
		<< "\n-------------------------------------\n" << endl;

	renderStream(myCam.get_rtsp_url());

	return 0;
}

void renderStream(const string& url)
{
	cv::VideoCapture stream(url);
	
	assert(stream.isOpened());

	cv::Mat frame;		// stores current frame 
	cv::namedWindow("RTSP IP Camera", 1);

	// 1000 miliseconds
	while (stream.read(frame))
	{
		cv::imshow("RTSP IP Camera", frame);

		if (cv::waitKey(1000 / fps) >= 0)
			return;
	}
}