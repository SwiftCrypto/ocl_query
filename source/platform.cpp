#include <stdio.h>                                                                                                                                               
#include <stdlib.h>
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif


int main() {

	cl_uint platformCount;
	cl_platform_id* platforms;
	cl_uint deviceCount;
	cl_device_id* devices;

	// get all platforms
	clGetPlatformIDs(0, NULL, &platformCount);
	platforms = new cl_platform_id[platformCount];
	clGetPlatformIDs(platformCount, platforms, NULL);
	printf("Total platforms: %d\n\n", platformCount);

	for (unsigned i = 0; i < platformCount; i++) {

		const char* platformInfoStrings[] = { 
			"Name", 
			"Vendor",
			"Version", 
			"Profile", 
			"Extensions" 
		};
		const cl_platform_info platformInfos[] = {
			CL_PLATFORM_NAME, 
			CL_PLATFORM_VENDOR,
			CL_PLATFORM_VERSION, 
			CL_PLATFORM_PROFILE, 
			CL_PLATFORM_EXTENSIONS 
		};

		printf("Platform %d:\n", i);
		for (int j = 0; j < sizeof(platformInfos) / sizeof(platformInfos[0]); j++) {
			size_t	infoSize;
			char	*info;

			// get platform attribute value size
			clGetPlatformInfo(platforms[i], platformInfos[j], 0, NULL, &infoSize);
			info = new char[infoSize];

			// get platform attribute value
			clGetPlatformInfo(platforms[i], platformInfos[j], infoSize, info, NULL);

			printf("%*s%-12s: %s\n", 4, "", platformInfoStrings[j], info);
			delete[] info;
		}

		// get all devices
		clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &deviceCount);
		devices = new cl_device_id[deviceCount];
		clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, deviceCount, devices, NULL);

		// for each device print critical attributes
		for (unsigned j = 0; j < deviceCount; j++) {

			const char* deviceInfoStrings[] = {
				"Name",
				"Hardware version",
				"Software version",
				"OpenCL C version",
				"Parallel compute units"
			};
			const cl_device_info deviceInfos[] = {
				CL_DEVICE_NAME,
				CL_DEVICE_VERSION,
				CL_DRIVER_VERSION,
				CL_DEVICE_OPENCL_C_VERSION,
				CL_DEVICE_MAX_COMPUTE_UNITS
			};

			printf("%*s%-10s %d: \n", 4, "", "Device", j);
			for (unsigned k = 0; k < sizeof(deviceInfos)/sizeof(deviceInfos[0]); ++k) {
				char* value;
				size_t valueSize;

				clGetDeviceInfo(devices[j], deviceInfos[k], 0, NULL, &valueSize);
				value = new char[valueSize];
				clGetDeviceInfo(devices[j], deviceInfos[k], valueSize, value, NULL);
				if (CL_DEVICE_MAX_COMPUTE_UNITS == deviceInfos[k]) {
					printf("%*s%-24s: %d\n", 8, "", deviceInfoStrings[k], *(int*)value);
				}
				else {
					printf("%*s%-24s: %s\n", 8, "", deviceInfoStrings[k], value);
				}
				delete[] value;
			}

		}

		delete[] devices;

	}

	delete[] platforms;
	return 0;

}
