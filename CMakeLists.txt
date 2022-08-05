set(This ByteofSin_Messaging)

set(Headers
    # Core
    include/Messaging/Message.h
    include/Messaging/Router.h

    # Components
    include/Messaging/Reciever.h
)

set(Sources
    src/temp.cpp
)

add_library(${This} STATIC ${Headers} ${Sources})

set_target_properties(${This} PROPERTIES
    FOLDER Libraries
    LINKER_LANGUAGE CXX
)

target_include_directories(${This} PUBLIC include)

add_subdirectory(test)