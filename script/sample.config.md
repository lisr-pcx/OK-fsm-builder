# SAMPLE.CONFIG.MD

Content of this file is used by tool "OK-fsm-builder" to automatically generated source code of the finite state machine described below, but also as documentation.

Values below are just an example to demonstrate the tool.

Please edit all the fields in UPPERCASE characters to desired values.

## Description

FSM name: SAMPLE

Output path (directory): SAMPLE

State transition table:

| event | current state | next state | action |
| --- | --- | --- | --- |
| EV1 | STATEA | STATEB | FUNC1 |
| EV2 | STATEB | STATEC | none |
| EV3 | STATEA | STATEC | FUNC2 |

Actions triggered by event:

| event | action |
| --- | --- |
| EV1 | FUNC3 |
| EV2 | FUNC4 |

Actions managed by each state:

| state | entry action | cyclic action | exit action |
| --- | --- | --- | --- |
| STATEA | FUNC5 | FUNC6 | FUNC7 |
| STATEB | none | FUNC8 | none |
| STATEC | none | none | none |