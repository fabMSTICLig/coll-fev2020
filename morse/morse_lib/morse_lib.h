#ifndef MORSE_LIB_H
#define MORSE_LIB_H

#include <Arduino.h>
#include <avr/pgmspace.h>


//Define Default morse values
#define D_UNIT_LENGTH 200 //ms
#define D_ELM_SEP_UNITS 5 //dit
#define D_WORD_SEP_UNITS 7 //dit

#define MORSE_MAP_SIZE 47

const char elements[] PROGMEM = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?&!:;()\"@";

const char morse_A[] PROGMEM = ".-";
const char morse_B[] PROGMEM = "-...";
const char morse_C[] PROGMEM = "-.-.";
const char morse_D[] PROGMEM = "-..";
const char morse_E[] PROGMEM = ".";
const char morse_F[] PROGMEM = "..-.";
const char morse_G[] PROGMEM = "--.";
const char morse_H[] PROGMEM = "....";
const char morse_I[] PROGMEM = "..";
const char morse_J[] PROGMEM = ".---";
const char morse_K[] PROGMEM = "-.-";
const char morse_L[] PROGMEM = ".-..";
const char morse_M[] PROGMEM = "--";
const char morse_N[] PROGMEM = "-.";
const char morse_O[] PROGMEM = "---";
const char morse_P[] PROGMEM = ".--.";
const char morse_Q[] PROGMEM = "--.-";
const char morse_R[] PROGMEM = ".-.";
const char morse_S[] PROGMEM = "...";
const char morse_T[] PROGMEM = "-";
const char morse_U[] PROGMEM = "..-";
const char morse_V[] PROGMEM = "...-";
const char morse_W[] PROGMEM = ".--";
const char morse_X[] PROGMEM = "-..-";
const char morse_Y[] PROGMEM = "-.--";
const char morse_Z[] PROGMEM = "--..";
const char morse_0[] PROGMEM = "-----";
const char morse_1[] PROGMEM = ".----";
const char morse_2[] PROGMEM = "..---";
const char morse_3[] PROGMEM = "...--";
const char morse_4[] PROGMEM = "....-";
const char morse_5[] PROGMEM = ".....";
const char morse_6[] PROGMEM = "-....";
const char morse_7[] PROGMEM = "--...";
const char morse_8[] PROGMEM = "---..";
const char morse_9[] PROGMEM = "----.";
const char morse_p[] PROGMEM = ".-.-.-";
const char morse_v[] PROGMEM = "--..--";
const char morse_pi[] PROGMEM = "..--..";
const char morse_esp[] PROGMEM = ".-...";
const char morse_pe[] PROGMEM = "-.-.--";
const char morse_dp[] PROGMEM = "---...";
const char morse_pv[] PROGMEM = "-.-.-.";
const char morse_par_o[] PROGMEM = "-.--.";
const char morse_par_f[] PROGMEM = "-.--.-";
const char morse_g[] PROGMEM = ".-..-.";
const char morse_aro[] PROGMEM = ".--.-.";

const char* const morse_list[] PROGMEM =
  { morse_A,morse_B,morse_C,morse_D,morse_E,morse_F,
    morse_G,morse_H,morse_I,morse_J,morse_K,morse_L,
    morse_M,morse_N,morse_O,morse_P,morse_Q,morse_R,
    morse_S,morse_T,morse_U,morse_V,morse_W,morse_X,
    morse_Y,morse_Z,morse_0,morse_1,morse_2,morse_3,
    morse_4,morse_5,morse_6,morse_7,morse_8,morse_9,
    morse_p,morse_v,morse_pi,morse_esp,morse_pe,morse_dp,
    morse_pv,morse_par_o,morse_par_f,morse_g,morse_aro };

const short tab_length = MORSE_MAP_SIZE;
const char letter_separator = '|';
const char word_separator = ' ';

const char getLetterSeparator();
const char getWordSeparator();

char getCharAt(int pos);
char getCharOf(String s);

String getMorseAt(int pos);
String getMorseOf(char c);

#endif
