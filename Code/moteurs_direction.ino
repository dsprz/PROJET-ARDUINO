//-- MOTEUR A --
const int ENA=9; //Connecté à Arduino pin 9(sortie PWM)
const int IN1=4; //Connecté à Arduino pin 4
const int IN2=5; //Connecté à Arduino pin 5

const int ENB=10; //Connecté à Arduino pin 10(Sortie PWM)
const int IN3=6; //Connecté à Arduino pin 6
const int IN4=7; //Connecté à Arduino pin 7

//LED ROUGE
const int LED_VERTE = 2;
const int LED_ROUGE = 3;


void setup() {
  Serial.begin(9600);
  pinMode(ENA,OUTPUT); // Configurer
  pinMode(ENB,OUTPUT); // les broches
  pinMode(IN1,OUTPUT); // comme sortie
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  // LEDS
  pinMode(LED_VERTE, OUTPUT);
  pinMode(LED_ROUGE, OUTPUT);
  
  digitalWrite(ENA,LOW);// Moteur GAUCHE - Ne pas tourner
  digitalWrite(ENB,LOW);// Moteur DROIT - Ne pas tourner
  // Direction du Moteur A
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  // Direction du Moteur B
  // NB: en sens inverse du moteur
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void loop() {
  analogWrite(ENA, 120);
  analogWrite(ENB, 180);
  digitalWrite(LED_ROUGE, HIGH);
  Serial.println("LED ALLUMEE");
  delay(5000);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(LED_ROUGE, LOW);
  Serial.println("LED ROUGE ETEINTE");
  delay(5000);
  // Direction du Moteur B
  // NB: en sens inverse du moteur
  
}
