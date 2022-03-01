#include <canon.h>
#include <Moteurs.h>
#include <SoftwareSerial.h>
#include <ServoTank.h>
//bluetooth
#define TX 13
#define RX 2
char data;
int angle;
const int canonPin = 8;
 //-- MOTEUR A --
const int ENA = 9; //Connecté à Arduino pin 9(sortie PWM)
const int IN1 = 4; //Connecté à Arduino pin 4
const int IN2 = 5; //Connecté à Arduino pin 5

//-- MOTEUR B --
const int ENB = 10; //Connecté à Arduino pin 10(Sortie PWM)
const int IN3 = 6; //Connecté à Arduino pin 6
const int IN4 = 7; //Connecté à Arduino pin 7

//LEDs
const int LED_VERTE = 14;
const int LED_ROUGE = 15;

//servomoteur
const int servoPin = 3;

Canon canon(canonPin);
Moteurs moteurs(ENA, IN1, IN2, ENB, IN3, IN4);
SoftwareSerial BlueTooth(RX, TX);
ServoTank servo(servoPin);

void telecommande(){
    if(BlueTooth.available()){
    data = BlueTooth.read();
    if (data == 'M'){
    angle = BlueTooth.parseInt();
    Serial.println(angle);}
    Serial.println(data);

    if (data == 'Y'){
      servo.servoDroite(angle);

    }

    if (data == 'X'){
      servo.servoGauche(angle);
    }

    if (data == 'C'){
      canon.tire();
    }

    if (data == 'B'){
      canon.desarme();
    }

    if(moteurs.roule){
      analogWrite(LED_VERTE, 0);
      analogWrite(LED_ROUGE, 255);
      if (data == 'G'){
        moteurs.gauche();
      }
      if (data == 'D'){
        moteurs.droite();
        }
      if (data == 'S'){
        moteurs.arret();
      }
      if (data == 'R'){
        moteurs.arriere();
        moteurs.vitesseNormale();
      }
      if (data == 'A'){
      moteurs.avant();
      moteurs.vitesseNormale();
      }
      
    }
    else{
      analogWrite(LED_VERTE, 255);
      analogWrite(LED_ROUGE, 0);
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
      if(data == 'G' || data == 'D' || data == 'A' || data == 'R'){
        moteurs.rouler();
        if (data == 'G'){
          moteurs.gauche();
          }
        if (data == 'D'){
          moteurs.droite();
          }                                                                                                                                                                                                                                                                      
         if (data == 'R'){
          moteurs.arriere();
          moteurs.vitesseNormale();
         }
         if (data == 'A'){
          moteurs.avant();
          moteurs.vitesseNormale();
         }
      }
      if(data == 'S'){
        moteurs.vitesseNormale();
        moteurs.rouler();
      }
    }
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("pret");
  delay(500);
  BlueTooth.begin(9600);
  servo.servoDroite(30);
}

void loop() {
  // put your main code here, to run repeatedly:
  telecommande();

}
