// -*- C++ -*-
/*!
 * @file  RangeDataViewerRTC.cpp
 * @brief To Viewer RangeData Component
 * @date $Date$
 *
 * $Id$
 */

#include "RangeDataViewerRTC.h"

// Module specification
// <rtc-template block="module_spec">
static const char* rangedataviewerrtc_spec[] =
  {
    "implementation_id", "RangeDataViewerRTC",
    "type_name",         "RangeDataViewerRTC",
    "description",       "To Viewer RangeData Component",
    "version",           "1.0.0",
    "vendor",            "rsdlab",
    "category",          "SEE",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.maxRange", "2.0",

    // Widget
    "conf.__widget__.maxRange", "text",
    // Constraints

    "conf.__type__.maxRange", "double",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
RangeDataViewerRTC::RangeDataViewerRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_rangeIn("range", m_range),
    // </rtc-template>
    m_cvImage(NULL),
    dummy(0)
{
}

/*!
 * @brief destructor
 */
RangeDataViewerRTC::~RangeDataViewerRTC()
{
}



RTC::ReturnCode_t RangeDataViewerRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("range", m_rangeIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("maxRange", m_maxRange, "2.0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RangeDataViewerRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RangeDataViewerRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RangeDataViewerRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

#define WSIZE 640
RTC::ReturnCode_t RangeDataViewerRTC::onActivated(RTC::UniqueId ec_id)
{
  std::cout << m_profile.instance_name<< ": onActivated(" << ec_id << ")" << std::endl;
  m_cvImage = cvCreateImage(cvSize(WSIZE, WSIZE), IPL_DEPTH_8U, 3);
  cvNamedWindow("Range",CV_WINDOW_AUTOSIZE);
  return RTC::RTC_OK;
}

RTC::ReturnCode_t RangeDataViewerRTC::onDeactivated(RTC::UniqueId ec_id)
{
  std::cout << m_profile.instance_name<< ": onDeactivated(" << ec_id << ")" << std::endl;
  if (m_cvImage) 
    {
      cvReleaseImage(&m_cvImage);
      m_cvImage = NULL;
    }
  cvDestroyWindow("Range");
  
  return RTC::RTC_OK;
}



RTC::ReturnCode_t RangeDataViewerRTC::onExecute(RTC::UniqueId ec_id)
{
  //std::cout << m_profile.instance_name<< ": onExecute(" << ec_id << ")"  << std::endl;
  
  if (1/*m_rangeIn.isNew()*/){
    do {
      m_rangeIn.read();
    }while(m_rangeIn.isNew());
    
    cvSetZero(m_cvImage);
    
    CvPoint center = cvPoint(WSIZE/2,WSIZE/2);
    CvScalar green = cvScalar(0,255,0);
    double th,d,x,y;
#if 0
    std::cout << "minAngle:" << m_range.config.minAngle << std::endl;
    std::cout << "maxAngle:" << m_range.config.maxAngle << std::endl;
    std::cout << "angularRes:" << m_range.config.angularRes << std::endl;
    std::cout << "minRange:" << m_range.config.minRange << std::endl;
    std::cout << "maxRange:" << m_range.config.maxRange << std::endl;
    std::cout << "rangeRes:" << m_range.config.rangeRes << std::endl;
    std::cout << "frequency:" << m_range.config.frequency << std::endl;
    std::cout << "ndata = " << m_range.ranges.length() << std::endl;
#endif
    for (unsigned int i=0; i<m_range.ranges.length(); i++){
      d = m_range.ranges[i];
      if (isinf(d)) continue;
      th = m_range.config.minAngle + m_range.config.angularRes*i;
      x = -d*sin(th)/m_maxRange*WSIZE/2 + WSIZE/2;
      y = -d*cos(th)/m_maxRange*WSIZE/2 + WSIZE/2;
      cvLine(m_cvImage, center, cvPoint(x, y), green, 1, 8, 0);
    }
    
    cvShowImage("Range",m_cvImage);
    cvWaitKey(10);
  }
  
  return RTC::RTC_OK;
}
  
/*
RTC::ReturnCode_t RangeDataViewerRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RangeDataViewerRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RangeDataViewerRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RangeDataViewerRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RangeDataViewerRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void RangeDataViewerRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(rangedataviewerrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<RangeDataViewerRTC>,
                             RTC::Delete<RangeDataViewerRTC>);
  }
  
};


