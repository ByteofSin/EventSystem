// Central location where all messaging components send their messages

#pragma once

// Standard Library
#include <functional>
#include <queue>
#include <vector>

// Component Includes

#include "./Messaging/Message.h"

namespace byteofsin::messaging {
    class Router {
        public:
            Router(){};
            ~Router(){};

            // Adds Reciever to list of recievers
            void AddReciever(std::function<void (Message)> recieverFunction){
                recievers.push_back(recieverFunction);
            };

            // Adds a message to the queue
            void AddMessage(Message message){
                messages.push(message);
            };

            // Sends messages to each component
            void Notify(){};
        protected:
            std::vector<std::function<void (Message)>> recievers;
            std::queue<Message> messages;
    };
};