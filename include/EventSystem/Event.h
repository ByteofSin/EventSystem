// Interface class to represent various events.
// Also acts as a default for generic events

#pragma once

#include <string>
#include <map>


namespace byteofsin::eventsystem {
    class Event {
        public:
            Event(){};
            virtual ~Event() = 0{};
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
            // Event& operator = (const Event&) {
            //     return *this;
            // };

            std::map<std::string, std::string> variables;
            int priority = 0;
        private:
    }; 

};