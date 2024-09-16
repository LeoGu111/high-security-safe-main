#ifndef LOCK_H
#define LOCK_H

#include "HardwareTimer.h"

void setup_TIM2();
void TimerCallback();
void openDoor();




//extern void digitalWrite(uint32_t, uint32_t);
//extern int LOW;
//extern const int LED_BLUE_MAGNET_LOCK;  // Deklaration als extern

#endif // LOCK_H