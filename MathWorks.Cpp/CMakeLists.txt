
cmake_minimum_required(VERSION 3.12)

set(project_name MathWorks.Cpp)
set(project_version 1.0.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/MathWorks.Cpp/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/MathWorks.Cpp/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/MathWorks.Cpp/lib)

set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")

project(${project_name} DESCRIPTION "C++ Interface for some Matlab functionality that I've found to be useful.")

include(FindMatlab)
find_package(Matlab REQUIRED)

set(mw_include "${Matlab_ROOT_DIR}/extern/include" CACHE INTERNAL "mw_include")

include_directories(
    ./include
	./MathWorks/include
	${mw_include}
)

set(mathworks_dll_dir ${CMAKE_CURRENT_SOURCE_DIR}/dll/x64/MathWorksCpp.dll)
set(mathworks_lib_dir ${CMAKE_CURRENT_SOURCE_DIR}/lib/x64/MathWorksCpp.lib)

add_library(MathWorksCpp SHARED IMPORTED)
set_target_properties(MathWorksCpp PROPERTIES IMPORTED_LOCATION ${mathworks_dll_dir})
set_target_properties(MathWorksCpp PROPERTIES IMPORTED_IMPLIB ${mathworks_lib_dir})

set(libmat_lib_dir ${Matlab_ROOT_DIR}/extern/lib/win64/microsoft/libmat.lib)
set(libmx_lib_dir ${Matlab_ROOT_DIR}/extern/lib/win64/microsoft/libmx.lib)

if(EXISTS "${libmat_lib_dir}" AND EXISTS "${libmx_lib_dir}")
elseif()
	MESSAGE(FATAL_ERROR "Incompatible Matlab version ... ")
endif()

add_library(libmat STATIC IMPORTED)
set_target_properties(libmat PROPERTIES IMPORTED_LOCATION ${libmat_lib_dir})

add_library(libmx STATIC IMPORTED)
set_target_properties(libmx PROPERTIES IMPORTED_LOCATION ${libmx_lib_dir})

file(GLOB mw_HEADERS
	${mw_include}/mat.h
	${mw_include}/matrix.h
)

file(GLOB_RECURSE Library_HEADERS 
    ./include/*.h
    ./include/*.hpp
)

add_library(${project_name} STATIC
    
    # MathWorks.Cpp source
    source/C_Coder.cpp
    source/TypeConverters.cpp
	source/CellArray.cpp
	source/MatlabStruct.cpp
	source/Matfile.cpp

	${Library_HEADERS}
	${mw_HEADERS}
)

FIND_PACKAGE( OpenCV 3.4.6 REQUIRED )
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

target_link_libraries(${PROJECT_NAME} MathWorksCpp)
target_link_libraries(${PROJECT_NAME} libmat)
target_link_libraries(${PROJECT_NAME} libmx)

# Install

file(GLOB headers ./include/*.h)
file(GLOB mathworks_headers ./include/MathWorks/*.h mw_HEADERS)
file(GLOB depends_dll ./dll/x64/*.dll ${OpenCV_DIR}/x64/vc15/bin/*.dll)
file(GLOB depends_lib ./lib/x64/*.lib ${libmat_lib_dir} ${libmx_lib_dir})

set(mw_bin ${Matlab_ROOT_DIR}/bin/win64)

file(GLOB mw_depends_dll

	${mw_bin}/hdf5.dll
	${mw_bin}/icudt*.dll
	${mw_bin}/icuin*.dll
	${mw_bin}/icuio*.dll
	${mw_bin}/icuuc*.dll
	${mw_bin}/libexpat.dll
	${mw_bin}/libmat.dll
	${mw_bin}/libmwbwlookup_tbb.dll
	${mw_bin}/libmwbwpackctbb.dll
	${mw_bin}/libmwbwunpackctbb.dll
	${mw_bin}/libmwcpp*compat.dll
	${mw_bin}/libmwfl.dll
	${mw_bin}/libmwfoundation_usm.dll
	${mw_bin}/libmwMATLAB_res.dll
	${mw_bin}/libmwi*n.dll
	${mw_bin}/libmwimfilter.dll
	${mw_bin}/libmwimlincomb_tbb.dll
	${mw_bin}/libmwimregionalmax.dll
	${mw_bin}/libmwindexingapimethods.dll
	${mw_bin}/libmwipp.dll
	${mw_bin}/libmwippfilter.dll
	${mw_bin}/libmwippreconstruct.dll
	${mw_bin}/libmwmfl_permute.dll
	${mw_bin}/libmwmorphop_binary_tbb.dll
	${mw_bin}/libmwmorphop_packed.dll
	${mw_bin}/libmwnhood.dll
	${mw_bin}/libmwordfilt*.dll
	${mw_bin}/libmwresource_core.dll
	${mw_bin}/libmx.dll
	${mw_bin}/libut.dll
	${mw_bin}/*boost_chrono*.dll
	${mw_bin}/*boost_date_time*.dll
	${mw_bin}/*boost_filesystem*.dll
	${mw_bin}/*boost_log*.dll
	${mw_bin}/*boost_serialization*.dll
	${mw_bin}/*boost_system*.dll
	${mw_bin}/*boost_thread*.dll
	${mw_bin}/*boost_regex*.dll
	${mw_bin}/*boost_signals*.dll
	${mw_bin}/tbb.dll
	${mw_bin}/tbbmalloc.dll
	${mw_bin}/zlib1.dll
)

set(mw_depends "${mw_depends_dll}" CACHE INTERNAL "mw_depends")

install (FILES ${headers}
    DESTINATION ${project_name}/include
)
install (FILES ${mathworks_headers}
    DESTINATION ${project_name}/include/MathWorks
)

install (FILES ${depends_dll}
    DESTINATION ${project_name}/bin
)

install (FILES ${mw_depends_dll}
    DESTINATION ${project_name}/bin
)

install (FILES ${depends_lib}
    DESTINATION ${project_name}/lib
)
