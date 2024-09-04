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
 Name        : test_odds_publisher.h
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.1 07/05/2024
 Description : OpenDDS publisher for Test topic
 =================================================================================================================
*/

#pragma once
#include <string>
#include "../abstract_odds_publisher/abstract_odds_publisher.h"
#include "../../../../../../build/opendds_generated/TestDataTypeSupportImpl.h"

class TestODDSPublisher : public AbstractODDSPublisher
{
public:
    explicit TestODDSPublisher(const DDS::DomainParticipant_var &participant);

    /**
    * Method to set test_msg_
    * @param test_msg shape type message to be set
    */
    void set_test_msg_(const TestData::Message &test_msg);

    void publish_message() override;
private:
    TestData::MessageDataWriter_var test_writer_;
    TestData::Message test_msg_;
};
