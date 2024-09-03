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
 Name        : test_odds_subscriber.h
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.1 07/05/2024
 Description : OpenDDS subscriber for Test topic
 =================================================================================================================
*/

#pragma once
#include <string>
#include "../abstract_odds_subscriber/abstract_odds_subscriber.h"
#include "../../../../../models/odds_models/test_model/TestDataTypeSupportImpl.h"

class TestODDSSubscriber : public AbstractODDSSubscriber
{
public:
    explicit TestODDSSubscriber(const DDS::DomainParticipant_var &participant);

    /**
    * Method to get updated data
    * @return updated data as TestData::Message
    */
    TestData::Message& get_updated_data();

    void start() override;
private:
    DDS::ReturnCode_t result_;
    TestData::MessageSeq msg_list_;
    DDS::SampleInfoSeq info_seq_;
    TestData::MessageDataReader_var ntb2_reader_;
    TestData::Message message_;
};
