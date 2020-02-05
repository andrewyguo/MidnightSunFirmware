#include "event_queue.h"
#include "fsm.h"
#include "log.h"
#include "pedal_events.h"

<<<<<<< HEAD
Fsm *brake_fsm;

=======
>>>>>>> 5d5aa94fb8e673ab624420273fc1d6808257da11
FSM_DECLARE_STATE(brake_state_released);
FSM_DECLARE_STATE(brake_state_pressed);

FSM_STATE_TRANSITION(brake_state_pressed) {
  FSM_ADD_TRANSITION(PEDAL_BRAKE_FSM_EVENT_RELEASED, brake_state_released);
};

FSM_STATE_TRANSITION(brake_state_released) {
  FSM_ADD_TRANSITION(PEDAL_BRAKE_FSM_EVENT_PRESSED, brake_state_pressed);
}

<<<<<<< HEAD

=======
>>>>>>> 5d5aa94fb8e673ab624420273fc1d6808257da11
static void prv_pressed_output(Fsm *fsm, const Event *e, void *context) {
  // raises a can event to main, which sends can message
  event_raise(PEDAL_CAN_EVENT_BRAKE_PRESSED, 1);
}

static void prv_released_output(Fsm *fsm, const Event *e, void *context) {
  // raises a can event to main, which sends can message
  event_raise(PEDAL_CAN_EVENT_BRAKE_RELEASED, 0);
}

<<<<<<< HEAD
bool brake_fsm_process_event(Event *e) {
=======
bool brake_fsm_process_event(Fsm *brake_fsm, Event *e) {
>>>>>>> 5d5aa94fb8e673ab624420273fc1d6808257da11
  // transition the state
  return fsm_process_event(brake_fsm, e);
}

<<<<<<< HEAD
//main should have a brake fsm, and ads1015storage
StatusCode brake_fsm_init(Fsm *brake) {
  fsm_state_init(brake_state_pressed, prv_pressed_output);
  fsm_state_init(brake_state_released, prv_released_output);
  brake_fsm = brake;
=======
// main should have a brake fsm, and ads1015storage
StatusCode brake_fsm_init(Fsm *brake) {
  fsm_state_init(brake_state_pressed, prv_pressed_output);
  fsm_state_init(brake_state_released, prv_released_output);
>>>>>>> 5d5aa94fb8e673ab624420273fc1d6808257da11

  fsm_init(brake, "Brake_FSM", &brake_state_released, brake);
  return STATUS_CODE_OK;
}
