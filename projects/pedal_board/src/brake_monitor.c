#include "ads1015.h"
#include "event_queue.h"
#include "fsm.h"
#include "log.h"
#include "soft_timer.h"
#include "pedal_events.h"

// Timeout callback
static void prv_blink_timeout(SoftTimerId timer_id, void *context) {
  Ads1015Storage *storage = context;
  int16_t position = 0;
  ads1015_read_raw(storage, storage->current_channel, &position);

  LOG_DEBUG("Brake: %d", position);

  // math to convert readings to angles
  // position =

  // if (position > (3.14 / 4)) {
  //   event_raise(PEDAL_BRAKE_FSM_EVENT_PRESSED, 1);
  // } else {
  //   event_raise(PEDAL_BRAKE_FSM_EVENT_RELEASED, 0);
  // }

  // Schedule another timer - this creates a periodic timer
  soft_timer_start_seconds(0.05, prv_blink_timeout, storage, NULL);
}

// main should have a brake fsm, and ads1015storage
StatusCode brake_monitor_init(Ads1015Storage *storage) {
  ads1015_configure_channel(storage, storage->current_channel, true, NULL,
                            NULL);
  soft_timer_init();
  return soft_timer_start_millis(0.05, prv_blink_timeout, storage, NULL);
}
