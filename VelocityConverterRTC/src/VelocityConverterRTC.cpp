// -*- C++ -*-
/*!
 * @file  VelocityConverterRTC.cpp
 * @brief Velocity Converter Componebt
 * @date $Date$
 *
 * $Id$
 */

#include "VelocityConverterRTC.h"

// Module specification
// <rtc-template block="module_spec">
static const char* velocityconverterrtc_spec[] =
  {
    "implementation_id", "VelocityConverterRTC",
    "type_name",         "VelocityConverterRTC",
    "description",       "Velocity Converter Componebt",
    "version",           "1.0.0",
    "vendor",            "rsdlab",
    "category",          "Generi",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.tread", "0.23",

    // Widget
    "conf.__widget__.tread", "text",
    // Constraints

    "conf.__type__.tread", "double",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
VelocityConverterRTC::VelocityConverterRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in),
    m_velocityOut("velocity", m_velocity)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
VelocityConverterRTC::~VelocityConverterRTC()
{
}



RTC::ReturnCode_t VelocityConverterRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("in", m_inIn);
  
  // Set OutPort buffer
  addOutPort("velocity", m_velocityOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("tread", m_tread, "0.23");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t VelocityConverterRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VelocityConverterRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VelocityConverterRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t VelocityConverterRTC::onActivated(RTC::UniqueId ec_id)
{
  m_velocity.data.length(2);
  m_velocity.data[0] = 0.0;
  m_velocity.data[1] = 0.0;

  return RTC::RTC_OK;
}


RTC::ReturnCode_t VelocityConverterRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t VelocityConverterRTC::onExecute(RTC::UniqueId ec_id)
{
  if(m_inIn.isNew()) {
    m_inIn.read();
    
    
    m_velocity.data[0] = m_in.data.vx - m_in.data.va * m_tread / 2;   //left_wheel Speed Control 
    m_velocity.data[1] = m_in.data.vx + m_in.data.va * m_tread / 2;   //right_wheel Speed Control
    m_velocityOut.write();
  }

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t VelocityConverterRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VelocityConverterRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VelocityConverterRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VelocityConverterRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VelocityConverterRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void VelocityConverterRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(velocityconverterrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<VelocityConverterRTC>,
                             RTC::Delete<VelocityConverterRTC>);
  }
  
};


