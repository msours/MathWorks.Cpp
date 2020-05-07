
cmake_minimum_required(VERSION 3.9)

set(project_name TestCPP)
set(project_version 1.0.0)

FIND_PACKAGE( OpenCV 3.4.6 REQUIRED )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/TestCPP/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/TestCPP/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/TestCPP/bin)

set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")

project(${project_name} DESCRIPTION "Project for testing MathWorks functionality in C++")

include_directories(
	../MathWorks.Cpp/include
)

add_executable(${project_name} 
	./source/Test.cpp
)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} MathWorks.Cpp)