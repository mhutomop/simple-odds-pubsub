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
 Name        : observable.h
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 21/05/2024
 Description : Observable
 =================================================================================================================
*/

#pragma once
#include <list>
#include <thread>
#include "../observer/observer.h"

class Observable
{
public:
    /**
    * Method to add observer
    * @param observer observer to be added
    */
    void add_observer(Observer* observer);
    /**
    * Method to remove observer
    * @param observer observer to be removed
    */
    void remove_observer(Observer* observer);
    /**
    * Method to notify all observers
    */
    void notify_observers();
    /**
    * Method to synchronize all observer threads
    */
    void sync_threads();
private:
    std::list<Observer*> observers_;
    std::list<std::jthread> threads_;
};
