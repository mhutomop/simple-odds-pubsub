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
 Name        : threads_container.cpp
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 21/05/2024
 Description : File to contains thread functions
 =================================================================================================================
*/

#include "threads_container.h"
#include <thread>
#include <boost/function.hpp>
#include <boost/bind/bind.hpp>
#include <boost/thread.hpp>
#include "../../adapters/service_adapters/odds_adapter/subscribers/test_odds_subscriber/test_odds_subscriber.h"

void ThreadsContainer::odds_test_subscriber_thread(ODDSDomainParticipant* domain_participant) {
    TestODDSSubscriber test_odds_subscriber(domain_participant->get_participant_());
    test_odds_subscriber.start();
}
