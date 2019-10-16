#include "USBManager.h"
// #define ISDEBUG_BUILD
USBManager::USBManager() {
	libusb_init(NULL); // setup libusb
}

USBManager::~USBManager() {
	libusb_exit(NULL); // shutdownn libusb
}

std::unique_ptr<USB> USBManager::GetDeviceFromiProduct(std::string iProductString) {
	libusb_device** arrayOfPointersToDevices = NULL;
	ssize_t numUSBDevices = libusb_get_device_list(NULL, &arrayOfPointersToDevices);
	for (ssize_t deviceIndex = 0; deviceIndex < numUSBDevices; deviceIndex++) {
		std::unique_ptr<USB> USBPtr(std::make_unique<USB>(arrayOfPointersToDevices[deviceIndex]));
		if (USBPtr->isGoodDevice()) {
			std::string iProductStringFromUSB = USBPtr->getiProductString();
#ifdef ISDEBUG_BUILD
			std::cout << "\tDevice: " << iProductStringFromUSB << std::endl;
#endif
			if (iProductStringFromUSB.compare(iProductString) == 0) {
				return USBPtr;
			}
		}
	}
	return nullptr;
}

std::unique_ptr<USB> USBManager::GetiDeviceInDFUMode() {
	return this->GetDeviceFromiProduct("Apple Mobile Device (DFU Mode)");
}
