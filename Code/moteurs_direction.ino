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
bool roule = true;

//Boutons poussoir
//const int bouton_droite = 13;
const int bouton_gauche = 11;
const int bouton_stop = 2;
const int bouton_arriere = 3;
int val_droite = 0;
int val_gauche = 0;
int val_stop = 0;
int val_arriere = 0;

//bluetooth
char data;
#include <SoftwareSerial.h>
#define RX 2
#define TX 13

SoftwareSerial BlueTooth(RX, TX);

//void droite(){
 // val_droite = digitalRead(bouton_droite);
  //if(val_droite == LOW){
    //Serial.println("app");
    //analogWrite(ENA, 255);
  //}
  //else{analogWrite(ENA, 80);}
//}

 void gauche(){
  val_gauche = digitalRead(bouton_gauche);
  if(val_gauche == LOW){
    analogWrite(ENB, 255);
  }
  else{
  analogWrite(ENB, 100);}
 }

 void arriere(){
  val_arriere = digitalRead(bouton_arriere);
  if(val_arriere == LOW){
    analogWrite(ENB, -60);
    analogWrite(ENA, -60);
    delay(100);
  }
 }
 void arret(){
  val_stop = digitalRead(bouton_stop);
  if (val_stop == LOW){
    analogWrite(ENB, 0);
    analogWrite(ENA, 0);
    roule=!roule;
    delay(100);
  }
 }

void telecommande(){
    if(BlueTooth.available()){
    data = BlueTooth.read();
    Serial.println(data);
    if (data == 'G'){
      analogWrite(ENA, 180);
      analogWrite(LED_VERTE, 0);
      analogWrite(LED_ROUGE, 255);
      }
    if (data == 'D'){
      analogWrite(ENB, 180);
      analogWrite(LED_VERTE, 0);
      analogWrite(LED_ROUGE, 255);
      }
    if (data == 'S'){
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
      analogWrite(LED_ROUGE, 0);
      analogWrite(LED_VERTE, 255);
      
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
  // LEDS
  //pinMode(LED_VERTE, OUTPUT);
  //pinMode(LED_ROUGE, OUTPUT);
  
  digitalWrite(ENA,LOW);// Moteur GAUCHE - Ne pas tourner
  digitalWrite(ENB,LOW);// Moteur DROIT - Ne pas tourner
  // Direction du Moteur A
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  // Direction du Moteur B
  // NB: en sens inverse du moteur
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  //Boutons poussoir
  //pinMode(bouton_droite, INPUT);
  pinMode(bouton_gauche, INPUT);
  pinMode(bouton_stop, INPUT);
  pinMode(bouton_arriere, INPUT);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  pinMode(12, OUTPUT);
}

void loop() {
  digitalWrite(LED_VERTE, LOW);
  digitalWrite(LED_ROUGE, HIGH);
  digitalWrite(12, HIGH);
  //analogWrite(ENA, 120);
  //analogWrite(ENB, 180);
  telecommande();
    }
  //if (roule == true){
  //droite();
  //gauche();}
  //arret();


  
  // Direction du Moteur B
  // NB: en sens inverse du moteur
  
