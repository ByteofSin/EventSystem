#pragma once 

namespace byteofsin::eventsystem {
    class EventReciever {
        public:
            EventReciever() = default;

            void OnRecieve();
    };
};