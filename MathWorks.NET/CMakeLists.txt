cmake_minimum_required(VERSION 3.12)

set(project_name MathWorks.NET)
set(project_version 1.0.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/MathWorks.NET/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/MathWorks.NET/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/MathWorks.NET/bin)

set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")

project(${project_name} DESCRIPTION ".NET Interface for some Matlab functionality that I've found to be useful.")

include_directories(
    ./include
    ../MathWorks.Cpp/include
	${mw_include}
)

file(GLOB_RECURSE Library_HEADERS 
    ./include/*.h
    ./include/*.hpp
)

add_library(${project_name} SHARED
    source/C_Coder.NET.cpp
	source/Matfile.NET.cpp

    ${Library_HEADERS}
)

target_include_directories(${project_name}
    PUBLIC
        ${CMAKE_BINARY_DIR}/install/${project_name}/include
)

set_target_properties(${PROJECT_NAME} PROPERTIES VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.0")
set_target_properties(${PROJECT_NAME} PROPERTIES VS_DOTNET_REFERENCES "System")

set_target_properties(${PROJECT_NAME} PROPERTIES COMMON_LANGUAGE_RUNTIME "")

target_link_libraries(${PROJECT_NAME} MathWorks.Cpp)

#Install

file(GLOB headers ./include/*.h)
file(GLOB depends_dll 
	../MathWorks.Cpp/dll/x64/*.dll 
	${OpenCV_DIR}/x64/vc15/bin/*.dll 
	${mw_depends}
)

install (FILES ${headers}
    DESTINATION MathWorks.NET/include
)

install (FILES ${depends_dll}
    DESTINATION MathWorks.NET/bin
)

install(TARGETS ${project_name}
    EXPORT ${PROJECT_NAME}-export
    RUNTIME DESTINATION ${PROJECT_NAME}/bin
)

install(EXPORT ${PROJECT_NAME}-export
    FILE ${PROJECT_NAME}Config.cmake 
    DESTINATION cmake
)

