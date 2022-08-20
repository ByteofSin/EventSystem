// Interface class to represent various messages.
// Also acts as a default for generic messages

#pragma once

#include <string>
#include <map>
#include <stdexcept>

namespace byteofsin::messaging {
    /** @brief Abstract class representing a generic message
     *  @details An abstract class that represents a default message. By default uses key value pairs to store message data
     */
    class Message {
        public:
            Message(){
                //TODO Give each message a unique message id
                //Add("Name", "Default");
            };
            // Data access
            void Add(std::string key, std::string value, bool forceUpdate = false) {
                if(variables.find(key) == variables.end()){
                    variables.insert(std::pair<std::string, std::string>(key, value));
                } else if(forceUpdate){
                    variables.erase(key);
                    variables.insert(std::pair<std::string, std::string>(key, value));
                }

                //variables.insert(std::pair<std::string, std::string>(key, value));
            }

            std::string Get(std::string key){
                //return variables.at(key);
                std::string returnValue;

                try {
                    returnValue = variables.at(key);
                } catch (std::out_of_range& const error){
                    returnValue = error.what();
                }

                return returnValue;
            }

        protected:
            int priority = 0;
        private:
            // Private to allow each message type to implement their own storage format
            std::map<std::string, std::string> variables;
    }; 

};