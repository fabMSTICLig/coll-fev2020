#include "define.h"

rgb_lcd lcd;
Bounce bouton = Bounce();
Bounce morse_bouton = Bounce();
int lposrot = 0;
Timing morse_timing = {D_UNIT_LENGTH,D_ELM_SEP_UNITS,D_WORD_SEP_UNITS};
String message_to_send = "";
int messageIndex = 0;
String message_received = "";
