#pragma once

#include <string>
#include <vector>


namespace byteofsin::eventsystem {
    class Event {
        public:
            // Object Construction
            Event() = default;
            virtual~ Event();

            // Data access
            
        protected:
            bool handled;
            std::string name;
        private:
        
    };
};