#pragma once

#include <Messaging/Message.h>
#include <string>

class TestMessage : public byteofsin::messaging::Message {
    public:
        TestMessage(){}
        ~TestMessage() {};

        // void Add(std::string key, std::string value) {
        //     __super::Add(key, value);
        // }
        // std::string Get(std::string key){
        //    return __super::Get(key);
        // }
        
};