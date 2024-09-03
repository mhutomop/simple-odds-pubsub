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
 Version     : 1.0.0 21/05/2024
 Description : Domain Participant of OpenDDS
 =================================================================================================================
*/

#include "domain_participant.h"
#include <iostream>
#include <string>
#include "../../../../globals/constants.h"

ODDSDomainParticipant::ODDSDomainParticipant() 
{
    /* The DDS entities required to publish data */
    DDS::DomainParticipantFactory_var factory;
    DDS::DomainId_t                   domain;

    // Get the DDS DomainParticipantFactory
    int argc = 5;
    char* arg1 = strdup(std::string("./" + std::string(kServiceName)).c_str());
    char* arg2 = strdup("-DCPSInfoRepo");
    char* arg3 = strdup(std::getenv("IOR_PATH"));
    char* arg4 = strdup("-DCPSConfigFile");
    char* arg5 = strdup(std::getenv("RTPS_PATH"));
    std::array<ACE_TCHAR*, 6> args = { arg1, arg2, arg3, arg4, arg5, NULL };
    factory = TheParticipantFactoryWithArgs(argc, args.data());
    this->odds_operator_.check_handle(factory, "get_instance() failed");

    // Create a domain participant entity for the Default Domain (Domain Id = 0)
    domain = 0;
    participant_ = factory->create_participant(domain, PARTICIPANT_QOS_DEFAULT, nullptr, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    this->odds_operator_.check_handle(participant_, "create_participant() failed");
}

DDS::DomainParticipant_var& ODDSDomainParticipant::get_participant_() {
    return this->participant_;
}
