#include "lock.h"
#include "pin_defs.h"
#include "Arduino.h"

//--------------------------------------

HardwareTimer *MyTimer = new HardwareTimer(TIM2);  // Wahl des Timer

//-------------------------------------


void setup_TIM2()
{
  // Konfiguriere den Timer, aber starte ihn noch nicht
  MyTimer->setOverflow(5000000, MICROSEC_FORMAT);  // Timer für 5 Sekunden

  MyTimer->attachInterrupt(TimerCallback); // Callback-Funktion zuweisen
}


void TimerCallback() 
{
  // Schalte den Pin auf LOW nach 5 Sekunden
  digitalWrite(MAGNET_LOCK, LOW);

  // Stoppe den Timer, bis der Taster erneut gedrückt wird
  MyTimer->pause();
}

void openDoor()
{
  // Taster wurde gedrückt, also schalte den Pin auf HIGH
  digitalWrite(MAGNET_LOCK, HIGH);

  // Starte den Timer, um nach 5 Sekunden den Pin wieder auszuschalten
  MyTimer->resume();
}

