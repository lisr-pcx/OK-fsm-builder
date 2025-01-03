// OK-fsm-builder
// (github.com/lisr-pcx/OK-fsm-builder)

#include <iostream>
#include <string>

#include "FSMSample.h"

int main()
{
    std::cout << "OK-fsm-builder: testing features\nSTART sample...\n\n";

    FSMSample test;

    test.Event(FSMSampleEvent::IN1);
    test.Event(FSMSampleEvent::IN2);
    test.Event(FSMSampleEvent::IN3);

    std::cout << "\n\nEND sample\n";
    return 0;
}