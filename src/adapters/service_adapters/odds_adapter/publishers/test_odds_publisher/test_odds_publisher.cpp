/*
 * Copyright PT LEN INNOVATION TECHNOLOGY
 *
 * THIS SOFTWARE SOURCE CODE AND ANY EXECUTABLE DERIVED THEREOF ARE PROPRIETARY
 * TO PT LEN INNOVATION TECHNOLOGY, AS APPLICABLE, AND SHALL NOT BE USED IN ANY WAY
 * OTHER THAN BEFOREHAND AGREED ON BY PT LEN INNOVATION TECHNOLOGY, NOR BE REPRODUCED
 * OR DISCLOSED TO THIRD PARTIES WITHOUT PRIOR WRITTEN AUTHORIZATION BY
 * PT LEN INNOVATION TECHNOLOGY, AS APPLICABLE.
*/

/*
 =================================================================================================================
 Name        : test_odds_publisher.cpp
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.1 07/05/2024
 Description : OpenDDS publisher for Test topic
 =================================================================================================================
*/

#include "test_odds_publisher.h"
#include <iostream>
#include <string>
#include "../../../../../utils/log_util/logger.h"

TestODDSPublisher::TestODDSPublisher(const DDS::DomainParticipant_var &participant) : AbstractODDSPublisher(participant)
{
    /* The DDS entities required to publish data */
    DDS::DataWriter_var               writer;

    /* The Application Test Data type_support */
    HelloWorldData::MsgTypeSupport_var type_support;

    DDS::ReturnCode_t result;
    CORBA::String_var type_name;

    HelloWorldData::MsgSeq msg_list;
   
    // Register the application data type
    type_support = new HelloWorldData::MsgTypeSupportImpl();
    /* Get the IDL type name and use this to register the type. */
    type_name = type_support->get_type_name();
    result = type_support->register_type(participant_, type_name);
    this->odds_operator_.check_status(result, "register_type() failed");

    set_topic(type_name, std::getenv("TEST_PUB_TOPIC"), writer);

    /* Cast writer to 'HelloWorldData' type specific interface. */
    test_writer_ = HelloWorldData::MsgDataWriter::_narrow(writer);
    this->odds_operator_.check_handle(test_writer_, "HelloWorldDataWriter::_narrow() failed");

    LOG_INFO("ODDS Publisher", "[Hello World] Ready ...");
}

void TestODDSPublisher::set_test_msg_(const HelloWorldData::Msg &test_msg) {
    this->test_msg_ = test_msg;
}

void TestODDSPublisher::publish_message() {
    LOG_DEBUG("ODDS Publisher", "[Hello World] Writing a message containing : \n \
        user_id : " + std::to_string(this->test_msg_.user_id) + "\n \
        message : \"" + std::string(this->test_msg_.message)
    );

    DDS::ReturnCode_t result;
    result = this->test_writer_->write(this->test_msg_, DDS::HANDLE_NIL);
    this->odds_operator_.check_status(result, "write() failed");
}
