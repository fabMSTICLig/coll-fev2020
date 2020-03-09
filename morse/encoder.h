#ifndef ENCODER_READ
#define ENCODER_READ

#include <Arduino.h>
#define COMP(V,I,A) (V>=I && V<=A)

int getIncRot(int& lposrot, int pin);

#endif
