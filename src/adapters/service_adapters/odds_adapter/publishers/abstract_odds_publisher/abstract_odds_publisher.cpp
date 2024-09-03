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
 Name        : abstract_odds_publisher.cpp
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 21/05/2024
 Description : Abstract for OpenDDS publisher
 =================================================================================================================
*/

#include "abstract_odds_publisher.h"
#include <iostream>
#include <string>
#include "../../../../../utils/log_util/logger.h"

AbstractODDSPublisher::AbstractODDSPublisher(const DDS::DomainParticipant_var &participant) : participant_(participant)
{
    /* The DDS entities required to publish data */
    DDS::ReturnCode_t result;

    // Create Topic entity
    /* Create and initialize topic qos value on heap. */
    result = participant_->get_default_topic_qos(t_qos_);
    this->odds_operator_.check_status(result, "get_default_topic_qos() failed");

    /* Fine tune topic qos, i.e. make topic reliable and transient (for late joining subscribers) */
    t_qos_.reliability.kind = DDS::RELIABLE_RELIABILITY_QOS;
    t_qos_.durability.kind = DDS::TRANSIENT_DURABILITY_QOS;

    // Create Publisher entity
    /* Create on heap and initialize publisher qos value with the default value. */
    result = participant_->get_default_publisher_qos(p_qos_);
    this->odds_operator_.check_status(result, "get_default_publisher_qos() failed");
}

void AbstractODDSPublisher::set_topic(
    CORBA::String_var &type_name,
    const char* odds_topic,
    DDS::DataWriter_var &writer
)
{
    /* The DDS entities required to publish data */
    DDS::Topic_var                    topic;
    DDS::Publisher_var                publisher;

    DDS::ReturnCode_t result;

    /* Use the changed policy when defining the topic */
    topic = participant_->create_topic(odds_topic, type_name, this->t_qos_, nullptr, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    this->odds_operator_.check_handle(topic, "create_topic() failed");

    // Create Publisher entity
    /* Create on heap and initialize publisher qos value with the default value. */
    result = participant_->get_default_publisher_qos(this->p_qos_);
    this->odds_operator_.check_status(result, "get_default_publisher_qos() failed");

    /* Fine tune the partition qos policy ito the partition in which the data will be published. */
    /* Create the publisher. */
    publisher = participant_->create_publisher(this->p_qos_, nullptr, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    this->odds_operator_.check_handle(publisher, "create_publisher() failed");

    // create DataWriter entity
    DDS::DataWriterQos w_qos;
    result = publisher->get_default_datawriter_qos(w_qos);
    this->odds_operator_.check_status(result, "get_default_datawriter_qos() failed");

    result = publisher->copy_from_topic_qos(w_qos, this->t_qos_);
    this->odds_operator_.check_status(result, "copy_from_topic_qos() failed");

    /* Set the autodispose_unregistered_instances qos policy to false.
     * If autodispose_unregistered_instances is set to true (default value),
     * you will have to start the subscriber before the publisher
    */
    w_qos.writer_data_lifecycle.autodispose_unregistered_instances = false;
    // w_qos.representation.value.length(1);
    // w_qos.representation.value[0] = DDS::XCDR_DATA_REPRESENTATION;

    writer = publisher->create_datawriter(topic, w_qos, nullptr, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    this->odds_operator_.check_handle(writer, "create_datawriter() failed");
}
