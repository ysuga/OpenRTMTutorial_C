// -*- C++ -*-
/*!
 * @file  PeriodicConsoleOut.cpp
 * @brief Periodically Console Out Component
 * @date $Date$
 *
 * $Id$
 */

#include "PeriodicConsoleOut.h"

// Module specification
// <rtc-template block="module_spec">
static const char* periodicconsoleout_spec[] =
  {
    "implementation_id", "PeriodicConsoleOut",
    "type_name",         "PeriodicConsoleOut",
    "description",       "Periodically Console Out Component",
    "version",           "1.0.0",
    "vendor",            "ysuganet",
    "category",          "Example",
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
PeriodicConsoleOut::PeriodicConsoleOut(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
PeriodicConsoleOut::~PeriodicConsoleOut()
{
}



RTC::ReturnCode_t PeriodicConsoleOut::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t PeriodicConsoleOut::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PeriodicConsoleOut::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PeriodicConsoleOut::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PeriodicConsoleOut::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PeriodicConsoleOut::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t PeriodicConsoleOut::onExecute(RTC::UniqueId ec_id)
{
	std::cout << "Hello RTC!" << std::endl;
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t PeriodicConsoleOut::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PeriodicConsoleOut::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PeriodicConsoleOut::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PeriodicConsoleOut::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PeriodicConsoleOut::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void PeriodicConsoleOutInit(RTC::Manager* manager)
  {
    coil::Properties profile(periodicconsoleout_spec);
    manager->registerFactory(profile,
                             RTC::Create<PeriodicConsoleOut>,
                             RTC::Delete<PeriodicConsoleOut>);
  }
  
};


