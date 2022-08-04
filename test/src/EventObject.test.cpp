#pragma once
/*  Basic tests specifically for the event class 
    uses the test event class as a proxy 
*/

#include <gtest/gtest.h>
#include "./TestEvent.cpp"

#include <string>


// Creating an object
TEST(Event_System, Event_Object_Creation){
    TestEvent* testedEvent = new TestEvent();   
    EXPECT_FALSE(testedEvent == NULL) << "Event object set to NULL";

    delete testedEvent;
}

// Adding variables and retrieving them 
TEST(Event_System, Event_Object_Variable_Insertion_and_Retrieval){
    TestEvent* testedEvent = new TestEvent(); 
    std::string expectedValue = "Tested Event";

    testedEvent->Add("Name", "Tested Event");
    


    EXPECT_TRUE(testedEvent->Get("Name") == expectedValue);

    delete testedEvent;
}

// Adding multiple variables and retrieving them
TEST(Event_System, Event_Object_MultiVariable_Insertion_and_Retrieval){
    TestEvent* testedEvent = new TestEvent();

    // Expected Values
    std::string valueA = "Value A";
    std::string valueB = "Value B";
    std::string valueC = "Value C";

    // Adding to event
    testedEvent->Add("Key A", "Value A");
    testedEvent->Add("Key B", "Value B");
    testedEvent->Add("Key C", "Value C");

    
    EXPECT_TRUE(testedEvent->Get("Key A") == valueA) 
        << "Event variable value for key A is incorrect";
    
    EXPECT_TRUE(testedEvent->Get("Key B") == valueB)
        << "Event variable value for key B is incorrect";
    
    EXPECT_TRUE(testedEvent->Get("Key C") == valueC)
        << "Event variable value for key C is incorrect";
}

// Adding duplicate keys
TEST(Event_System, Event_Object_Duplicate_Variable_Insertion){
    TestEvent* testedEvent = new TestEvent();

    // Expected Values
    std::string initialValue = "Initial Value";
    std::string updatedValue = "Updated Value";

    testedEvent->Add("Key", "Initial Value");

    EXPECT_TRUE(testedEvent->Get("Key") == initialValue)
        << "Event variable initial value incorrect";

    testedEvent->Add("Key", "Updated Value");

    EXPECT_TRUE(testedEvent->Get("Key") == initialValue)
        << "Event variable updated existing value without force update flag";

    testedEvent->Add("Key", "Updated Value", true);

    EXPECT_TRUE(testedEvent->Get("Key") == updatedValue) 
        << "Event variable not updated when given force update flag";

}