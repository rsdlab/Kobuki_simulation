# RangeDataViewerRTC CMake config file
#
# This file sets the following variables:
# RangeDataViewerRTC_FOUND - Always TRUE.
# RangeDataViewerRTC_INCLUDE_DIRS - Directories containing the RangeDataViewerRTC include files.
# RangeDataViewerRTC_IDL_DIRS - Directories containing the RangeDataViewerRTC IDL files.
# RangeDataViewerRTC_LIBRARIES - Libraries needed to use RangeDataViewerRTC.
# RangeDataViewerRTC_DEFINITIONS - Compiler flags for RangeDataViewerRTC.
# RangeDataViewerRTC_VERSION - The version of RangeDataViewerRTC found.
# RangeDataViewerRTC_VERSION_MAJOR - The major version of RangeDataViewerRTC found.
# RangeDataViewerRTC_VERSION_MINOR - The minor version of RangeDataViewerRTC found.
# RangeDataViewerRTC_VERSION_REVISION - The revision version of RangeDataViewerRTC found.
# RangeDataViewerRTC_VERSION_CANDIDATE - The candidate version of RangeDataViewerRTC found.

message(STATUS "Found RangeDataViewerRTC-1.0.0")
set(RangeDataViewerRTC_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(RangeDataViewerRTC_INCLUDE_DIRS
#    "/usr/local/include/rangedataviewerrtc-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(RangeDataViewerRTC_IDL_DIRS
#    "/usr/local/include/rangedataviewerrtc-1/idl")
set(RangeDataViewerRTC_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(RangeDataViewerRTC_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(RangeDataViewerRTC_LIBRARIES
        "/usr/local/components/lib/librangedataviewerrtc.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(RangeDataViewerRTC_LIBRARIES
        "/usr/local/components/lib/librangedataviewerrtc.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(RangeDataViewerRTC_DEFINITIONS ${<dependency>_DEFINITIONS})

set(RangeDataViewerRTC_VERSION 1.0.0)
set(RangeDataViewerRTC_VERSION_MAJOR 1)
set(RangeDataViewerRTC_VERSION_MINOR 0)
set(RangeDataViewerRTC_VERSION_REVISION 0)
set(RangeDataViewerRTC_VERSION_CANDIDATE )

