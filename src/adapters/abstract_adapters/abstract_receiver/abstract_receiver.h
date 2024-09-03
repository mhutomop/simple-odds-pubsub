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
 Name        : abstract_receiver.h
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 21/05/2024
 Description : Abstract for receiver
 =================================================================================================================
*/

#pragma once
#include "../observable/observable.h"

class AbstractReceiver : public Observable
{
public:
    AbstractReceiver();
    virtual ~AbstractReceiver() = default;

    /**
    * Interface method to start receiver
    */
    virtual void start() = 0;
    /**
    * Interface method to stop receiver
    */
    virtual void stop() = 0;
};
