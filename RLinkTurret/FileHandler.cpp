#include <fstream>
#include <iostream>
#include <assert.h>

#include "FileHandler.h"

using namespace std;

string const IP_ADDRESS_PATH("C:\\Users\\wbloo\\OneDrive\\Documents\\RLC_IP_ADDRESS.txt");

IPCamera::IPCamera()
{
	ifstream ipcSrcFile(IP_ADDRESS_PATH);

	if (ipcSrcFile.is_open())
	{
		getline(ipcSrcFile, ip_address);
		getline(ipcSrcFile, rtsp_username);
		getline(ipcSrcFile, rtsp_password);
		getline(ipcSrcFile, rtsp_port);
		getline(ipcSrcFile, rtsp_path);

		ipcSrcFile.close();
	}
	else
		cerr << "File not found.\n";
}

string IPCamera::get_rtsp_url() const
{
	return ("rtsp://" + rtsp_username + ":" + rtsp_password
		+ "@" + ip_address + ":" + rtsp_port 
		+ "//" + rtsp_path);
}

string IPCamera::get_ip_address() const
{
	return ip_address;
}

IPCamera::~IPCamera()
{
}