#
# @file     CMakeLists.txt
# @brief    Root CMakeFile for ATXMega256a3u and atmel328p in VSCode
# @author   Nico Verduin
# @date     14-4-2023
#

cmake_minimum_required(VERSION 3.20)
set(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

 ______________________________________________________________________________
# delete the build folder. This fix removes the need
# to rebuild the build folder if the target 
# list is empty. By pressing the build button, the build folder
# will be rebuilt. Could be a reason to keep projects_active.cmake limited
# Now you can open any cmakelists.txt in the folder in VSCode, save it and
# the project target list will be rebuilt

message(STATUS "Removing " ${CMAKE_CURRENT_BINARY_DIR})
file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR})

#_______________________________________________________________________________


# get our avr toolchain location
include(file_locations.cmake)

# default CPU to build for
set(TARGET_CPU atxmega256a3u)

# default COM PORT
set (COMPORT usb)

# Make sure parameters are lower case
string(TOLOWER ${TARGET_CPU} TARGET_CPU)
string(TOLOWER ${COMPORT} COMPORT)

# default programmer
set(PROGRAMMER avrispmkII)

#check if we can find the compilers
include(CMakeVerifyCompiler.cmake)

# set our generic compiler and link options
add_compile_options("-Os")
add_compile_options(-fdata-sections)
add_compile_options(-ffunction-sections)
add_compile_options("-fpack-struct")
add_compile_options("-fshort-enums")
add_compile_options("-Wall")
add_compile_options("-funsigned-char")
add_compile_options("-funsigned-bitfields")
add_compile_options("-c")
add_compile_options("-D__DELAY_BACKWARD_COMPATIBLE__")
add_link_options(-Wl,--gc-sections)

# see change 1.6 in generic.cmake
#add_link_options(-Wl,-u,vfprintf)
#add_link_options(-lprintf_flt)

add_link_options(-lm)

# give the project the root folder name
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME PROJECT_NAME)
string(REPLACE " " "_" ProjectId ${PROJECT_NAME})
project(${PROJECT_NAME} NONE)

# add our sub projects
include (projects_active.cmake)
