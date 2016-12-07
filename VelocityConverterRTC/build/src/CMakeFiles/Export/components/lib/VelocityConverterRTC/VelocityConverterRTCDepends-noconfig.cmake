#----------------------------------------------------------------
# Generated CMake target import file for configuration "".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "VelocityConverterRTC" for configuration ""
set_property(TARGET VelocityConverterRTC APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(VelocityConverterRTC PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "pthread;omniORB4;omnithread;omniDynamic4;RTC;coil"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/lib/VelocityConverterRTC.so"
  IMPORTED_SONAME_NOCONFIG "VelocityConverterRTC.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS VelocityConverterRTC )
list(APPEND _IMPORT_CHECK_FILES_FOR_VelocityConverterRTC "${_IMPORT_PREFIX}/components/lib/VelocityConverterRTC.so" )

# Import target "VelocityConverterRTCComp" for configuration ""
set_property(TARGET VelocityConverterRTCComp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(VelocityConverterRTCComp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/bin/VelocityConverterRTCComp"
  )

list(APPEND _IMPORT_CHECK_TARGETS VelocityConverterRTCComp )
list(APPEND _IMPORT_CHECK_FILES_FOR_VelocityConverterRTCComp "${_IMPORT_PREFIX}/components/bin/VelocityConverterRTCComp" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
