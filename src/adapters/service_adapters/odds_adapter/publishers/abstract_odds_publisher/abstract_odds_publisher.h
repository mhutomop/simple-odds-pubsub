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
 Name        : abstract_odds_publisher.h
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 09/10/2024
 Description : Abstract for OpenDDS publisher
 =================================================================================================================
*/

#pragma once
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/StaticIncludes.h>
#include <dds/DCPS/WaitSet.h>
#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>
#include "../../odds_operator/odds_operator.h"

class AbstractODDSPublisher
{
public:
    explicit AbstractODDSPublisher(const DDS::DomainParticipant_var &participant);
    virtual ~AbstractODDSPublisher() = default;

    /**
    * Method to get Domain Participant
    * @return Domain Participant as pointer DDS::DomainParticipant_var
    */
    DDS::DomainParticipant_var* get_participant_();
    /**
    * Method to get ODDS Operator
    * @return ODDS Operator as pointer ODDSOperator
    */
    ODDSOperator* get_odds_operator_();

    /**
    * Interface method to publish message of the topic
    */
    virtual void publish_message() = 0;
protected:
    /**
    * Method set topic on ODDS
    * @param type_name type name as CORBA::String_var
    * @param odds_topic topic to be set as pointer char
    * @param writer writer to be set as DDS::DataWriter_var
    */
    void set_topic
    (
        CORBA::String_var &type_name,
        const char* odds_topic,
        DDS::DataWriter_var &writer
    );
private:
    DDS::DomainParticipant_var participant_;
    DDS::Publisher_var publisher_;
    DDS::TopicQos t_qos_;
    DDS::PublisherQos p_qos_;
    DDS::DataWriterQos w_qos_;

    ODDSOperator odds_operator_;
};
