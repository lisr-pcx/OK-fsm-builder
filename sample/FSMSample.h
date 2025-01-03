// OK-fsm-builder
// (github.com/lisr-pcx/OK-fsm-builder)

#ifndef FSM_SAMPLE_H
#define FSM_SAMPLE_H

#include <iostream>
#include <map>

enum class FSMSampleEvent
{
    IN1,
    IN2,
    IN3,
};

enum class FSMSampleState
{
    SA,
    SB,
    SC,
};

class FSMState;     // Forward declaration

class FSMSampleContext
{
public:
    FSMSampleState  current_state;
    FSMState*       current_state_ptr = nullptr;
    // Add other useful info
};

class FSMSampleAction
{
public:
    static void ActionA(FSMSampleContext& context) { std::cout << "\n..ActionA"; };
    static void ActionB(FSMSampleContext& context) { std::cout << "\n..ActionB"; };
    static void ActionC(FSMSampleContext& context) { std::cout << "\n..ActionC"; };
    static void ActionD(FSMSampleContext& context) { std::cout << "\n..ActionD"; };
};

#include "FSMState.h"
#include "StateA.h"
#include "StateB.h"
#include "StateC.h"

class FSMSample
{
public:

    FSMSample()
    {
        // Create all states, and define entry point

        FSMState* state_ptr = new StateA();
        map_states_.insert(std::pair<FSMSampleState, FSMState*>(FSMSampleState::SA, state_ptr));
        context_.current_state = FSMSampleState::SA;
        context_.current_state_ptr = state_ptr;
        state_ptr->EntryState(context_);

        state_ptr = new StateB();
        map_states_.insert(std::pair<FSMSampleState, FSMState*>(FSMSampleState::SB, state_ptr));

        state_ptr = new StateC();
        map_states_.insert(std::pair<FSMSampleState, FSMState*>(FSMSampleState::SC, state_ptr));
    };

    ~FSMSample()
    {
        // Delete all states
        for (auto s : map_states_)
        {
            delete s.second;
        }
        map_states_.clear();
    };

    void Event(const FSMSampleEvent& event_id)
    {
        if (context_.current_state_ptr != nullptr)
        {
            FSMSampleState move_to_state = context_.current_state;
            context_.current_state_ptr->Event(event_id, context_, move_to_state);

            // Manage transition to next state
            if (move_to_state != context_.current_state)
            {
                FSMState* state = StatePointer(move_to_state);
                if (state != nullptr)
                {
                    context_.current_state = move_to_state;
                    context_.current_state_ptr = state;
                    // Run entry action on the next state
                    state->EntryState(context_);
                }
            }
        }
    };
    
private:
    FSMSampleContext context_;
    std::map<FSMSampleState, FSMState*> map_states_;

    FSMState* StatePointer(FSMSampleState state)
    {
        FSMState* state_pointer = nullptr;
        std::map<FSMSampleState, FSMState*>::iterator elem;
        elem = map_states_.find(state);
        if (elem != map_states_.end())
        {
            state_pointer = elem->second;
        }
        return state_pointer;
    };
};

#endif // FSM_SAMPLE_H