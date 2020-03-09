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


//String morse_decode(String string){
//  String morse_element = "";
//  String result = "";
//  for(int i = 0 ; i < string.length(); i++){
//    if(string[i] == theMap.getLetterSeparator()){
//      result += theMap.getCharOf(morse_element);
//      morse_element = "";
//    }else if(string[i] == theMap.getWordSeparator()){
//      result += theMap.getCharOf(morse_element);
//      morse_element = "";
//      result += ' ';
//    }else{
//      morse_element += string[i];
//    }
//  }
//  if(morse_element.length() > 0)
//    result += theMap.getCharOf(morse_element);
//  return result;
//}
//
//String morse_encode(String message_in_clear){
//  String res = "";
//  for(int i = 0 ; i < message_in_clear.length(); i++){
//    if(message_in_clear[i] == ' '){
//      res += theMap.getWordSeparator();
//    }else{
//      res += theMap.getCodeOf(message_in_clear[i]);
//      if(i<message_in_clear.length()-1 && message_in_clear[i+1] != ' ')
//        res += theMap.getLetterSeparator();
//    }
//  }
//  return res;
//}



// #define MORSE_MAP_SIZE 47
//
// struct MorseEquivalence {
//   char element;
//   char* code;
// };
//
// struct MorseMap {
//   const MorseEquivalence characterAndMorse[MORSE_MAP_SIZE+1] = {
//     { 'A', ".-" },{ 'B', "-..." },{ 'C', "-.-." },{ 'D', "-.." },
//     { 'E', "." },{ 'F', "..-." },{ 'G', "--." },{ 'H', "...." },
//     { 'I', ".." },{ 'J', ".---" },{ 'K', "-.-" },{ 'L', ".-.." },
//     { 'M', "--" },{ 'N', "-." },{ 'O', "---" },{ 'P', ".--." },
//     { 'Q', "--.-" },{ 'R', ".-." },{ 'S', "..." },{ 'T', "-" },
//     { 'U', "..-" },{ 'V', "...-" },{ 'W', ".--" },{ 'X', "-..-" },
//     { 'Y', "-.--" },{ 'Z', "--.." }, //26 éléments
//
//     { '0', "-----" },{ '1', ".----" },{ '2', "..---" },{ '3', "...--" },
//     { '4', "....-" },{ '5', "....." },{ '6', "-...." },{ '7', "--..." },
//     { '8', "---.." },{ '9', "----." }, //10 éléments
//
//     { '.', ".-.-.-" },{ ',', "--..--" },{ '?', "..--.." },{ '&', ".-..." },
//     { '!', "-.-.--" },{ ':', "---..." },{ ';', "-.-.-." },{ '(', "-.--." },
//     { ')', "-.--.-" },{ '"', ".-..-." },{ '@', ".--.-." }, //11 éléments
//
//     {'\0',""}//in case of null MorseEquivalence
//   };
//   const short tab_length = MORSE_MAP_SIZE;
//   const char letter_separator = '|';
//   const char word_separator = ' ';
//
//   const MorseEquivalence& operator[](int index) const;
//
//   // const String& getCodeOf(char elm) const;
//   inline const char* MorseMap::getCodeOf(char elm) const {
//     if(isAlpha(elm)){
//       Serial.print("oki : ");
//       Serial.println(characterAndMorse[(int)((int)(toupper(elm))-(int)('A'))].code);
//       return characterAndMorse[(int)(toupper(elm))-(int)('A')].code;
//     }else if(isDigit(elm)){
//       return characterAndMorse[(int)elm-(int)('0')].code;
//     }else{
//       for(int i = 36 ; i < tab_length ; i++){
//         if(characterAndMorse[i].element == elm)
//           return characterAndMorse[i].code;
//       }
//     }
//     return "";
//   }
//   const char& getCharOf(String morse_code) const;
//
//   const char getLetterSeparator();
//
//   const char getWordSeparator();
// };
// //
// //
// // String morse_decode(String string);
// //
// // String morse_encode(String message_in_clear);

#endif
