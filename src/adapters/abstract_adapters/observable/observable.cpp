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
 Name        : observable.cpp
 Author      : Muhammad Hutomo Padmanaba
 Version     : 1.0.0 21/05/2024
 Description : Observable
 =================================================================================================================
*/

#include "observable.h"

void Observable::add_observer(Observer* observer) {
    this->observers_.push_back(observer);
}

void Observable::remove_observer(Observer* observer) {
    this->observers_.remove(observer);
}

void Observable::notify_observers() {
    for (auto observer : this->observers_) {
        this->threads_.emplace_back([observer] () {
            observer->update_data();
        });
    }
}

void Observable::sync_threads() {
    for (auto& thread : this->threads_) {
        thread.join();
    }

    this->threads_.clear();
}

