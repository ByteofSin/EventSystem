#pragma once

#include <EventSystem/Event.h>
#include <string>

class TestEvent : public byteofsin::eventsystem::Event {
    public:
        TestEvent(){}
        ~TestEvent() {};

        // void Add(std::string key, std::string value) {
        //     __super::Add(key, value);
        // }
        // std::string Get(std::string key){
        //    return __super::Get(key);
        // }
        
};