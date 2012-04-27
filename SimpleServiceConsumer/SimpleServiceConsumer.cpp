// -*- C++ -*-
/*!
 * @file  SimpleServiceConsumer.cpp
 * @brief SimpleServiceConsumer
 * @date $Date$
 *
 * $Id$
 */

#include "SimpleServiceConsumer.h"

// Module specification
// <rtc-template block="module_spec">
static const char* simpleserviceconsumer_spec[] =
  {
    "implementation_id", "SimpleServiceConsumer",
    "type_name",         "SimpleServiceConsumer",
    "description",       "SimpleServiceConsumer",
    "version",           "1.0.0",
    "vendor",            "ysuga_net",
    "category",          "Tes",
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
SimpleServiceConsumer::SimpleServiceConsumer(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_simpleServicePort("simpleService")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SimpleServiceConsumer::~SimpleServiceConsumer()
{
}



RTC::ReturnCode_t SimpleServiceConsumer::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  m_simpleServicePort.registerConsumer("SimpleService", "ysuga::SimpleService", m_simpleServiceConsumer);
  
  // Set CORBA Service Ports
  addPort(m_simpleServicePort);
  
  // </rtc-template>

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SimpleServiceConsumer::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceConsumer::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceConsumer::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceConsumer::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceConsumer::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t SimpleServiceConsumer::onExecute(RTC::UniqueId ec_id)
{
	std::cout << "Input Command (q:reset, r:read, w:write)" << std::endl;

	char c;
	std::cin >> c;

	CORBA::Long data;

	switch(c) {
		case 'r':
			m_simpleServiceConsumer->read(data);
			std::cout << "read(): Data is " << (long)data << std::endl;
			break;
		case 'w':
			data = (long)rand();
			std::cout << "write(" << (long)data << ")" << std::endl;
			m_simpleServiceConsumer->write(data);
			break;
		case'q':
			data = m_simpleServiceConsumer->reset();
			std::cout << "reset(): return value is " << data << std::endl;
			break;
		default:
			break;
	}

	return RTC::RTC_OK;
}


/*
RTC::ReturnCode_t SimpleServiceConsumer::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceConsumer::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceConsumer::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceConsumer::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimpleServiceConsumer::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SimpleServiceConsumerInit(RTC::Manager* manager)
  {
    coil::Properties profile(simpleserviceconsumer_spec);
    manager->registerFactory(profile,
                             RTC::Create<SimpleServiceConsumer>,
                             RTC::Delete<SimpleServiceConsumer>);
  }
  
};


