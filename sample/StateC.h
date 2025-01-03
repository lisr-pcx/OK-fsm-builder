// OK-fsm-builder
// (github.com/lisr-pcx/OK-fsm-builder)

#ifndef STATE_C_H
#define STATE_C_H

#include "FSMState.h"

class StateC : public FSMState
{
public:
    virtual ~StateC() {};

    virtual void Event(const FSMSampleEvent& event_id, FSMSampleContext& context, FSMSampleState& next_state)
    {
        switch (event_id)
        {
            default:
                std::cout << "\n..Event not managed in State C";
                break;
        }
    };

    virtual void EntryState(FSMSampleContext& context)
    {
        std::cout << "\n..EntryState C, trigger action";
    };

protected:
    virtual void RunState(FSMSampleContext& context)
    {
        std::cout << "\n..RunState C, trigger action";
    };

    virtual void ExitState(FSMSampleContext& context)
    {
        std::cout << "\n..ExitState C, trigger action";
    };
};

#endif // STATE_C_H