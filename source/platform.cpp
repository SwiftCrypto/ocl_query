#define __CL_ENABLE_EXCEPTIONS

#if defined(__APPLE__) || defined(__MACOSX)
#include <OpenCL/cl.hpp>
#else
#include <CL/cl.hpp>
#endif
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

int main()
{
    // get all platforms
    cl_int err = CL_SUCCESS;
    try {
        std::vector<cl::Platform> platforms;
        cl::Platform::get(&platforms);
        if (platforms.size() == 0) {
            std::cout << "Platform size 0\n";
            return -1;
        }
        std::cout << "Total platforms: " << platforms.size() << std::endl
                  << std::endl;

        for (unsigned i = 0; i < platforms.size(); i++) {
            std::vector<std::string> platformInfoStrings{"Name", "Vendor", "Version",
                "Profile", "Extensions"};
            std::vector<cl_platform_info> platformInfos{
                CL_PLATFORM_NAME, CL_PLATFORM_VENDOR, CL_PLATFORM_VERSION,
                CL_PLATFORM_PROFILE, CL_PLATFORM_EXTENSIONS};

            printf("Platform %d:\n", i);
            for (unsigned j = 0; j < platformInfos.size(); j++) {
                std::string infoString;
                platforms[i].getInfo(platformInfos[j], &infoString);
                printf("%*s%-12s: %s\n", 4, "", platformInfoStrings[j].c_str(), infoString.c_str());
            }

            // get all devices
            std::vector<cl::Device> devices;
            platforms[i].getDevices(CL_DEVICE_TYPE_ALL, &devices);

            // for each device print critical attributes
            for (unsigned j = 0; j < devices.size(); j++) {
                std::vector<std::string> deviceInfoStrings{
                    "Name", "Hardware version", "Software version",
                    "OpenCL C version", "Parallel compute units"};
                std::vector<cl_device_info> deviceInfos{
                    CL_DEVICE_NAME, CL_DEVICE_VERSION, CL_DRIVER_VERSION,
                    CL_DEVICE_OPENCL_C_VERSION, CL_DEVICE_MAX_COMPUTE_UNITS};

                printf("%*s%-10s %d: \n", 4, "", "Device", j);
                for (unsigned k = 0; k < deviceInfoStrings.size(); ++k) {
                    if (CL_DEVICE_MAX_COMPUTE_UNITS == deviceInfos[k]) {
                        int value;
                        devices[j].getInfo(deviceInfos[k], &value);
                        printf("%*s%-24s: %d\n", 8, "", deviceInfoStrings[k].c_str(),
                            value);
                    } else {
                        std::string value;
                        devices[j].getInfo(deviceInfos[k], &value);
                        printf("%*s%-24s: %s\n", 8, "", deviceInfoStrings[k].c_str(),
                            value.c_str());
                    }
                }
            }
        }
    } catch (cl::Error err) {
        std::cerr
            << "ERROR: "
            << err.what()
            << "("
            << err.err()
            << ")"
            << std::endl;
    }

    return 0;
}
