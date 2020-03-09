#include "Menu.h"

void Menu::loop()
{
  bouton.update();
  int enc=getIncRot(lposrot, ROTPIN);
  bool but = bouton.fell();
  if(but || (enc && enc!=127))
  {
    if(!layer1In)
    {
      if(enc)
      {
        layer1+=(enc+numItem); //avoid to obtain -x when mod computed
        layer1%=numItem;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(menuitems[layer1].name);
      }else if(but)
      {
        Serial.println(F("Enter Layer1"));
        layer1In=true;
        layer2In=false;
        layer2=0;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(menuitems[layer1].name);
        delay(2);
        lcd.setCursor(0, 1);
        lcd.print(menuitems[layer1].submenus[0].name);
      }
    }else
    {
      if(!layer2In)
      {
        if(enc)
        {
          layer2+=enc+menuitems[layer1].numItem+1;
          layer2%=menuitems[layer1].numItem+1;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print(menuitems[layer1].name);
          delay(2);
          lcd.setCursor(0, 1);
          if(layer2<menuitems[layer1].numItem)
          {
            lcd.print(menuitems[layer1].submenus[layer2].name);
          }
          else
          {
            lcd.print(F("Retour"));
          }
        }else if(but)
        {
          
          if(layer2==menuitems[layer1].numItem)
          {
            layer1In=false;
            lcd.clear();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(menuitems[layer1].name);
          }
          else
          {
            layer2In=true;
            
            lcd.clear();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(menuitems[layer1].submenus[layer2].name);
            delay(2);
            lcd.setCursor(0, 1);
            menuitems[layer1].submenus[layer2].cbaff();
            if(menuitems[layer1].submenus[layer2].autoRun){
              menuitems[layer1].submenus[layer2].cbopt(enc,but);
              layer2In=false;
              lcd.clear();
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print(menuitems[layer1].name);
              delay(2);
              lcd.setCursor(0, 1);
              lcd.print(menuitems[layer1].submenus[layer2].name);
            }
          }
        }
      }else
      {
        if(menuitems[layer1].submenus[layer2].cbopt(enc,but))
        {
          layer2In=false;
          lcd.clear();
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print(menuitems[layer1].name);
          delay(2);
          lcd.setCursor(0, 1);
          lcd.print(menuitems[layer1].submenus[layer2].name);
        }else
        {
          lcd.clear();
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print(menuitems[layer1].submenus[layer2].name);
          delay(2);
          lcd.setCursor(0, 1);
          menuitems[layer1].submenus[layer2].cbaff();
        }
      }
    }
  }
}

Menu setupmenu(){
  Menu menu;
  
  SubMenuItem ditmenu;
  ditmenu.name=("Dit duree");
  ditmenu.cbopt=confDit;
  ditmenu.cbaff=confDitAff;
  
  SubMenuItem lettremenu;
  lettremenu.name=("Inter Lettre");
  lettremenu.cbopt=conflettre;
  lettremenu.cbaff=conflettreAff;

  MenuItem confMenu;
  confMenu.name=("Configuration");
  confMenu.submenus[0]=ditmenu;
  confMenu.submenus[1]=lettremenu;
  confMenu.numItem=2;

  
  SubMenuItem inputLightmenu;
  inputLightmenu.name=("Lumiere");
  inputLightmenu.cbopt=inputLight;
  inputLightmenu.cbaff=inputLightAff;
  inputLightmenu.autoRun=true;

  SubMenuItem readReceivedMessagemenu;
  readReceivedMessagemenu.name=("Lecture");
  readReceivedMessagemenu.cbopt=readReceivedMessage;
  readReceivedMessagemenu.cbaff=readReceivedMessageAff;
  readReceivedMessagemenu.autoRun=true;
  

  MenuItem entreemenu;
  entreemenu.name=("Reception");
  entreemenu.submenus[0]=inputLightmenu;
  entreemenu.submenus[1]=readReceivedMessagemenu;
  entreemenu.numItem=3;

  
  SubMenuItem sendInputmenu;
  sendInputmenu.name=("Message");
  sendInputmenu.cbopt=sendInput;
  sendInputmenu.cbaff=sendInputAff;

  
  SubMenuItem inputButtmenu;
  inputButtmenu.name=("Bouton");
  inputButtmenu.cbopt=inputButt;
  inputButtmenu.cbaff=inputButtAff;
  inputButtmenu.autoRun=true;
  
  SubMenuItem sendLummenu;
  sendLummenu.name=("Lumiere");
  sendLummenu.cbopt=sendLum;
  sendLummenu.cbaff=sendLumAff;
  sendLummenu.autoRun=true;

  SubMenuItem inputErasemenu;
  inputErasemenu.name=("Message Suppr");
  inputErasemenu.cbopt=sendErase;
  inputErasemenu.cbaff=sendEraseAff;
  inputErasemenu.autoRun=true;
  
  MenuItem sendmenu;
  sendmenu.name=("Envoi");
  sendmenu.submenus[0]=sendInputmenu;
  sendmenu.submenus[1]=inputButtmenu;
  sendmenu.submenus[2]=sendLummenu;
  sendmenu.submenus[3]=inputErasemenu;
  sendmenu.numItem=4;

  menu.menuitems[0]=confMenu;
  menu.menuitems[1]=entreemenu;
  menu.menuitems[2]=sendmenu;
  menu.numItem=3;
  return menu;
}



