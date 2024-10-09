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
 Name        : domain_participant.cpp
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 09/10/2024
 Description : Domain Participant of OpenDDS
 =================================================================================================================
*/

#include "domain_participant.h"
#include <string>
#include "../odds_operator/odds_operator.inl"
#include "../../../../globals/constants.h"

template void ODDSOperator::check_handle<DDS::DomainParticipantFactory_var>
    (DDS::DomainParticipantFactory_var* handle, std::string_view info) const;
template void ODDSOperator::check_handle<DDS::DomainParticipant_var>
    (DDS::DomainParticipant_var* handle, std::string_view info) const;

ODDSDomainParticipant::ODDSDomainParticipant() 
{
    if (!domain_participant_instance_) {
        // The DDS entities required to publish data
        DDS::DomainParticipantFactory_var factory;
        DDS::DomainId_t domain;

        // Get the DDS DomainParticipantFactory
        int32_t argc = 5;
        char* arg1 = strdup(("./" + static_cast<std::string>(kServiceName)).c_str());
        char* arg2 = strdup("-DCPSInfoRepo");
        char* arg3 = strdup(std::getenv("IOR_PATH"));
        char* arg4 = strdup("-DCPSConfigFile");
        char* arg5 = strdup(std::getenv("RTPS_PATH"));
        std::array<ACE_TCHAR*, 6> args = { arg1, arg2, arg3, arg4, arg5, NULL };
        factory = TheParticipantFactoryWithArgs(argc, args.data());
        odds_operator_.check_handle(&factory, "get_instance() failed");

        // Create a Domain Participant entity for the default domain (domain id = 0)
        domain = 0;
        participant_ =
            factory->create_participant(domain, PARTICIPANT_QOS_DEFAULT, nullptr, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
        odds_operator_.check_handle(&participant_, "create_participant() failed");
    }
}

std::shared_ptr<ODDSDomainParticipant> ODDSDomainParticipant::get_instance() {
    if (!domain_participant_instance_)
        domain_participant_instance_ = std::make_shared<ODDSDomainParticipant>();

    return domain_participant_instance_;
}

DDS::DomainParticipant_var& ODDSDomainParticipant::get_participant_() {
    return this->participant_;
}
