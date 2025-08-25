#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <util/delay.h>
#include "led.h"
#include "seg7.h"

void setup() {
  LED_Init();
  SEG7_Init();
}

void loop() {
  // RED 15 sec
  LED_On(RED_LED_PIN);
  for (int i=15; i>0; i--) {
    for (int j=0; j<5; j++) SEG7_DisplayNumber(i);
  }
  LED_Off(RED_LED_PIN);

  // YELLOW 5 sec
  LED_On(YELLOW_LED_PIN);
  for (int i=5; i>0; i--) {
    for (int j=0; j<5; j++) SEG7_DisplayNumber(i);
  }
  LED_Off(YELLOW_LED_PIN);

  // GREEN 10 sec
  LED_On(GREEN_LED_PIN);
  for (int i=10; i>0; i--) {
    for (int j=0; j<5; j++) SEG7_DisplayNumber(i);
  }
  LED_Off(GREEN_LED_PIN);
}