///***Functions used by LCD menu***///
//Operationnal functions
bool confDit(int enc, bool but)
{
  if(enc != 0) morse_timing.UNIT_LENGTH+=enc;
  return but;
}
bool conflettre(int enc, bool but)
{
  if(enc != 0) morse_timing.ELM_SEP_UNITS+=enc;
  return but;
}

bool inputButt(int enc, bool but)
{
  char c;
  message_to_send = "";
  messageIndex = 0;
  PreviousState button_state;
  button_state.t = millis();
  button_state.value = 1;
  while(millis()-button_state.t < 5000){
  c = button_read(button_state, morse_bouton);
    if(c!='\n')
      message_to_send+=c;
  }
  Serial.println(message_to_send);
  message_to_send = decode_message(message_to_send);
  Serial.println(message_to_send);
  return but;
}

bool inputLight(int enc, bool but)
{
  char c;
  message_received = "";
  PreviousState sensor_state;
  sensor_state.t = millis();
  sensor_state.value = 0;
  while(millis()- sensor_state.t < 5000){
    c = light_sensor_read(sensor_state);
    if(c!='\n')
      message_received+=c;
  }
  String last_char = "";
  String message_t = "";
  message_received += " ";
  for (int i=0 ; i<message_received.length() ; i++) {
      if (message_received[i] != ' ' && message_received[i] != '|') {
          last_char = last_char+message_received[i];
      } else if (message_received[i] == '|') {
          char c = getCharOf(last_char);
          message_t = message_t+c;
          last_char ="";
      } else {
          char c = getCharOf(last_char);
          message_t = message_t+c+' ';
          last_char = "";
      }
  }
  message_received = message_t;
  Serial.println("message");
  Serial.println(message_received);
  return but;
}

/**
 * Function called by the Menu
 * It calls a function from "functionnalities.h"
 * The goal is to use the laser of the box to send morse informations
 */
bool sendLum(int enc, bool but)
{
  laser_recep(message_to_send);
  return true;
}

/**
 * Allows to select a message for morse sending by using encoder. 
 */
bool sendInput(int enc, bool but)
{
  if(message_to_send.length()==0) message_to_send+=" ";
  char l = message_to_send[messageIndex];
  if(l==' ' && but) return true;
  if(but)
  {
    message_to_send+=" ";
    messageIndex++;
  }
  if(enc!=0)
  {
    if(l==' ' && enc>0)
    {
      l='A';
      enc--;
    }
    l+=enc;
    if(l<'A') l = ' ';
    message_to_send[messageIndex]=l;
  }
  return false;
}


/**
 * Erase the message to send. 
 */
bool sendErase(int enc, bool but)
{
  delay(1000);
  message_to_send = "";
  messageIndex = 0;
  return true;
}

//Printing functions
void confDitAff()
{
  lcd.setCursor(0, 1);
  lcd.print((int)morse_timing.UNIT_LENGTH);
}
void conflettreAff(){
  lcd.setCursor(0, 1);
  lcd.print((int)morse_timing.ELM_SEP_UNITS);
}
void inputButtAff(){
  lcd.setCursor(0, 1);
  lcd.print(F("Input Butt"));
}
void inputLightAff(){
  lcd.setCursor(0, 1);
  lcd.print(F("Reception..."));
}

void readReceivedMessageAff(){
  lcd.setCursor(0, 1);
  lcd.print(message_received);
}
void sendInputAff(){
  lcd.setCursor(0, 1);
  lcd.print(message_to_send);
}
void sendLumAff(){
  lcd.setCursor(0, 1);
  lcd.print(F("Sending ..."));
  
}
void sendEraseAff(){
  lcd.setCursor(0, 0);
  lcd.print(F("Suppression :"));
  lcd.setCursor(0, 1);
  lcd.print(message_to_send);
}
///******************************************///
