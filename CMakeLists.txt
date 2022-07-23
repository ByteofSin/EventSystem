set(This ByteofSin_Events)

set(Headers
    include/EventSystem/Event.h
)

set(Sources
    src/EventDispatcher.cpp
)

add_library(${This} STATIC ${Headers} ${Sources})

set_target_properties(${This} PROPERTIES
    FOLDER Libraries
)

target_include_directories(${This} PUBLIC include)

add_subdirectory(test)