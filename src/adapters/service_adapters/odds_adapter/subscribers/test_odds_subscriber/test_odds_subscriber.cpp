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
 Name        : test_odds_subscriber.cpp
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.1 07/05/2024
 Description : OpenDDS subscriber for Test topic
 =================================================================================================================
*/

#include "test_odds_subscriber.h"
#include "../../../../../utils/log_util/logger.h"

TestODDSSubscriber::TestODDSSubscriber(const DDS::DomainParticipant_var &participant) : AbstractODDSSubscriber(participant) {
    /* The DDS entities required to subcribe data */
    DDS::DataReader_var               reader;

    /* The Application Own Ship Position Data TypeSupport */
    HelloWorldData::MsgTypeSupport_var type_support;

    DDS::ReturnCode_t result;
    CORBA::String_var type_name;

    // Register the application data type
    type_support = new HelloWorldData::MsgTypeSupportImpl();
    /* Get the IDL type name and use this to register the type. */
    type_name = type_support->get_type_name();
    result = type_support->register_type(participant_, type_name);
    this->odds_operator_.check_status(result, "register_type() failed");

    set_topic(type_name, std::getenv("TEST_SUB_TOPIC"), reader);

    /* Cast reader to 'HelloWorldData' type specific interface. */
    test_reader_ = HelloWorldData::MsgDataReader::_narrow(reader);
    this->odds_operator_.check_handle(test_reader_, "HelloWorldDataReader::_narrow() failed");
}

HelloWorldData::Msg& TestODDSSubscriber::get_updated_data() {
    return this->message_;
}

void TestODDSSubscriber::start() {
    LOG_INFO("ODDS Subscriber", "[Hello World] Ready ...");

    while (!this->is_stop_)
    {
        this->result_ = this->test_reader_->take(this->msg_list_, this->info_seq_, DDS::LENGTH_UNLIMITED,
                                        DDS::ANY_SAMPLE_STATE, DDS::ANY_VIEW_STATE, DDS::ANY_INSTANCE_STATE);
        this->odds_operator_.check_status(this->result_, "msgDataReader::take() failed");

        for (CORBA::ULong i = 0; i < this->msg_list_.length(); i++)
        {
            this->sync_threads();

            LOG_DEBUG("ODDS Subscriber", "[Hello World] Message received \n \
                user_id : " + std::to_string(this->msg_list_[i].user_id) + "\n \
                message : \"" + std::string(this->msg_list_[i].message)
            );
            
            this->message_ = this->msg_list_[i];

            this->notify_observers();
        }
        this->result_ = this->test_reader_->return_loan(this->msg_list_, this->info_seq_);
        this->odds_operator_.check_status(this->result_, "HelloWorldDataReader::return_loan() failed");
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
