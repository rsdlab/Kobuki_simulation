// -*- C++ -*-
/*!
 * @file  PoseConverterRTC.cpp
 * @brief Pose Converter RTC
 * @date $Date$
 *
 * $Id$
 */

#include "PoseConverterRTC.h"

// Module specification
// <rtc-template block="module_spec">
static const char* poseconverterrtc_spec[] =
  {
    "implementation_id", "PoseConverterRTC",
    "type_name",         "PoseConverterRTC",
    "description",       "Pose Converter RTC",
    "version",           "1.0.0",
    "vendor",            "rsdlab",
    "category",          "Generi",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
PoseConverterRTC::PoseConverterRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_poseIn("pose", m_pose),
    m_odometryOut("odometry", m_odometry)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
PoseConverterRTC::~PoseConverterRTC()
{
}



RTC::ReturnCode_t PoseConverterRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("pose", m_poseIn);
  
  // Set OutPort buffer
  addOutPort("odometry", m_odometryOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t PoseConverterRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PoseConverterRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PoseConverterRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t PoseConverterRTC::onActivated(RTC::UniqueId ec_id)
{
  m_pose.data.position.x = 0;
  m_pose.data.position.x = 0;
  m_pose.data.orientation.y = 0;

  return RTC::RTC_OK;
}


RTC::ReturnCode_t PoseConverterRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t PoseConverterRTC::onExecute(RTC::UniqueId ec_id)
{
  if(m_poseIn.isNew())
    {
      m_poseIn.read();
      
      m_odometry.data.position.x = m_pose.data.position.x;
      m_odometry.data.position.y = m_pose.data.position.y;
      m_odometry.data.heading = m_pose.data.orientation.y;
      
      m_odometryOut.write();
      
      /* std::cout << m_odometry.data.position.x << ',' << m_odometry.data.position.y << ',' << m_odometry.data.heading << std::endl;*/
    }
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t PoseConverterRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PoseConverterRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PoseConverterRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PoseConverterRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PoseConverterRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void PoseConverterRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(poseconverterrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<PoseConverterRTC>,
                             RTC::Delete<PoseConverterRTC>);
  }
  
};


