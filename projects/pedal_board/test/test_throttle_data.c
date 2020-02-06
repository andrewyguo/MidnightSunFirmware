#include "throttle.h"

#include "ads1015.h"
#include "event_queue.h"
#include "gpio.h"
#include "gpio_it.h"
#include "i2c.h"
#include "interrupt.h"
#include "log.h"
#include "pedal_events.h"
#include "soft_timer.h"
#include "throttle.h"
#include "unity.h"

static ThrottleStorage throttle_storage;
static Ads1015Storage ads1015_storage;

void setup_test(void) {
    gpio_init();
    interrupt_init();
    soft_timer_init();
    gpio_it_init();
    
    I2CSettings i2c_settings = {
        .speed = I2C_SPEED_FAST,                    
        .scl = { .port = GPIO_PORT_B, .pin = 10 },  
        .sda = { .port = GPIO_PORT_B, .pin = 11 }, 
    };
    i2c_init(I2C_PORT_2, &i2c_settings);
    GpioAddress ready_pin = { .port = GPIO_PORT_B, .pin = 2 };  
    ads1015_init(&ads1015_storage, I2C_PORT_2, ADS1015_ADDRESS_GND, &ready_pin);

    // pedal_data_tx_init(&ads1015_storage);

}

void teardown_test(void) {}

void test_throttle_data_should_intialize(void){
    TEST_ASSERT_EQUAL(STATUS_CODE_OK, throttle_init(&throttle_storage, &ads1015_storage)); 
} 
