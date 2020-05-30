cmake_minimum_required(VERSION 3.9)

set(project_name MathWorks.NET.Tests)
set(project_version 1.0.0)

set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")
set(CMAKE_CSharp_FLAGS "/langversion:6")

project(${project_name} LANGUAGES CSharp DESCRIPTION "C# integration tests")

add_executable(${project_name}
	Program.cs
)

set_property(TARGET ${project_name} PROPERTY VS_DOTNET_REFERENCES
    "System"
    "System.Core"
)

set_property(TARGET ${project_name} PROPERTY VS_DOTNET_REFERENCE_Microsoft.VisualStudio.QualityTools.UnitTestFramework
    "./dll/Microsoft.VisualStudio.QualityTools.UnitTestFramework.dll"
)

target_link_libraries(${project_name} MathWorks.NET)

#Install

file(GLOB depends_dll ./dll/*.dll ${OpenCV_DIR}/x64/vc15/bin/*.dll )

install(TARGETS ${project_name}
	RUNTIME DESTINATION ${project_name}/bin
)

install(TARGETS MathWorks.NET
 	RUNTIME DESTINATION ${project_name}/bin
)

install (FILES ${depends_dll}
    DESTINATION ${project_name}/bin
)
