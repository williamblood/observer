#include "opencv2/opencv.hpp"
#include "FileHandler.h"

using namespace std;

const int fps = 25;


void renderStream(const string& rtspURL);

int main()
{
	IPCamera myCam;
	string rlcRTSPURL = myCam.get_rtsp_url();

	cout << "\n-------------------------------------\n"
		<< "[CAMERA]\nIP ADDRESS:\t"
		<< myCam.ip_address
		<< "\n-------------------------------------\n" << endl;

	string testURL = "rtsp://admin:@" + myCam.ip_address + ":554//h264Preview_01_main";

	renderStream(testURL);
	// renderStream(rlcRTSPURL);

	return 0;
}

void renderStream(const string& url)
{
	cv::VideoCapture stream(url);
	
	assert(stream.isOpened());

	cv::Mat frame;		// stores current frame 
	cv::namedWindow("RTSP IP Camera", );

	// 1000 miliseconds
	while (stream.read(frame))
	{
		cv::imshow("RTSP IP Camera", frame);

		if (cv::waitKey(1000 / fps) >= 0)
			return;
	}
}