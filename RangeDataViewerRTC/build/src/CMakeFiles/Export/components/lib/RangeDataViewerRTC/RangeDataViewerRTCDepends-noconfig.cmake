#----------------------------------------------------------------
# Generated CMake target import file for configuration "".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "RangeDataViewerRTC" for configuration ""
set_property(TARGET RangeDataViewerRTC APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(RangeDataViewerRTC PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "pthread;omniORB4;omnithread;omniDynamic4;RTC;coil;opencv_videostab;opencv_video;opencv_ts;opencv_superres;opencv_stitching;opencv_photo;opencv_ocl;opencv_objdetect;opencv_ml;opencv_legacy;opencv_imgproc;opencv_highgui;opencv_gpu;opencv_flann;opencv_features2d;opencv_core;opencv_contrib;opencv_calib3d"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/lib/RangeDataViewerRTC.so"
  IMPORTED_SONAME_NOCONFIG "RangeDataViewerRTC.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS RangeDataViewerRTC )
list(APPEND _IMPORT_CHECK_FILES_FOR_RangeDataViewerRTC "${_IMPORT_PREFIX}/components/lib/RangeDataViewerRTC.so" )

# Import target "RangeDataViewerRTCComp" for configuration ""
set_property(TARGET RangeDataViewerRTCComp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(RangeDataViewerRTCComp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/bin/RangeDataViewerRTCComp"
  )

list(APPEND _IMPORT_CHECK_TARGETS RangeDataViewerRTCComp )
list(APPEND _IMPORT_CHECK_FILES_FOR_RangeDataViewerRTCComp "${_IMPORT_PREFIX}/components/bin/RangeDataViewerRTCComp" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
