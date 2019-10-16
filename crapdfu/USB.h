#pragma once
#include <iostream>
#include <libusb.h>
#pragma comment(lib, "libusb-1.0.lib")
class USB {
private:
	struct libusb_device_descriptor deviceDescriptor;
	libusb_device_handle* deviceHandle;
	bool isBadDevice;
public:
	USB(libusb_device* from);
	~USB();
	std::string getiProductString();
	bool isGoodDevice();
};

