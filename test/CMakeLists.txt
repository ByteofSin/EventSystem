set(This Messaging_System)

set(Sources
    # Helpers Classes
    helpers/TestMessage.cpp
    #helpers/TestReciever.cpp

    # Tests
    src/Message.test.cpp
    src/MessageTransmission.test.cpp
)

add_executable(${This} ${Sources})
set_target_properties(${This} PROPERTIES
    FOLDER Tests
    LINKER_LANGUAGE CXX
)

target_link_libraries(${This} PUBLIC
    gtest_main
    ByteofSin_Messaging
)

include(GoogleTest)
gtest_discover_tests(${This})