#ifndef FILE_HANDLER_
#define FILE_HANDLER_

#include <string>

// TODO: Find RLC_IP_ADDRESS.txt file and extract address

class IPCamera
{
public:
	IPCamera();

	std::string get_rtsp_url() const;
	std::string get_ip_address() const;
	
	~IPCamera();

private:
	std::string ip_address;
	std::string rtsp_url;
	std::string rtsp_port;
	std::string rtsp_path;
	std::string rtsp_username;
	std::string rtsp_password;
};

#endif // !FILE_HANDLER_!
