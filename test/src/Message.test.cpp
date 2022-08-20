#pragma once
/*  Basic tests specifically for the event class 
    uses the test event class as a proxy 
*/

#include <gtest/gtest.h>
#include "../helpers/TestMessage.cpp"

#include <string>

#define Message_Test_Name Message_Object

// Creating an object
TEST(Message_Test_Name, Message_Creation){
    TestMessage* testMessage = new TestMessage();   
    EXPECT_FALSE(testMessage == NULL) << "Message object set to NULL";

    delete testMessage;
}

// Adding variables and retrieving them 
TEST(Message_Test_Name, Message_Variable_Insertion_and_Retrieval){
    TestMessage* testMessage = new TestMessage(); 
    std::string expectedValue = "Tested Event";

    testMessage->Add("Name", "Tested Event");

    EXPECT_TRUE(testMessage->Get("Name") == "Tested Event") << "Message failed to retrieve value from key\nError: " + testMessage->Get("Name");

    delete testMessage;
}

// Adding multiple variables and retrieving them
TEST(Message_Test_Name, Message_MultiVariable_Insertion_and_Retrieval){
    TestMessage* testMessage = new TestMessage();

    // Expected Values
    std::string valueA = "Value A";
    std::string valueB = "Value B";
    std::string valueC = "Value C";

    // Adding to event
    testMessage->Add("Key A", "Value A");
    testMessage->Add("Key B", "Value B");
    testMessage->Add("Key C", "Value C");

    
    EXPECT_TRUE(testMessage->Get("Key A") == "Value A") 
        << "Event variable value for key A is incorrect";
    
    EXPECT_TRUE(testMessage->Get("Key B") == "Value B")
        << "Event variable value for key B is incorrect";
    
    EXPECT_TRUE(testMessage->Get("Key C") == "Value C")
        << "Event variable value for key C is incorrect";

    delete testMessage;
}

// Adding duplicate keys
TEST(Message_Test_Name, Message_Duplicate_Variable_Insertion){
    TestMessage* testMessage = new TestMessage();

    // Expected Values
    std::string initialValue = "Initial Value";
    std::string updatedValue = "Updated Value";

    testMessage->Add("Key", "Initial Value");

    EXPECT_TRUE(testMessage->Get("Key") == initialValue)
        << "Event variable initial value incorrect";

    testMessage->Add("Key", "Updated Value");

    EXPECT_TRUE(testMessage->Get("Key") == initialValue)
        << "Event variable updated existing value without force update flag";

    testMessage->Add("Key", "Updated Value", true);

    EXPECT_TRUE(testMessage->Get("Key") == updatedValue) 
        << "Event variable not updated when given force update flag";

        
    delete testMessage;
}