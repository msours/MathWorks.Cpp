
cmake_minimum_required(VERSION 3.9)

set(project_name MathWorks.Cpp)
set(project_version 1.0.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/MathWorks.Cpp/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/MathWorks.Cpp/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/MathWorks.Cpp/lib)

set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")

project(${project_name} DESCRIPTION "C++ Interface for some Matlab functionality that I've found to be useful.")

include_directories(
    ./include
)

set(mathworks_dll_dir ${CMAKE_CURRENT_SOURCE_DIR}/dll/x64/MathWorksCpp.dll)
set(mathworks_lib_dir ${CMAKE_CURRENT_SOURCE_DIR}/lib/x64/MathWorksCpp.lib)

add_library(MathWorksCpp SHARED IMPORTED)
set_target_properties(MathWorksCpp PROPERTIES IMPORTED_LOCATION ${mathworks_dll_dir})
set_target_properties(MathWorksCpp PROPERTIES IMPORTED_IMPLIB ${mathworks_lib_dir})

file(GLOB_RECURSE Library_HEADERS 
    ./include/*.h
    ./include/*.hpp
)

add_library(${project_name} STATIC
    
    # MathWorks.Cpp source
    source/MathWorks.cpp

    ${Library_HEADERS}
)

FIND_PACKAGE( OpenCV 3.4.6 REQUIRED )
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

target_link_libraries(${PROJECT_NAME} MathWorksCpp)
