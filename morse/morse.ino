#include<morse_lib.h>//bibliothèque servant pour la traduction caractère <-> morse
#include "Menu.h"
#include "encoder.h"
#include "functionnalities.h"
#include "define.h"

Menu menu;

void setup() {
  // put your setup code here, to run once:
  //Serial link speed initialisation, required for "Serial.print()"
  Serial.begin(9600);
  lcd.begin(16, 2);
  bouton.attach(BUTTPIN,INPUT_PULLUP);
  morse_bouton.attach(buttonMorsePin,INPUT_PULLUP);
  pinMode(LEDPIN,OUTPUT);
  pinMode(ROTPIN,INPUT);
  pinMode(LIGHT_RECEP_PIN,INPUT);
  pinMode(LASER_PIN,OUTPUT);
  
  menu = setupmenu();
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  menu.loop();
  delay(2);
}
