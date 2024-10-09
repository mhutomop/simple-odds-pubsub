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
 Name        : main.cpp
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 21/05/2024
 Description : Main file of application
 =================================================================================================================
*/

#include "threads/threads_container/threads_container.h"
#include "adapters/service_adapters/odds_adapter/domain_participant/domain_participant.h"
#include "adapters/service_adapters/odds_adapter/publishers/test_odds_publisher/test_odds_publisher.h"
#include "utils/log_util/log_util.h"

int main(int argc, char** argv) {
    try {
        // Create a domain participant
        ODDSDomainParticipant* domain_participant = ODDSDomainParticipant::get_instance().get();

        // Create ODDS publishers
        auto test_odds_publisher = std::make_unique<TestODDSPublisher>(domain_participant->get_participant_()).release();

        // Create a thread to run ODDS test subscriber
        std::thread odds_test_subscriber_thread(ThreadsContainer::odds_test_subscriber_thread, domain_participant);

        while(true) {
            HelloWorldData::Msg test_msg;
            test_msg.user_id = 9;
            test_msg.message = "Hello from C++!";
            test_odds_publisher->set_test_msg_(test_msg);
            test_odds_publisher->publish_message();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        odds_test_subscriber_thread.join();
    }
    catch (const std::exception &err) {
        LOG_ERROR("Main Method", err.what());
    }

    return 0;
}
