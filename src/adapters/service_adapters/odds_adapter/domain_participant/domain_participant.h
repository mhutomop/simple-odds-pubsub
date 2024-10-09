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
 Name        : domain_participant.h
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 09/10/2024
 Description : Domain Participant of OpenDDS
 =================================================================================================================
*/

#pragma once
#include <mutex>
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/StaticIncludes.h>
#include <dds/DCPS/WaitSet.h>
#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>
#include "../odds_operator/odds_operator.h"

class ODDSDomainParticipant
{
public:
    ODDSDomainParticipant();

    /**
    * Method to get Domain Participant instance
    * @return Domain Participant as std::shared_ptr<ODDSDomainParticipant>
    */
    static std::shared_ptr<ODDSDomainParticipant> get_instance();
    /**
    * Method to get Domain Participant
    * @return Domain Participant as DDS::DomainParticipant_var
    */
    DDS::DomainParticipant_var& get_participant_();
private:
    static inline std::shared_ptr<ODDSDomainParticipant> domain_participant_instance_ = nullptr;
    static inline std::mutex domain_participant_mutex_;  

    DDS::DomainParticipant_var participant_;

    ODDSOperator odds_operator_;
};
