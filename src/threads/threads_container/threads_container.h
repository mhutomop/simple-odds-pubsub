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
 Name        : threads_container.h
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 21/05/2024
 Description : File to contains thread functions
 =================================================================================================================
*/

#pragma once
#include "../../adapters/service_adapters/odds_adapter/domain_participant/domain_participant.h"

class ThreadsContainer 
{
public:
    /**
    * Method to run ODDS test subscriber
    */
    static void odds_test_subscriber_thread(ODDSDomainParticipant* domain_participant);
};
