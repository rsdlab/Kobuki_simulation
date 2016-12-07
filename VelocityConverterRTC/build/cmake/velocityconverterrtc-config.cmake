# VelocityConverterRTC CMake config file
#
# This file sets the following variables:
# VelocityConverterRTC_FOUND - Always TRUE.
# VelocityConverterRTC_INCLUDE_DIRS - Directories containing the VelocityConverterRTC include files.
# VelocityConverterRTC_IDL_DIRS - Directories containing the VelocityConverterRTC IDL files.
# VelocityConverterRTC_LIBRARIES - Libraries needed to use VelocityConverterRTC.
# VelocityConverterRTC_DEFINITIONS - Compiler flags for VelocityConverterRTC.
# VelocityConverterRTC_VERSION - The version of VelocityConverterRTC found.
# VelocityConverterRTC_VERSION_MAJOR - The major version of VelocityConverterRTC found.
# VelocityConverterRTC_VERSION_MINOR - The minor version of VelocityConverterRTC found.
# VelocityConverterRTC_VERSION_REVISION - The revision version of VelocityConverterRTC found.
# VelocityConverterRTC_VERSION_CANDIDATE - The candidate version of VelocityConverterRTC found.

message(STATUS "Found VelocityConverterRTC-1.0.0")
set(VelocityConverterRTC_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(VelocityConverterRTC_INCLUDE_DIRS
#    "/usr/local/include/velocityconverterrtc-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(VelocityConverterRTC_IDL_DIRS
#    "/usr/local/include/velocityconverterrtc-1/idl")
set(VelocityConverterRTC_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(VelocityConverterRTC_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(VelocityConverterRTC_LIBRARIES
        "/usr/local/components/lib/libvelocityconverterrtc.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(VelocityConverterRTC_LIBRARIES
        "/usr/local/components/lib/libvelocityconverterrtc.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(VelocityConverterRTC_DEFINITIONS ${<dependency>_DEFINITIONS})

set(VelocityConverterRTC_VERSION 1.0.0)
set(VelocityConverterRTC_VERSION_MAJOR 1)
set(VelocityConverterRTC_VERSION_MINOR 0)
set(VelocityConverterRTC_VERSION_REVISION 0)
set(VelocityConverterRTC_VERSION_CANDIDATE )

