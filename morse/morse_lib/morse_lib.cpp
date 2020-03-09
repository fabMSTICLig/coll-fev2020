#include <Arduino.h>
#include <avr/pgmspace.h>
#include "morse_lib.h"

const char getLetterSeparator(){
  return letter_separator;
}

const char getWordSeparator(){
  return word_separator;
}

char getCharAt(int pos){
  return pgm_read_byte_near(elements + pos);
}
char getCharOf(String s){
  char res ='\0';
  if(s.length() < 8 && s.length() > 0){
    char s_buffer[8];
    for(int i = 0 ; i < tab_length ; i++){
      strcpy_P(s_buffer, (char *)pgm_read_word(&(morse_list[i])));  // Necessary casts and dereferencing, just copy.
      if(String(s_buffer) == s){
        res = getCharAt(i);
        break;
      }
    }
  }
  return res;
}

String getMorseAt(int pos){
  char s_buffer[8];
  strcpy_P(s_buffer, (char *)pgm_read_word(&(morse_list[pos])));  // Necessary casts and dereferencing, just copy.
  return String(s_buffer);
}
String getMorseOf(char c){
  if(isAlpha(c)){
    return getMorseAt((int)(toupper(c))-(int)('A'));
  }else if(isDigit(c)){
    return getMorseAt((int)c-(int)('0')+26);
  }else{
    for(int i = 36 ; i < tab_length ; i++){
      if(getCharAt(i) == c)
          return getMorseAt(i);
    }
  }
  return "";
}
