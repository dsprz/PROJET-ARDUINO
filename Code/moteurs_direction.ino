//-- MOTEUR A --
const int ENA=9; //Connecté à Arduino pin 9(sortie PWM)
const int IN1=4; //Connecté à Arduino pin 4
const int IN2=5; //Connecté à Arduino pin 5

//-- MOTEUR B --
const int ENB=10; //Connecté à Arduino pin 10(Sortie PWM)
const int IN3=6; //Connecté à Arduino pin 6
const int IN4=7; //Connecté à Arduino pin 7

//LEDs
const int LED_VERTE = 3;
const int LED_ROUGE = 2;
bool roule = true;

//Boutons poussoir
const int bouton_droite = 13;
const int bouton_gauche = 11;
const int bouton_stop = 2;
int val_droite = 0;
int val_gauche = 0;
int val_stop = 0;


void droite(){
  val_droite = digitalRead(bouton_droite);
  if(val_droite == LOW){
    Serial.println("app");
    analogWrite(ENA, 255);
  }
  else{analogWrite(ENA, 80);}
}

 void gauche(){
  val_gauche = digitalRead(bouton_gauche);
  if(val_gauche == LOW){
    analogWrite(ENB, 255);
  }
  else{
  analogWrite(ENB, 100);}
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

void setup() {
  Serial.begin(9600);
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
  pinMode(bouton_droite, INPUT);
  pinMode(bouton_gauche, INPUT);
  pinMode(bouton_stop, INPUT);
  analogWrite(ENA, 120);
  analogWrite(ENB, 120);
  pinMode(12, OUTPUT);
}
void loop() {
  digitalWrite(LED_VERTE, LOW);
  digitalWrite(LED_ROUGE, HIGH);
  digitalWrite(12, HIGH);
  analogWrite(ENA, 120);
  analogWrite(ENB, 120);
  //if (roule == true){
  //droite();
  //gauche();}
  //arret();
  //delay(5000);
  //analogWrite(ENA, 0);
  //analogWrite(ENB, 0);
  //delay(5000);

  
  // Direction du Moteur B
  // NB: en sens inverse du moteur
  
}
