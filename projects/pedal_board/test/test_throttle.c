#include "throttle.h"
<<<<<<< HEAD

#include "ads1015.h"
=======
#include "ads1015.h"
#include "event_queue.h"
>>>>>>> 5d5aa94fb8e673ab624420273fc1d6808257da11
#include "gpio.h"
#include "gpio_it.h"
#include "i2c.h"
#include "interrupt.h"
#include "log.h"
<<<<<<< HEAD
#include "soft_timer.h"
#include "unity.h"
#include "event_queue.h"
#include "pedal_events.h"
=======
#include "pedal_events.h"
#include "soft_timer.h"
#include "unity.h"
>>>>>>> 5d5aa94fb8e673ab624420273fc1d6808257da11

static ThrottleStorage throttle_storage;
static Ads1015Storage ads1015_storage;

void setup_test(void) {
  gpio_init();
  interrupt_init();
  soft_timer_init();
  gpio_it_init();
<<<<<<< HEAD
  event_queue_init(); 
  
=======
  event_queue_init();

>>>>>>> 5d5aa94fb8e673ab624420273fc1d6808257da11
  // I2CSettings i2c_settings = {
  //   .speed = I2C_SPEED_FAST,
  //   .scl = { .port = GPIO_PORT_B, .pin = 5 },
  //   .sda = { .port = GPIO_PORT_B, .pin = 5 },  // Need to change later
  // };

  // i2c_init(I2C_PORT_2, &i2c_settings);
  // GpioAddress ready_pin = { .port = GPIO_PORT_B, .pin = 2 };

  // // Intialize ADS1015
  // ads1015_init(&ads1015_storage, I2C_PORT_2, ADS1015_ADDRESS_GND, &ready_pin);
}

void teardown_test(void) {}

// void test_throttle_module_should_intialize_properly(void) {
//   TEST_ASSERT_EQUAL(STATUS_CODE_OK, throttle_init(&throttle_storage));
// }

// void test_throttle_should_be_enabled(void) {
//   TEST_ASSERT_EQUAL(STATUS_CODE_OK, throttle_enable(&throttle_storage));
// }

void test_private_callback_should_raise_events(void) {
<<<<<<< HEAD
  throttle_init(&throttle_storage); 
  Event e = { 0 }; 
  
  while(!status_ok(event_process(&e))) {
  }
  TEST_ASSERT_EQUAL(PEDAL_EVENT_THROTTLE_READING, e.id); 
}

void test_throttle_should_be_disabled(void) {
  throttle_init(&throttle_storage); 
  TEST_ASSERT_EQUAL(STATUS_CODE_OK, throttle_disable(&throttle_storage));
}

#include "soft_timer.h" 

static ThrottleStorage throttle_storage;  
=======
  throttle_init(&throttle_storage);
  Event e = { 0 };

  while (!status_ok(event_process(&e))) {
  }
  TEST_ASSERT_EQUAL(PEDAL_EVENT_THROTTLE_READING, e.id);
}

void test_throttle_should_be_disabled(void) {
  throttle_init(&throttle_storage);
  TEST_ASSERT_EQUAL(STATUS_CODE_OK, throttle_disable(&throttle_storage));
}
>>>>>>> 5d5aa94fb8e673ab624420273fc1d6808257da11
