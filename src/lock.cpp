#include "lock.h"
#include "pin_defs.h"
#include "Arduino.h"

//--------------------------------------
HardwareTimer *MyTimer = new HardwareTimer(TIM2);  // Wähle den Timer, z.B. TIM1

bool pinStatus = false;    // Zustand des Ausgangspins
//-------------------------------------


void setup_TIM2()
{
// Konfiguriere den Timer, aber starte ihn noch nicht
MyTimer->setOverflow(5000000, MICROSEC_FORMAT);  // Timer für 10 Sekunden
MyTimer->attachInterrupt(TimerCallback); // Callback-Funktion zuweisen
}


void TimerCallback() 
{
  // Schalte den Pin auf LOW nach 10 Sekunden
  digitalWrite(LED_BLUE_MAGNET_LOCK, LOW);
  pinStatus = false;  // Pin ist wieder auf LOW

  // Stoppe den Timer, bis der Taster erneut gedrückt wird
  MyTimer->pause();
}

void openDoor()
{
  // Taster wurde gedrückt, also schalte den Pin auf HIGH
  digitalWrite(LED_BLUE_MAGNET_LOCK, HIGH);
  pinStatus = true;  // Merke, dass der Pin jetzt auf HIGH ist
 
  // Starte den Timer, um nach 10 Sekunden den Pin wieder auszuschalten
  MyTimer->resume();
}

