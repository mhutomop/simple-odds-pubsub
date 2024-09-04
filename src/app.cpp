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
#include "utils/log_util/logger.h"
#include "globals/globals.h"

int main(int argc, char** argv) {
    try {
        // Create a domain participant
        domain_participant = std::make_unique<ODDSDomainParticipant>().release();
        
        // Create ODDS publishers
        test_odds_publisher = std::make_unique<TestODDSPublisher>(domain_participant->get_participant_()).release();

        // Create a thread to run ODDS subscribers
        std::jthread odds_thread(ThreadsContainer::odds_subscriber_thread);

        while(true) {
            TestData::Message test_msg;
            test_msg.command("GREEN");
            test_msg.type(2);
            test_odds_publisher->set_test_msg_(test_msg);
            test_odds_publisher->publish_message();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
    catch (const std::exception &err) {
        LOG_ERROR("Main Method", err.what());
    }

    return 0;
}
