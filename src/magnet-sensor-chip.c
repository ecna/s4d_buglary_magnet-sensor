// Wokwi Custom Chip - For information and examples see:
// https://link.wokwi.com/custom-chips-alpha
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2022 Uri Shaked / wokwi.com

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

    // Define the range
const float JITTER_LOW = 0.0;
const float JITTER_HIGH = 0.05;

float getRandomJitter(float min, float max) {
    // Generate a random integer and cast it to float
    float random_float = (float)rand();
    
    // Normalize the number to the range [0, 1]
    // RAND_MAX is the maximum value returned by rand()
    float normalized_float = random_float / (float)RAND_MAX;
    
    // Scale the normalized number to the desired range [min, max]
    return min + normalized_float * (max - min);
}

typedef struct {
  pin_t pin_out;
  uint32_t voltage_attr;
} chip_state_t;

static void chip_timer_event(void *user_data);

void chip_init(void) {
  chip_state_t *chip = malloc(sizeof(chip_state_t));
  chip->pin_out = pin_init("OUT", ANALOG);
  chip->voltage_attr = attr_init_float("voltage", 2.5);

  const timer_config_t timer_config = {
    .callback = chip_timer_event,
    .user_data = chip,
  };
  timer_t timer_id = timer_init(&timer_config);
  timer_start(timer_id, 1000, true);
}

void chip_timer_event(void *user_data) {
  chip_state_t *chip = (chip_state_t*)user_data;
  float jitter = getRandomJitter(JITTER_LOW,JITTER_HIGH);
  float voltage = attr_read_float(chip->voltage_attr);
  pin_dac_write(chip->pin_out, voltage + jitter);
}