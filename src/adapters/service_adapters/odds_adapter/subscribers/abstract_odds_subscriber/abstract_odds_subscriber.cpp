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
 Name        : abstract_odds_subscriber.cpp
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 09/10/2024
 Description : Abstract for OpenDDS subscriber
 =================================================================================================================
*/

#include "abstract_odds_subscriber.h"
#include "../../odds_operator/odds_operator.inl"

template void ODDSOperator::check_handle<DDS::Topic_var>(DDS::Topic_var* handle, std::string_view info) const;
template void ODDSOperator::check_handle<DDS::Publisher_var>(DDS::Publisher_var* handle, std::string_view info) const;
template void ODDSOperator::check_handle<DDS::DataWriter_var>(DDS::DataWriter_var* handle, std::string_view info) const;

AbstractODDSSubscriber::AbstractODDSSubscriber(const DDS::DomainParticipant_var &participant) 
    : participant_(participant) 
{
    // The DDS entities required to subscribe data
    DDS::ReturnCode_t result;

    DDS::SampleInfoSeq info_seq;

    /* Create topic QOS
     * Create and initialize topic QOS value on heap
    */
    result = participant_->get_default_topic_qos(t_qos_);
    odds_operator_.check_status(result, "get_default_topic_qos() failed");

    // Fine tune topic QOS, i.e. make topic reliable and transient (for late joining subscribers)
    t_qos_.reliability.kind = DDS::RELIABLE_RELIABILITY_QOS;
    t_qos_.durability.kind = DDS::TRANSIENT_DURABILITY_QOS;

    /* Create subscriber entity
     * Create on heap and initialize subscriber QOS value with the default value
    */
    result = participant_->get_default_subscriber_qos(s_qos_);
    odds_operator_.check_status(result, "get_default_subscriber_qos() failed");

    /* Fine tune the partition qos policy ito the partition from which the data will be received. */
    /* Create the subscriber. */
    subscriber_ = participant_->create_subscriber(this->s_qos_, nullptr, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    this->odds_operator_.check_handle(&subscriber_, "create_subscriber() failed");

    // create DataReader entity
    result = subscriber_->get_default_datareader_qos(r_qos_);
    this->odds_operator_.check_status(result, "get_default_datareader_qos() failed");

    result = subscriber_->copy_from_topic_qos(r_qos_, t_qos_);
    this->odds_operator_.check_status(result, "copy_from_topic_qos() failed");
}

DDS::DomainParticipant_var* AbstractODDSSubscriber::get_participant_() {
    return &this->participant_;
}

ODDSOperator* AbstractODDSSubscriber::get_odds_operator_() {
    return &this->odds_operator_;
}

bool* AbstractODDSSubscriber::get_is_stop_() {
    return &this->is_stop_;
}

void AbstractODDSSubscriber::stop() {
    this->is_stop_ = true;
}

void AbstractODDSSubscriber::set_topic
(
    CORBA::String_var &type_name,
    const char* odds_topic,
    DDS::DataReader_var &reader
) const
{
    /* The DDS entities required to subcribe data */
    DDS::Topic_var                    topic;

    /* Use the changed policy when defining the topic */
    topic = participant_->create_topic(odds_topic, type_name, this->t_qos_, nullptr, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    this->odds_operator_.check_handle(&topic, "create_topic() failed");

    reader = subscriber_->create_datareader(topic, r_qos_, nullptr, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    this->odds_operator_.check_handle(&reader, "create_datareader() failed");
}
