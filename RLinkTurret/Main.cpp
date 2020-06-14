#include <fstream>

#include "opencv2/opencv.hpp"
#include "FileHandler.h"


using namespace std;

string getCameraIPAddress();

int main()
{

	cout << "\n-------------------------------------\n"
		<< "[CAMERA]\nIP ADDRESS:\t" 
		<< getCameraIPAddress()
		<< "\n-------------------------------------\n" << endl;

	return 0;
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
	{
		cerr << "File not found.\n";
	}

	return ipAddress;
}