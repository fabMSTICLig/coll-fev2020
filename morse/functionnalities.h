#ifndef FUNCTIONNALITIES
#define FUNCTIONNALITIES

#include "define.h"
#include "WString.h"
#include <Bounce2.h>
#include <morse_lib.h>


struct PreviousState;

//** Function that check if the 'morse-button' is pressed/released **//
// It identifies : '.' for short press ; '-' for long press ; ' ' for interword ; '|' for inter-letter
// It uses previous known button state and pressed-time to works.  
char button_read(PreviousState& button, Bounce& morse_button);

char light_sensor_read(PreviousState light);

String decode_message(String& m);


bool readReceivedMessage(int enc, bool but);

/**
 * take a character, translate it into morse and send the code in pulse to an arduino pin. 
 */
void led_unit_blink(char elm, int pin);

/**
 * Takes a valid String, and diffuses each character morse representation with a laser. 
 */
void laser_recep(String str);
#endif
