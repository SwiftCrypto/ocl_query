# ocl_query
OpenCL Query program

## Build
### Prerequisites
1. `cmake`
2. `Visual Studio` -- `cmake` supports multiple Visual Studio versions (check with `cmake --help`)
3. `OpenCL` sdk, which is distributed along with NVidia CUDA Toolkit or as Intel OpenCL SDK.

### Build
For Windows,

In Windows command prompt, `cd` to where this source is located,
```
$ mkdir build
$ cd build
$ cmake -G "Visual Studio 14 2015" ..
```
The last command generates Visual Studio 2015 solution and project files. 
Other Visual Studio versions can also be specified.

Open the solution file in the `build` directory with Visual Studio, build 
and run it.
 



