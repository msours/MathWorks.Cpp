## MathWorks.Cpp

C++ API (and C# wrapper) with OpenCV style interface for a handful of Matlab functions, and Matfile reading and writing.

### Building and Installing
Requirements:
* OpenCV 3.4.6
* Local Matlab installation is required for CMake to link some of the dependencies
* Tested with Matlab 2015 and 2019

#### Windows
After cloning the repo,
* `mkdir build`
* `cd build`
* `cmake .. -G "Visual Studio 15 2017 Win64" -D OpenCV_DIR=<Path to opencv build dir>`
* `cmake --build . --config release --target install`
