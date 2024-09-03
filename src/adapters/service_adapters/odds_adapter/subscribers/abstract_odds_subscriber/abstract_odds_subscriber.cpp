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
 Version     : 1.0.1 07/05/2024
 Description : Abstract for OpenDDS subscriber
 =================================================================================================================
*/

#include "abstract_odds_subscriber.h"
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include "../../../../../globals/globals.h"

AbstractODDSSubscriber::AbstractODDSSubscriber(const DDS::DomainParticipant_var &participant) : participant_(participant) {
    /* The DDS entities required to subscribe data */
    DDS::ReturnCode_t result;

    DDS::SampleInfoSeq info_seq;

    // Create Topic entity
    /* Create and initialize topic qos value on heap. */
    result = participant_->get_default_topic_qos(t_qos_);
    this->odds_operator_.check_status(result, "get_default_topic_qos() failed");

    /* Fine tune topic qos, i.e. make topic reliable and transient (for late joining subscribers) */
    t_qos_.reliability.kind = DDS::RELIABLE_RELIABILITY_QOS;
    t_qos_.durability.kind = DDS::TRANSIENT_DURABILITY_QOS;

    // Create Subscriber entity
    /* Create on heap and initialize subscriber qos value with the default value. */
    result = participant_->get_default_subscriber_qos(s_qos_);
    this->odds_operator_.check_status(result, "get_default_subscriber_qos() failed");
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
    DDS::Subscriber_var               subscriber;

    DDS::ReturnCode_t result;

    /* Use the changed policy when defining the topic */
    topic = participant_->create_topic(odds_topic, type_name, this->t_qos_, nullptr, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    this->odds_operator_.check_handle(topic, "create_topic() failed");

    /* Fine tune the partition qos policy ito the partition from which the data will be received. */
    /* Create the subscriber. */
    subscriber = participant_->create_subscriber(this->s_qos_, nullptr, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    this->odds_operator_.check_handle(subscriber, "create_subscriber() failed");

    // create DataReader entity
    DDS::DataReaderQos r_qos;
    result = subscriber->get_default_datareader_qos(r_qos);
    this->odds_operator_.check_status(result, "get_default_datareader_qos() failed");

    result = subscriber->get_default_datareader_qos(r_qos);
    this->odds_operator_.check_status(result, "copy_from_topic_qos() failed");

    // r_qos.representation.value.length(1);
    // r_qos.representation.value[0] = DDS::XCDR_DATA_REPRESENTATION;

    reader = subscriber->create_datareader(topic, r_qos, nullptr, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    this->odds_operator_.check_handle(reader, "create_datareader() failed");
}
