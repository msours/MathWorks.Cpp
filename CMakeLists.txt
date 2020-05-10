cmake_minimum_required(VERSION 3.12)

set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")

set(parent_project_name  MathWorksCpp)
set(project_version 1.0.0)

project(${parent_project_name} DESCRIPTION "Some Matlab functionality I've found to be useful, accesible from C++ and .Net")

add_subdirectory(MathWorks.CPP)
add_subdirectory(MathWorks.NET)
add_subdirectory(TestCpp)