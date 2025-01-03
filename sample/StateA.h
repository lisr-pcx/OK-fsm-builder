// OK-fsm-builder
// (github.com/lisr-pcx/OK-fsm-builder)

#ifndef STATE_A_H
#define STATE_A_H

#include <iostream>
#include "FSMState.h"

class StateA : public FSMState
{
public:
    virtual ~StateA() {};

    virtual void Event(const FSMSampleEvent& event_id, FSMSampleContext& context, FSMSampleState& next_state)
    {
        switch (event_id)
        {
            case FSMSampleEvent::IN1:
                std::cout << "\n..Event IN1 in State A, trigger action";
                FSMSampleAction::ActionA(context);
                this->RunState(context);
                this->ExitState(context);
                std::cout << "\n..Transition to State B, trigger action";
                FSMSampleAction::ActionB(context);
                next_state = FSMSampleState::SB;
                break;
            case FSMSampleEvent::IN3:
                std::cout << "\n..Event IN3 in State A, trigger action";
                this->RunState(context);
                this->ExitState(context);
                std::cout << "\n..Transition to State C, trigger action";
                next_state = FSMSampleState::SC;
                break;
            default:
                std::cout << "\n..Event not managed in State A";
                break;
        }
    };

    virtual void EntryState(FSMSampleContext& context)
    {
        std::cout << "\n..EntryState A, trigger action";
        FSMSampleAction::ActionC(context);
    };

protected:
    virtual void RunState(FSMSampleContext& context)
    {
        std::cout << "\n..RunState A, trigger action";
        FSMSampleAction::ActionD(context);
    };

    virtual void ExitState(FSMSampleContext& context)
    {
        std::cout << "\n..ExitState A, trigger action";
    };
};

#endif // STATE_A_H