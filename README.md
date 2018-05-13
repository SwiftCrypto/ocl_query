# ocl_query
OpenCL Query program

## Build
### Prerequisites
1. `cmake`
2. `Visual Studio` -- `cmake` supports multiple Visual Studio versions (check with `cmake --help`)
3. `OpenCL` sdk, which is distributed along with NVidia CUDA Toolkit or Intel OpenCL SDK.

### Build
For Windows,

Open command prompt, and `cd` to where this source is located,
```
$ mkdir build
$ cd build
$ cmake -G "Visual Studio 14 2015"
```
The last command generates Visual Studio 2015 solution and project files. 
You can specify other versions of Visual Studio.

Open the solution file in the `build` directory, build and run it.
 



