#include<stdio.h>
#include<wiringPi.h>
#include"decod.h"

#define A 21
#define B 22
#define C 23
#define D 24

void decode(int qtd_pessoas)
{
    wiringPiSetup;
    pinMode(A,OUTPUT);
    pinMode(B,OUTPUT);
    pinMode(C,OUTPUT);
    pinMode(D,OUTPUT);

    switch (qtd_pessoas)
    {
    case 0:
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
        break;
    case 1:
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
        break;
    case 2:
        digitalWrite(A,LOW);
        digitalWrite(B,HIGH);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
        break;
    case 3:
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
        break;
    case 4:
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
        break;
    case 5:
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
        break;
    case 6:
        digitalWrite(A,LOW);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
        break;
    case 7:
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
        break;
    case 8:
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,HIGH);
        break;
    case 9:
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,HIGH);
        break;

    default:
        break;
}
}