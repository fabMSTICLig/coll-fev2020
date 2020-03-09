#include "functionnalities.h"

/**
 * input : PreviousState - (value ; time) of last interaction with the button. Bounce - A button. 
 * output : a character . / - / ' ' ; depending of time between to press. 
 */
char button_read(PreviousState& button, Bounce& morse_button){
  morse_button.update();
  int buttonState = morse_button.read();
  char res = '\n'; //Prevent to return uninitialized value
  if(buttonState != button.value){
    unsigned long t = millis();
    if(buttonState == 1){ //button released
      if(t-button.t < morse_timing.UNIT_LENGTH){
        res = '.';
      }else{
        res = '-';
      }
    }else{
        if(t-button.t > morse_timing.WORD_SEP_UNITS*morse_timing.UNIT_LENGTH){
          res = word_separator;
      }else if(t-button.t > morse_timing.ELM_SEP_UNITS*morse_timing.UNIT_LENGTH){
          res = letter_separator;
      }
    }
    button.t = millis();
  }
  button.value = buttonState;
  return res;
}

/**
 * Take an input string made of morse code ( ./-/' ') and return it in clear. 
 */
String decode_message(String& m){
  String message = "";
  String part = "";
  char c;
  m += ' ';
  for(int i = 0; i< m.length() ; i++){
    if(m[i] == letter_separator){
      c = getCharOf(part);
      message += c;
      part = "";
    }else if(m[i] == word_separator){
      c = getCharOf(part);
      message += ' ';
      message += c;
      part = "";
    }else{
      part += m[i];
    }
  }
  return message;
}

char light_sensor_read(PreviousState prev_light){
  int lightValue = analogRead(LIGHT_RECEP_PIN);
  char res = '\n'; //Prevent to return uninitialized value
  if((lightValue>LIGHT_LIM) != (prev_light.value>LIGHT_LIM)){
    
    unsigned long t = millis();
    if((lightValue<LIGHT_LIM)){ //button released
      if(t-prev_light.t < 1.1*morse_timing.UNIT_LENGTH){
        res = '.';
      }else{
        res = '-';
      }
    }else{
        if(t-prev_light.t > .9*morse_timing.WORD_SEP_UNITS*morse_timing.UNIT_LENGTH){
          res = ' ';
      }else if(t-prev_light.t > .9*morse_timing.ELM_SEP_UNITS*morse_timing.UNIT_LENGTH){
          res = '|';
      }
    }
    prev_light.t = millis();
  }
  prev_light.value = lightValue;
  return res;
}


///*** Functions for morse applications ***///
//Encode a string and send it using laser pointer
void laser_recep(String str){
  for(int i = 0; i < str.length(); i++){   
    if(str[i] != ' '){
      led_unit_blink(str[i],LASER_PIN);
      delay(morse_timing.ELM_SEP_UNITS*morse_timing.UNIT_LENGTH);
    }else{
      if(i < str.length()-1)
        delay(morse_timing.WORD_SEP_UNITS*morse_timing.UNIT_LENGTH);
    }
  }
}

//Transform a character into light pulse
void led_unit_blink(char elm, int pin){
  String sequence = getMorseOf(elm);
  for(int i = 0; i < sequence.length(); i++){  
    if(i>0)
      delay(morse_timing.UNIT_LENGTH); 
    if(sequence[i] == '.') {
      digitalWrite(pin, HIGH);
      delay(morse_timing.UNIT_LENGTH);
    }else if(sequence[i] == '-') {
      digitalWrite(pin, HIGH);
      delay(3*morse_timing.UNIT_LENGTH);
    }
    digitalWrite(pin, LOW);
  }
}

bool readReceivedMessage(int enc, bool but)
{
  for(int i = 0; i < message_received.length(); i++){   
    if(message_received[i] != ' '){
      led_unit_blink(message_received[i],LEDPIN);
      delay(morse_timing.ELM_SEP_UNITS*morse_timing.UNIT_LENGTH);
    }else{
      if(i < message_received.length()-1)
        delay(morse_timing.WORD_SEP_UNITS*morse_timing.UNIT_LENGTH);
    }
  }
  return true;
}
