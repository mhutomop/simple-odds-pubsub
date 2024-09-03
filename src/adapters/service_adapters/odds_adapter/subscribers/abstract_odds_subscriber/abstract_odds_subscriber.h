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
 Version     : 1.0.1 07/05/2024
 Description : Abstract for OpenDDS subscriber
 =================================================================================================================
*/

#pragma once
#include <string>
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/StaticIncludes.h>
#include <dds/DCPS/WaitSet.h>

#if OPENDDS_DO_MANUAL_STATIC_INCLUDES
#include <dds/DCPS/RTPS/RtpsDiscovery.h>
#include <dds/DCPS/transport/rtps_udp/RtpsUdp.h>
#endif

#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>

#include "../../../../abstract_adapters/abstract_receiver/abstract_receiver.h"
#include "../../odds_operator/odds_operator.h"

class AbstractODDSSubscriber : public AbstractReceiver
{
public:
    explicit AbstractODDSSubscriber(const DDS::DomainParticipant_var &participant);

    void stop() override;
protected:
    DDS::DomainParticipant_var participant_;
    DDS::TopicQos t_qos_;
    DDS::SubscriberQos s_qos_;
    
    bool is_stop_ = false;
    ODDSOperator odds_operator_;

    /**
    * Method set topic
    * @param type_name type name
    * @param odds_topic topic to be set
    * @param reader reader to be set
    */
    void set_topic
    (
        CORBA::String_var &type_name,
        const char* odds_topic,
        DDS::DataReader_var &reader
    ) const;
};
