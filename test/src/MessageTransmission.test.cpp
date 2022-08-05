#pragma once
/*  Tests the message routers ability to transfer data
*/

#include <gtest/gtest.h>

#include <Messaging/Router.h>
#include <Messaging/Reciever.h>

//#include "../helpers/TestReciever.cpp"

using namespace byteofsin::messaging;


TEST(Messaging_System, Messaging_Router_Creation){
    Router* testRouter = new Router();

    EXPECT_FALSE(testRouter == NULL) << "Router not constructed properly";

    delete testRouter;
}

TEST(Messaging_System, Messaging_Reciever_Creation){
    Router testRouter;

    Reciever* testReciever = new Reciever(&testRouter);
    //Reciever testReciever(&testRouter);

    EXPECT_FALSE(testReciever == NULL) << "Reciever not constructed";

    delete testReciever;
}

TEST(Messaging_System, Messaging_Reciever_Recieve_Message){
    Router testRouter;
    Reciever testReciever(&testRouter);

    //TODO
}
