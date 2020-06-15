#include <fstream>
#include <iostream>

#include "FileHandler.h"

using namespace std;

string const IP_ADDRESS_PATH("C:\\Users\wbloo\OneDrive\Documents\RLC_IP_ADDRESS.txt");

IPCamera::IPCamera()
{
	ifstream ipcSrcFile(IP_ADDRESS_PATH);

	if (ipcSrcFile.is_open())
	{
		getline(ipcSrcFile, ip_address);

		ipcSrcFile.close();
	}
	else
		cerr << "File not found.\n";

	rtsp_path = "//h264Preview_01_main";
	rtsp_port = "544";
}

string IPCamera::get_rtsp_url() const
{
	return ("rtsp://" + user_credentials + ip_address + ":" + rtsp_port + rtsp_path);
}

IPCamera::~IPCamera()
{
}