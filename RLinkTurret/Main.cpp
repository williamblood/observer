#include <fstream>
#include <assert.h>

#include "opencv2/opencv.hpp"
#include "FileHandler.h"

using namespace std;

const int fps = 25;

string getCameraIPAddress();
void renderStream(const string& rtspURL);

int main()
{

	cout << "\n-------------------------------------\n"
		<< "[CAMERA]\nIP ADDRESS:\t" 
		<< getCameraIPAddress()
		<< "\n-------------------------------------\n" << endl;

	string testURL = "rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov";

	renderStream(testURL);

	return 0;
}

void renderStream(const string& rtspURL)
{
	cv::VideoCapture stream(rtspURL);
	
	assert(stream.isOpened());

	cv::Mat frame;		// stores current frame 
	cv::namedWindow("Livestream 1");

	// 1000 miliseconds
	while (stream.read(frame))
	{
		cv::imshow("Livestream 1", frame);

		if (cv::waitKey(1000 / fps) >= 0)
			return;
	}
}

string getCameraIPAddress()
{
	ifstream ipaFile(IP_ADDRESS_PATH);
	string ipAddress;

	if (ipaFile.is_open())
	{
		getline(ipaFile, ipAddress);
		
		ipaFile.close();
	}
	else
		cerr << "File not found.\n";

	return ipAddress;
}