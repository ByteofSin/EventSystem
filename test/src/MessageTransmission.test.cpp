#pragma once
/*  Tests the message routers ability to transfer data
*/

#include <gtest/gtest.h>

#include <Messaging/Message.h>
#include <Messaging/Router.h>
#include <Messaging/Reciever.h>

#include <functional>

//#include "../helpers/TestReciever.cpp"

using namespace byteofsin::messaging;

/*	Utility Classes
 ========================= */
class TestRouter : public Router {
    public:
        TestRouter() : Router(){};

        ~TestRouter() = default;

        void AddMessage(Message message){
            Router::AddMessage(message);

            if(!Router::IsMessageQueueEmpty()){
                recievedMessage = true;
            };
            
            if(messages.front().Get("from") == "reciever"){
                recievedFromReciever = true;
            };
        };

        void Notify() {
            Router::Notify();
        }

        bool recievedMessage = false;
        bool recievedFromReciever = false;
};

class TestReciever : public Reciever {
    public:
        TestReciever(Router* messageRouter) : Reciever(messageRouter){

        }

        ~TestReciever() = default;

        void OnMessageRecieved(Message message) {
            this->messageRecieved = true;
            //Reciever::OnMessageRecieved(message);

            if(message.Get("from") == "router") { 
                messageFromRouter = true;
                
                if(message.Get("return") == "true"){
                    Message msg;
                    msg.Add("from", "reciever");

                    messageRouter->AddMessage(msg);
                }
            }
            
        }

        
        std::function<void (Message)> recieveMessage(){
            return Reciever::recieveMessage();
        }

        void Send(Message msg){
            Reciever::Send(msg);
        }

        bool messageFromRouter = false;
        bool messageRecieved = false;
};

/*	Component Creation
 ========================= */
TEST(Message_Transmission, Messaging_Router_Creation){
    Router* testRouter = new Router();

    EXPECT_FALSE(testRouter == NULL) << "Router not constructed properly";

    delete testRouter;
}

TEST(Message_Transmission, Messaging_Reciever_Creation){
    Router testRouter;

    Reciever* testReciever = new Reciever(&testRouter);
    //Reciever testReciever(&testRouter);

    EXPECT_FALSE(testReciever == NULL) << "Reciever not constructed";

    delete testReciever;
}

/*	Router Testing
 ========================= */
TEST(Message_Transmission, Router_Adding_Recievers){
    Router testRouter;  
    TestReciever a(&testRouter), b(&testRouter), c(&testRouter); 

    EXPECT_TRUE(testRouter.GetRecieverCount() == 3) << "The reciever count does not match the correct value:\nExpected: 3 \nActual: " + testRouter.GetRecieverCount();
}

TEST(Message_Transmission, Router_Enqueues_Messages){
    Router testRouter;

    Message msg;

    EXPECT_TRUE(testRouter.IsMessageQueueEmpty());

    testRouter.AddMessage(msg);

    EXPECT_FALSE(testRouter.IsMessageQueueEmpty());
}

TEST(Message_Transmission, Router_Deques_Messages_On_Notify){
    Router testRouter;

    Message msg;

    testRouter.AddMessage(msg);

    EXPECT_TRUE(testRouter.GetMessageCount() != 0) << "Initial message not recieved";

    testRouter.Notify();

    EXPECT_TRUE(testRouter.GetMessageCount() == 0) << "Messages not removed from message queue";
}


/*	Reciever Testing
 ========================= */
TEST(Message_Transmission, Reciever_OnRecieved_Static_Call){
    Router testRouter;
    TestReciever testReciever(&testRouter);

    Message msg;

    testReciever.OnMessageRecieved(msg);

    EXPECT_TRUE(testReciever.messageRecieved);
}

TEST(Message_Transmission, Reciever_OnRecieved_RecieveMessage_Callback){
    Router testRouter;
    TestReciever testReciever(&testRouter);

    std::function<void (Message)> recieverCallbackFunction = testReciever.recieveMessage();

    Message msg;

    recieverCallbackFunction(msg);

    EXPECT_TRUE(testReciever.messageRecieved);
}

//TODO Adding and removing varying sizes of message counts

TEST(Message_Transmission, Reciever_OnRecieve_From_Router){
    Router testRouter;
    TestReciever testReciever(&testRouter);

    Message msg;

    msg.Add("from", "router");
    msg.Add("return", "false");

    testRouter.AddMessage(msg);

    testRouter.Notify();

    EXPECT_TRUE(testReciever.messageFromRouter);// << testRouter.GetMessageCount() + " Messages in queue";
}

TEST(Message_Transmission, Reciever_Responding_To_Router_Message){
    Router testRouter;
    TestReciever testReciever(&testRouter);

    Message msg;


    msg.Add("from", "router");
    msg.Add("return","true");

    testRouter.AddMessage(msg);

    EXPECT_FALSE(testRouter.IsMessageQueueEmpty()) << "Router did not recieve message";

    testRouter.Notify();

    EXPECT_TRUE(testReciever.messageRecieved) << "Message not recieved by reciever";
    EXPECT_TRUE(testReciever.messageFromRouter) << "Message recieved by reciever but not from router";
}

//TODO Implement way to check for response 

TEST(Message_Transmission, Reciever_Sending_To_Router){
    Router testRouter;
    TestReciever testReciever(&testRouter);

    Message msg;

    msg.Add("from", "reciever");

    testReciever.Send(msg);

    EXPECT_FALSE(testRouter.IsMessageQueueEmpty()) << "Message from reciever not added to message queue";


}