cmake_minimum_required(VERSION 3.9)

set(parent_project_name  MathWorksCpp)
set(project_version 1.0.0)

project(${parent_project_name} DESCRIPTION "Some Matlab functionality I've found to be useful, accesible from C++ and .Net")

add_subdirectory(MathWorks.CPP)
add_subdirectory(TestCpp)