
#include <IRremote.h>
#include <Servo.h>
#define SERVO_PIN 7
#define SERVO2_PIN 8
#define IR_PIN 4

#include <Adafruit_NeoPixel.h>

#define PHARE_PIN 6
#define NUMPIXELS 2
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PHARE_PIN, NEO_GRB + NEO_KHZ800);
#if defined (__AVR_ATtiny85__)
 if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
 


Servo myservo;
Servo myservo2;
   

void avance(){
  myservo.write(180);
  myservo2.write(0);
}
void reculer(){
  myservo.write(0);
  myservo2.write(180);
}
void gauche(){ 
  myservo.write(90);
  myservo2.write(0);
}
void droite(){
  myservo.write(180);
  myservo2.write(90);
}
void stop(){
  myservo.write(90);
  myservo2.write(90);
}
int pos = 0;

IRrecv irrecv(IR_PIN);

decode_results results;

void setup(){
  Serial.begin(9600);
  myservo.attach(SERVO_PIN);  
  myservo2.attach(SERVO2_PIN);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
  pixels.begin();

  pixels.setPixelColor(0,240,255,255);
  pixels.setPixelColor(1,240,255,255);
 
  pixels.show(); 

  
  myservo.write(90);
  myservo2.write(90);
}

void loop() {
  if (irrecv.decode(&results)) {
    
    Serial.println(results.value);
    if( results.value == (0xFF629D)) {
      avance();  
    }
    if( results.value == (0xFFA857)) {
      reculer();  
    }
    if( results.value == (0xFFC23D)) {
      droite();  
    }
    if( results.value == (0xFF22DD)) {
      gauche();  
    }
    if( results.value == (0xFF02FD)) {
      stop();  
    }
    irrecv.resume();
  }
}

  

  

  

  
