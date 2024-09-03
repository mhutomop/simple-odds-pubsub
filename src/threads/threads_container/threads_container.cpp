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
#include "../../globals/globals.h"
#include "../../adapters/service_adapters/odds_adapter/subscribers/test_odds_subscriber/test_odds_subscriber.h"

void ThreadsContainer::odds_subscriber_thread() {
    std::array<boost::function<void ()>, 1> subscriber_threads = {
        boost::bind(&ThreadsContainer::odds_test_subscriber_thread),
    };

    boost::thread_group t_group;

    std::ranges::for_each(subscriber_threads, [&t_group] (const boost::function<void ()> &subscriber_thread) {
        t_group.create_thread(subscriber_thread);
    });
    t_group.join_all();
}

void ThreadsContainer::odds_test_subscriber_thread() {
    TestODDSSubscriber test_odds_subscriber(domain_participant->get_participant_());
    test_odds_subscriber.start();
}
