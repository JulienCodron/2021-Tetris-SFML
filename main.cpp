#include "FrameManager.hpp"
#include "test.cpp"
#include "MemoryManager.hpp"
#include "DEFINITIONS.hpp"

#include "windows.h"
#define _CRTDBG_MAP_ALLOC //to get more details
#include <stdlib.h>  
#include <crtdbg.h>   //for malloc and free


#include "MainMenuState.hpp"
#include <iostream>

//class alo {
//public:
//    virtual void showi() = 0;
//};

//class Complex : public alo {
//private:
//    int x;
//    int y;
//    int z;
//public:
//    Complex(int x, int y,int z) : x(x),y(y), z(z) {};
//    void showi() {};
//};
//
//void test() {
//    alo* a = new Complex(1,2,6);
//    delete a;
//
//    a = new Complex(1, 9, 8);
//    delete a;
//}

int main()
{
    _CrtMemState sOld;
    _CrtMemState sNew;
    _CrtMemState sDiff;
    _CrtMemCheckpoint(&sOld); //take a snapshot

    FrameManager(SCREEN_WIDTH,SCREEN_HEIGHT, "Tetris");

    _CrtMemCheckpoint(&sNew); //take a snapshot 
    if (_CrtMemDifference(&sDiff, &sOld, &sNew)) // if there is a difference
    {
        OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
        _CrtMemDumpStatistics(&sDiff);
        OutputDebugString(L"-----------_CrtMemDumpAllObjectsSince ---------");
        _CrtMemDumpAllObjectsSince(&sOld);
        /*OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
        _CrtDumpMemoryLeaks();*/
    }

    return 0;
}