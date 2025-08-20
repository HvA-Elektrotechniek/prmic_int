#
# @file     file_locations.cmake
# @brief    This cmake file contains all the roots to our compiler and avrdude
# @author   Nico Verduin
# version   1.0
#           1.1 add objdump to the program list
#           1.2 added Linux 
#           1.3 cleaned up file. No more changes needed with standard procedure
#           1.4 Get absolute paths under windows increasing portability
# @date     20-8-2025
#

# root folder of our tool. is automatically determined
if(DEFINED ENV{DEV_ROOT})
    set(DEV_ROOT $ENV{DEV_ROOT})
    message(STATUS "DEV_ROOT is defined as ${DEV_ROOT}")
else()
    cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH DEV_ROOT)
    message(STATUS "DEV_ROOT was not defined, and is now set as ${DEV_ROOT}")
endif()

# compiler path. This should be the only one to modify unless
# AVR_DUDE is somewhere else

# If we use standard installation no change in this file is needed
if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
    # Get the abdolute path to these folders usin CMAKE
    get_filename_component(TOOLCHAIN_PATH  "../avr8-gnu-toolchain-win32_x86_64/bin" ABSOLUTE )
    get_filename_component(AVRDUDE_PATH  "../avrdude-v7.1-windows-x64/" ABSOLUTE )
else()
    if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Darwin")
        # mac osx avr-gcc compiler
        set(TOOLCHAIN_PATH "${DEV_ROOT}/avr8-gnu-toolchain-darwin_x86_64/bin")
        set(AVRDUDE_PATH "")
    else()
        # linux avr-gcc compiler
        set(TOOLCHAIN_PATH "${DEV_ROOT}/avr8-gnu-toolchain-linux_x86_64/bin")
        set(AVRDUDE_PATH "")
    endif()
endif()

# do we need file extensions?
if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Darwin" OR ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
    # OSX no file extension
    set(FILE_EXTENSION "")
else()
    # Windows with file extension
    set(FILE_EXTENSION ".exe")
endif()

# our compilers
set (CMAKE_C_COMPILER   ${TOOLCHAIN_PATH}/avr-gcc${FILE_EXTENSION} )
set (CMAKE_CXX_COMPILER ${TOOLCHAIN_PATH}/avr-g++${FILE_EXTENSION})
set (AVR_SIZE           ${TOOLCHAIN_PATH}/avr-size${FILE_EXTENSION} )
set (AVR_OBJCOPY        ${TOOLCHAIN_PATH}/avr-objcopy${FILE_EXTENSION} )
set (AVR_OBJDUMP        ${TOOLCHAIN_PATH}/avr-objdump${FILE_EXTENSION} )
set (AVR_READELF        ${TOOLCHAIN_PATH}/avr-readelf${FILE_EXTENSION} )
set (AVR_DUDE           ${AVRDUDE_PATH}avrdude${FILE_EXTENSION})

# set path for the compiler
set(AVR_PATH ${TOOLCHAIN_PATH}../)

