 //-- MOTEUR A --
const int ENA=9; //Connecté à Arduino pin 9(sortie PWM)
const int IN1=4; //Connecté à Arduino pin 4
const int IN2=5; //Connecté à Arduino pin 5

//-- MOTEUR B --
const int ENB=10; //Connecté à Arduino pin 10(Sortie PWM)
const int IN3=6; //Connecté à Arduino pin 6
const int IN4=7; //Connecté à Arduino pin 7

//LEDs
const int LED_VERTE = 14;
const int LED_ROUGE = 15;
bool roule = false;

//bluetooth
char data;

#include <SoftwareSerial.h>
#define RX 2
#define TX 13

SoftwareSerial BlueTooth(RX, TX);


 void arriere(){
  //Marche arrière
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
 }

 void avant(){
  //Marche avant
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
 }
 

void vitesseNormale(){
  //Vitesse de croisière
  analogWrite(ENA, 100);
  analogWrite(ENB, 120);
}


void telecommande(){
    if(BlueTooth.available()){
    data = BlueTooth.read();
    
    if(roule){
      analogWrite(LED_VERTE, 0);
      analogWrite(LED_ROUGE, 255);
      Serial.println(data);
      if (data == 'G'){
        analogWrite(ENA, 180);
        analogWrite(ENB, 100);
      }
      if (data == 'D'){
        analogWrite(ENB, 180);
        analogWrite(ENA, 100);
        }
      if (data == 'S')roule = false;
      if (data == 'R'){
        arriere();
        vitesseNormale();
      }
      if (data == 'A'){
      avant();
      vitesseNormale();
      }
      
    }
    else{
      analogWrite(LED_VERTE, 255);
      analogWrite(LED_ROUGE, 0);
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
      if(data == 'G' || data == 'D' || data == 'A' || data == 'R'){
        roule = true;
        if (data == 'G'){
          analogWrite(ENA, 180);
          analogWrite(ENB, 100);
          }
        if (data == 'D'){
          analogWrite(ENB, 180);
          analogWrite(ENA, 100);
          }                                                                                                                                                                                                                                                                      
         if (data == 'R'){
          arriere();
          vitesseNormale();
         }
         if (data == 'A'){
          avant();
          vitesseNormale();
         }
      }
      if(data == 'S'){
        vitesseNormale();
        roule = true;
      }
    }

  }
}

void setup() {
  Serial.begin(9600);
  delay(500);
  BlueTooth.begin(9600);
  delay(500);
  
  pinMode(ENA,OUTPUT); // Configurer
  pinMode(ENB,OUTPUT); // les broches
  pinMode(IN1,OUTPUT); // comme sortie
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  avant();
  
  //Moteurs à l'arrêt
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void loop() {
  telecommande();
    }

  
