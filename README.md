# MathWorks.Cpp

C++ API with OpenCV style interface for a handful of Matlab functions that I've found to be useful. No dependancy to Matlab runtime or Matlab license required.

Dependencies: OpenCV version 3.4.6 (CMake can be modified to use a differnt version, but no guarantee for compatibility)

## To build on Windows 64 bit (tested with Visual Studio 2017):
1. Build or download OpenCV 3.4.6
2. mkdir build
3. cd build
4. cmake .. -G "Visual Studio 15 2017 Win64" -D OpenCV_DIR=<Path To build dir> 
5. cmake --build . --config <debug/release>
