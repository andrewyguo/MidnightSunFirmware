#include "throttle.h"

#include "brake_data.h"
#include "ads1015.h"
#include "log.h"

// Timeout callback
StatusCode throttle_init(ThrottleStorage *storage, Ads1015Storage *pedal_ads1015_storage) {
  // if (storage == NULL) {
  //   return status_code(STATUS_CODE_INVALID_ARGS);
  // } 
  status_ok_or_return(
      ads1015_configure_channel(pedal_ads1015_storage, ADS1015_CHANNEL_0, true, NULL, NULL));
  status_ok_or_return(
      ads1015_configure_channel(pedal_ads1015_storage, ADS1015_CHANNEL_1, true, NULL, NULL));
  
  return STATUS_CODE_OK; 
}

int16_t getThrottleData(Ads1015Storage *storage, Ads1015Channel *channel) { 
  // TO-DO: Modify getThrottleData function to receive two channels and read from both 
  int16_t position = INT16_MAX;
  ads1015_read_raw(storage, *channel, &position);

  LOG_DEBUG("Throttle: %d", position);

  int16_t mapped_value = 419.67*(position - 297); 
  LOG_DEBUG("Mapped Value: %d", mapped_value); 
  return mapped_value;
  // if (position > (3.14 / 4)) {
  //   event_raise(PEDAL_BRAKE_FSM_EVENT_PRESSED, 1);
  // } else {
  //   event_raise(PEDAL_BRAKE_FSM_EVENT_RELEASED, 0);
  // }
}