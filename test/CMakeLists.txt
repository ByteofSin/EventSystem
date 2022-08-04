enable_testing()

set(This Event_System)

set(Sources
    # Helpers Classes
    src/TestEvent.cpp

    # Tests
    src/EventObject.test.cpp
    src/EventDispatchAndRetrieve.test.cpp
)

add_executable(${This} ${Sources})
set_target_properties(${This} PROPERTIES
    FOLDER Tests
)

target_link_libraries(${This} PUBLIC
    gtest_main
    ByteofSin_Events
)

include(GoogleTest)
gtest_discover_tests(${This})