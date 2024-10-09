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
 Name        : abstract_odds_subscriber.h
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 09/10/2024
 Description : Abstract for OpenDDS subscriber
 =================================================================================================================
*/

#pragma once
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/StaticIncludes.h>
#include <dds/DCPS/WaitSet.h>
#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>
#include "../../../../abstract_adapters/interface_receiver/interface_receiver.h"
#include "../../odds_operator/odds_operator.h"

class AbstractODDSSubscriber : public InterfaceReceiver
{
public:
    explicit AbstractODDSSubscriber(const DDS::DomainParticipant_var &participant);

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
    * Method to get stop subscriber status
    * @return stop subscriber status as boolean
    */
    bool* get_is_stop_();    

    void stop() override;
protected:
    /**
    * Method to set topic on ODDS
    * @param type_name type name as CORBA::String_var
    * @param odds_topic topic to be set as pointer char
    * @param reader reader to be set as DDS::DataReader_var
    */
    void set_topic
    (
        CORBA::String_var &type_name,
        const char* odds_topic,
        DDS::DataReader_var &reader
    ) const;
private:
    DDS::DomainParticipant_var participant_;
    DDS::Subscriber_var subscriber_;
    DDS::TopicQos t_qos_;
    DDS::SubscriberQos s_qos_;
    DDS::DataReaderQos r_qos_;
    
    bool is_stop_ = false;
    ODDSOperator odds_operator_;
};
