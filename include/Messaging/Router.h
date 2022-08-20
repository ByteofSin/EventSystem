// Central location where all messaging components send their messages

#pragma once

// Standard Library
#include <functional>
#include <queue>
#include <vector>

// Component Includes

#include "./Messaging/Message.h"

namespace byteofsin::messaging {
    /** @brief Broadcasts messages recieved from the AddMessage function to Recievers
     *  @see Reciever Class Header
     */
    class Router {
        public:
            Router() = default;
            ~Router() = default;

            /** @brief Add a reciever objects recieve message function to recievers list
             */
            void AddReciever(std::function<void (Message)> recieverFunction){
                recievers.push_back(recieverFunction);
            };

            /** @brief Enqueues a message to later be notified
             */
            void AddMessage(Message message){
                messages.push(message);
            };
            
            /** @brief Notifies recievers of the message
             */
            void Notify(){
                // Iterates unless the messages are empty until they are empty
                while(!messages.empty()){
                    for(auto recieveFunction = recievers.begin(); recieveFunction != recievers.end(); recieveFunction++){
                        (*recieveFunction)(messages.front());
                    }

                    messages.pop();
                }
            };

            /*	Debug/Status
             ========================= */
            /** @brief Returns the amount of recievers currently in the list
             */
            size_t GetRecieverCount(){
                return recievers.size();
            }

            /** @brief Returns the amount of messages currently in the queue
             */
            size_t GetMessageCount(){
                return messages.size();
            }

            /** @brief Returns if the messages queue is empty
             */
            bool IsMessageQueueEmpty(){
                return messages.empty();
            }

        protected:
            std::vector<std::function<void (Message)>> recievers;
            std::queue<Message> messages;
    };
};