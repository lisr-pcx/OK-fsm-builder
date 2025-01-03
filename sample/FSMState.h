// OK-fsm-builder
// (github.com/lisr-pcx/OK-fsm-builder)

#ifndef FSM_STATE_H
#define FSM_STATE_H

class FSMState
{
public:
    virtual ~FSMState() { /* clean-up*/ };
    virtual void Event(const FSMSampleEvent& event_id, FSMSampleContext& context, FSMSampleState& next_state) = 0;
    virtual void EntryState(FSMSampleContext& context) = 0;

protected:
    virtual void RunState(FSMSampleContext& context) = 0;
    virtual void ExitState(FSMSampleContext& context) = 0;
};

#endif // FSM_STATE_H