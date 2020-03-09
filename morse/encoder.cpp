#include "encoder.h"

int getIncRot(int& lposrot, int pin)
{
  int pos=127;
  int val = analogRead(pin);
  
  if(COMP(val,900,910)) //905
  {
    pos=0;
  } else if(COMP(val,792,802)) //797
  {
    pos = 1;
  } else if(COMP(val,683,693)) //688
  {
    pos = 2;
  } else if(COMP(val,578,587)) //582
  {
    pos = 3;
  } else if(COMP(val,473,483)) //478
  {
    pos = 4;
  } else if(COMP(val,375,385)) //380
  {
    pos = 5;
  } else if(COMP(val,283,293)) //288
  {
    pos = 6;
  } else if(COMP(val,191,201)) //196
  {
    pos = 7;
  }
  if(pos!=127)
  {
    val = pos - lposrot;
    if(val==-7) val =1;
    if(val==7) val =-1;
    lposrot = pos;
    return val;
  }
  return 127;
}
