#pragma once
#include <iostream>
#include <libusb.h>
#include "USB.h"
class USBManager {
private:
	std::unique_ptr<USB> GetDeviceFromiProduct(std::string iProductString);
public:
	USBManager();
	~USBManager();
	std::unique_ptr<USB> GetiDeviceInDFUMode();
};
