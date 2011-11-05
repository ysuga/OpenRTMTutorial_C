// -*- C++ -*-
/*!
 * @file  ConfigurationTest.cpp
 * @brief Configuration Test
 * @date $Date$
 *
 * $Id$
 */

#include "ConfigurationTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* configurationtest_spec[] =
  {
    "implementation_id", "ConfigurationTest",
    "type_name",         "ConfigurationTest",
    "description",       "Configuration Test",
    "version",           "1.0.0",
    "vendor",            "ysugaet",
    "category",          "Example",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.i_debug", "0",
    "conf.default.f_debug", "0.0",
    "conf.default.s_debug", "debug",
    // Widget
    "conf.__widget__.i_debug", "text",
    "conf.__widget__.f_debug", "text",
    "conf.__widget__.s_debug", "text",
    // Constraints
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ConfigurationTest::ConfigurationTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ConfigurationTest::~ConfigurationTest()
{
}



RTC::ReturnCode_t ConfigurationTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("i_debug", m_i_debug, "0");
  bindParameter("f_debug", m_f_debug, "0.0");
  bindParameter("s_debug", m_s_debug, "debug");
  
  // </rtc-template>
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ConfigurationTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConfigurationTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConfigurationTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConfigurationTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConfigurationTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ConfigurationTest::onExecute(RTC::UniqueId ec_id)
{
	std::cout << "i_debug = " << this->m_i_debug << std::endl;
	std::cout << "f_debug = " << this->m_f_debug << std::endl;
	std::cout << "s_debug = " << this->m_s_debug << std::endl;
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ConfigurationTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConfigurationTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConfigurationTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConfigurationTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConfigurationTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ConfigurationTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(configurationtest_spec);
    manager->registerFactory(profile,
                             RTC::Create<ConfigurationTest>,
                             RTC::Delete<ConfigurationTest>);
  }
  
};


