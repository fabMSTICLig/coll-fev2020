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

//
//
//   const MorseEquivalence& MorseMap::operator[](int index) const {
//     if(index >= 0 && index < tab_length)
//       return characterAndMorse[index];
//     return characterAndMorse[MORSE_MAP_SIZE];
//   }
//
//
//
//   const char& MorseMap::getCharOf(String morse_code) const {
//     for(int i = 0 ; i < tab_length ; i++){
//       if(morse_code == characterAndMorse[i].code)
//         return characterAndMorse[i].element;
//     }
//     return '\0';
//   }
//
//   const char MorseMap::getLetterSeparator(){
//     return letter_separator;
//   }
//   const char MorseMap::getWordSeparator(){
//     return word_separator;
//   }
// //
//
// String morse_decode(String string){
//   String morse_element = "";
//   String result = "";
//   for(int i = 0 ; i < string.length(); i++){
//     if(string[i] == theMap.getLetterSeparator()){
//       result += theMap.getCharOf(morse_element);
//       morse_element = "";
//     }else if(string[i] == theMap.getWordSeparator()){
//       result += theMap.getCharOf(morse_element);
//       morse_element = "";
//       result += ' ';
//     }else{
//       morse_element += string[i];
//     }
//   }
//   if(morse_element.length() > 0)
//     result += theMap.getCharOf(morse_element);
//   return result;
// }
//
// String morse_encode(String message_in_clear){
//   String res = "";
//   for(int i = 0 ; i < message_in_clear.length(); i++){
//     if(message_in_clear[i] == ' '){
//       res += theMap.getWordSeparator();
//     }else{
//       res += theMap.getCodeOf(message_in_clear[i]);
//       if(i<message_in_clear.length()-1 && message_in_clear[i+1] != ' ')
//         res += theMap.getLetterSeparator();
//     }
//   }
//   return res;
// }



//
// void setup() {
//   Serial.begin(9600);
//
// }
//
// void loop() {
//   char c_buffer;
//   String s_buffer;
//   for (byte k = 0; k < strlen_P(elements); k++) {
//     c_buffer = getCharAt(k);
//     s_buffer = getMorseAt(k);
//     Serial.print("[by index ] -> ");
//     Serial.print(c_buffer);
//     Serial.print(" : ");
//     Serial.println(s_buffer);
//     c_buffer = getCharAt(k);
//     s_buffer = getMorseAt(k);
//     Serial.print("[by element ] -> ");
//     Serial.print(getMorseOf(c_buffer));
//     Serial.print(" : ");
//     Serial.println(getCharOf(s_buffer));
//   }
//   while(true)
//     delay(10);
// }
