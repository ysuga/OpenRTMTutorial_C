// -*- C++ -*-
/*!
 * @file  SimpleServiceProvider.cpp
 * @brief Simple Service Provider
 * @date $Date$
 *
 * $Id$
 */

#include "SimpleServiceProvider.h"

// Module specification
// <rtc-template block="module_spec">
static const char* simpleserviceprovider_spec[] =
  {
    "implementation_id", "SimpleServiceProvider",
    "type_name",         "SimpleServiceProvider",
    "description",       "Simple Service Provider",
    "version",           "1.0.0",
    "vendor",            "ysuga",
    "category",          "Test",
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
SimpleServiceProvider::SimpleServiceProvider(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_simpleServicePort("simpleService")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SimpleServiceProvider::~SimpleServiceProvider()
{
}



RTC::ReturnCode_t SimpleServiceProvider::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  m_simpleServicePort.registerProvider("SimpleService", "ysuga::SimpleService", m_simpleServiceProvider);
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  addPort(m_simpleServicePort);
  
  // </rtc-template>

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SimpleServiceProvider::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceProvider::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceProvider::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceProvider::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceProvider::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t SimpleServiceProvider::onExecute(RTC::UniqueId ec_id)
{
	std::cout << "data is " << m_simpleServiceProvider.getData() << std::endl;
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SimpleServiceProvider::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceProvider::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceProvider::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceProvider::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceProvider::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SimpleServiceProviderInit(RTC::Manager* manager)
  {
    coil::Properties profile(simpleserviceprovider_spec);
    manager->registerFactory(profile,
                             RTC::Create<SimpleServiceProvider>,
                             RTC::Delete<SimpleServiceProvider>);
  }
  
};


