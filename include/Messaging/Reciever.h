#pragma once

#include <functional>
#include <iostream>

#include "./Messaging/Router.h"
#include "./Messaging/Message.h"

namespace byteofsin::messaging {
    class Reciever {
        public:
            Reciever(Router* messageRouter){
                this->messageRouter = messageRouter;
                this->messageRouter->AddReciever(this->recieveMessage());
            }

            virtual void update(){};

        protected:
            byteofsin::messaging::Router* messageRouter;

            std::function<void (Message)> recieveMessage() {
                auto messageListener = [this](Message message) -> void  {
                    this->OnMessageRecieved(message);
                };

                return messageListener;
            }

            void Send(Message message){
                //this->messageRouter->AddMessage(message);
            }

            virtual void OnMessageRecieved(Message message){
                std::cout << "message recieved" << std::endl;
            }
    };
};