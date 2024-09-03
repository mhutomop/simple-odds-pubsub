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
 Name        : globals.h
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 21/05/2024
 Description : Declaration of global variables and objects
 =================================================================================================================
*/

#pragma once
#include <condition_variable>
#include "../adapters/service_adapters/odds_adapter/domain_participant/domain_participant.h"
#include "../adapters/service_adapters/odds_adapter/publishers/test_odds_publisher/test_odds_publisher.h"

inline ODDSDomainParticipant* domain_participant;
inline TestODDSPublisher* test_odds_publisher;
