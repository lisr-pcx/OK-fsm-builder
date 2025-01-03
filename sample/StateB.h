// OK-fsm-builder
// (github.com/lisr-pcx/OK-fsm-builder)

#ifndef STATE_B_H
#define STATE_B_H

#include "FSMState.h"

class StateB : public FSMState
{
public:
    virtual ~StateB() {};
    
    virtual void Event(const FSMSampleEvent& event_id, FSMSampleContext& context, FSMSampleState& next_state)
    {
        switch (event_id)
        {
            case FSMSampleEvent::IN2:
                std::cout << "\n..Event IN2 in State B, trigger action";
                this->RunState(context);
                this->ExitState(context);
                std::cout << "\n..Transition to State C, trigger action";
                next_state = FSMSampleState::SC;
                break;
            default:
                std::cout << "\n..Event not managed in State B";
                break;
        }
    };

    virtual void EntryState(FSMSampleContext& context)
    {
        std::cout << "\n..EntryState B, trigger action";
    };

protected:
    virtual void RunState(FSMSampleContext& context)
    {
        std::cout << "\n..RunState B, trigger action";
    };

    virtual void ExitState(FSMSampleContext& context)
    {
        std::cout << "\n..ExitState B, trigger action";
    };
};

#endif // STATE_B_H