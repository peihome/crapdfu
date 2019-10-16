#include "USB.h"
USB::USB(libusb_device* fromDevicePointer) {
	if (libusb_get_device_descriptor(fromDevicePointer, &deviceDescriptor) != LIBUSB_SUCCESS) goto isBad;
	if (libusb_open(fromDevicePointer, &deviceHandle) != LIBUSB_SUCCESS) goto isBad;
	if (deviceHandle != NULL && deviceDescriptor.iProduct > 0) return;
isBad:;
	isBadDevice = true;
}
std::string USB::getiProductString() {
	unsigned char cStringiProduct[256];
	if (libusb_get_string_descriptor_ascii(deviceHandle, deviceDescriptor.iProduct, cStringiProduct, sizeof(cStringiProduct)) < 0) return NULL;
	return std::string((char*)&cStringiProduct);
}

USB::~USB() {
	libusb_close(deviceHandle);
	deviceHandle = NULL;
}

bool USB::isGoodDevice() {
	return !isBadDevice;
}
