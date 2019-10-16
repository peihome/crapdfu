#include <iostream>
#include "USBManager.h"
#include "USB.h"

#define ERROR_USBMANAGER_SETUP		0x1;
#define ERROR_GETTINGIDEVICE		0x2;

int main(int argc, char *argv[]) {
	std::unique_ptr<USBManager> USBMan(std::make_unique<USBManager>());
	if (USBMan == nullptr) {
		std::cout << "USBManager failed" << std::endl;
		return ERROR_USBMANAGER_SETUP;
	}
	std::unique_ptr<USB> iDevice(USBMan->GetiDeviceInDFUMode());
	if (iDevice == nullptr) {
		std::cout << "Failed getting iDevice in DFU, is it in DFU?" << std::endl;
		return ERROR_GETTINGIDEVICE;
	}
	std::cout << "Found DFU Device!" << std::endl;
	return ERROR_SUCCESS;
}