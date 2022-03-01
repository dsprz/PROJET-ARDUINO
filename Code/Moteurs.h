#ifndef MOTEURS_H
#define MOTEURS_H

#include <Arduino.h>

class Moteurs
{
   public:
    Moteurs(int ENA, int IN1, int IN2, int ENB, int IN3, int IN4);
    void arriere();
    void avant();
    void vitesseNormale();
    void droite();
    void gauche();
    void arret();
    void rouler();
    bool roule;
   private:
     int _ENA;
     int _IN1;
     int _IN2;
     int _ENB;
     int _IN3;
     int _IN4;

};

#endif
