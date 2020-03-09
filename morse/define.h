#ifndef HEADER_BOITE
#define HEADER_BOITE

#include <rgb_lcd.h>
#include <Bounce2.h>
#include <morse_lib.h>

#define LIGHT_LIM 666

//Define used pins
#define ROTPIN A2
#define BUTTPIN A1
#define buttonMorsePin 5     // the number of the pushbutton pin
#define LEDPIN 4     // the number of the LED pin
#define LASER_PIN 8     // the number of the LED pin
#define LIGHT_RECEP_PIN A0     // the number of the LED pin

struct PreviousState {
  int value;
  unsigned long t;
};

struct Timing {
  int UNIT_LENGTH;
  int ELM_SEP_UNITS;
  int WORD_SEP_UNITS;
};

extern rgb_lcd lcd;
extern Bounce bouton;
extern Bounce morse_bouton;
extern int lposrot;
extern Timing morse_timing;
extern String message_to_send;
extern int messageIndex;
extern String message_received;


#endif
