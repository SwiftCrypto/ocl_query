# ocl_query
OpenCL Query program

## Build
Make sure that `cmake` v3.1 and above is installed on your system, as the 
build system is based on it.

### Build For Windows,
Make sure that the following software is installed:

- `Visual Studio` 
  
  `cmake generator` bases upon `Visual Studio` to generate Visual Studio 
  solution and project files.  

  For supported Multiple Visual Studio versions, please check with 
  `cmake --help`.
 
- `OpenCL SDK` 

   Install NVidia CUDA Toolkit, which includes OpenCL SDK, if your 
   system has NVidia graphics card.

   Or, install Intel/AMD OpenCL SDK if your system has Intel/AMD graphics 
   card. 

In a command prompt window, `cd` to where this source is located, and type

```
$ mkdir build
$ cd build
$ cmake -G "Visual Studio 14 2015" ..
```

Note that the last command generates Visual Studio 2015 solution and 
project files. You may specify any other Visual Studio version that you 
have installed. 

After last command completes, open the solution file, whose name ends with 
'.sln', in the `build` directory with Visual Studio, build and run it.

### Build for Linux
For ubuntu, install the following generic OpenCL SDK packages:
```
$ sudo apt install build-essential ocl-icd-libopencl1 opencl-headers, ocl-icd-opencl-dev
```

Note that the above packages don't have include OpenCL device driver and runtime
library, which should be installed separately.


In command shell, `cd` to where this source is located,

```
$ mkdir build
$ cd build
$ cmake ..
```

## Notes
Note that your OpenCL device driver and runtime library (including Installable Client
Driver loader) are usually included in your graphic card software driver packages, which 
have to be installed to ensure that your OpenCL applications can run.  These packages are
also included in vendor specific OpenCL SDK software packages from Intel, AMD and NVidia,
so it is recommanded that you install vendor specific OpenCL SDK software packages. 


