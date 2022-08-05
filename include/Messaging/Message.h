// Interface class to represent various messages.
// Also acts as a default for generic messages

#pragma once

#include <string>
#include <map>


namespace byteofsin::messaging {
    class Message {
        public:
            Message(){};
            // Data access
            void Add(std::string key, std::string value, bool forceUpdate = false) {
                if(variables.find(key) == variables.end()){
                    variables.insert({key, value});
                } else if(forceUpdate){
                    variables.erase(key);
                    variables.insert({key, value});
                }
            }

            std::string Get(std::string key){
                return variables.at(key);
            }

        protected:
            int priority = 0;
        private:
            // Private to allow each message type to implement their own storage format
            std::map<std::string, std::string> variables;
    }; 

};