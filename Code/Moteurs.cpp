#include "Moteurs.h"

Moteurs::Moteurs(int ENA, int IN1, int IN2, int ENB, int IN3, int IN4)
{
   pinMode(ENA, OUTPUT);
   pinMode(IN1, OUTPUT);
   pinMode(IN2, OUTPUT);
   pinMode(ENB, OUTPUT);
   pinMode(IN3, OUTPUT);
   pinMode(IN4, OUTPUT);

   analogWrite(ENA, 0);
   analogWrite(ENB, 0);
   avant();
   
   _ENA = ENA;
   _IN1 = IN1;
   _IN2 = IN2;
   _ENB = ENB;
   _IN3 = IN3;
   _IN4 = IN4;
   roule = false;
 
}

void Moteurs::arriere()
{
  //Marche arrière
  digitalWrite(_IN1,LOW);
  digitalWrite(_IN2,HIGH);
  digitalWrite(_IN3,HIGH);
  digitalWrite(_IN4,LOW);
 }

void Moteurs::avant()
{
  //Marche avant
  digitalWrite(_IN1,HIGH);
  digitalWrite(_IN2,LOW);
  digitalWrite(_IN3,LOW);
  digitalWrite(_IN4,HIGH);
 }
 

void Moteurs::vitesseNormale()
{
  //Vitesse de croisière
  analogWrite(_ENA, 140);
  analogWrite(_ENB, 160);
}

void Moteurs::droite()
{
   analogWrite(_ENB, 220);
   analogWrite(_ENA, 100);
}

void Moteurs::gauche()
{
   analogWrite(_ENA, 220);
   analogWrite(_ENB, 100);
}

void Moteurs::arret()
{
  roule = false;
}

void Moteurs::rouler()
{
  roule = true;
}
