#include <rgb_lcd.h>
#include <morse_lib.h>
#include <Servo.h>


// constants won't change. They're used here to set pin numbers:
const int buttonPin = 5;     // the number of the pushbutton pin
const int buttonPin2 = 6;
const int ledPinFermer =  2;      // the number of the LED pin
const int ledPinOuvert =  3;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
String lettremorse = "";
String mot = "";
String motdepasse = "TEST";
int nb = 0;
bool change=false;

unsigned long temps=0;


Servo myservo;

rgb_lcd ecran;

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPinFermer, OUTPUT);
  pinMode(ledPinOuvert, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  
  myservo.attach(7);
  myservo.write(60);
  ecran.begin(16,2);
}

void loop() {
  change=false;
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW){
    temps=millis();
    lettremorse+=".";  
    change=true; 
    delay(300);         
  }

  if (buttonState2 == LOW){
    temps=millis();
    lettremorse+="-";  
    change=true; 
    delay(300);
  }

  if((millis()-temps )>=5000 && mot!="")
  {
    if(mot==motdepasse)
    {

      ecran.clear();
      ecran.print("OUVERT");
      myservo.write(20);
      digitalWrite(ledPinFermer,HIGH);
      while(true)delay(10000);
    }
    else
    {
      ecran.clear();
      ecran.print("ERREUR");
      digitalWrite(ledPinOuvert,HIGH);
    }
    delay(5000);
      digitalWrite(ledPinFermer,LOW);
      digitalWrite(ledPinOuvert,LOW);
    ecran.clear();
    lettremorse="";
    mot="";
  }
  else if ((millis()-temps )>=2000){
    if(lettremorse.length()>8)lettremorse="";
    char c = getCharOf(lettremorse);
    if(c!='\0')
    {  
      lettremorse="";
      mot+=c;  
      change=true; 
    }
  }
  if(change)
  {
    ecran.clear();
    ecran.setCursor(0,0);
    ecran.print(mot);
    ecran.setCursor(0,1);
    ecran.print(lettremorse);
  }
  
}
