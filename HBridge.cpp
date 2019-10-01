#include "HBridge.h"
#include <Arduino.h>

Motor::Motor(){}

Motor::Motor(int pinIN1, int pinIN2, int pinPWM, int canalPWM)
{
    this->pinIN1 = pinIN1;
    this->pinIN2 = pinIN2;
    this->pinPWM = pinPWM;
    this->canalPWM = canalPWM;
    this->velocidadeMinima = 0;
    this->velocidadeMaxima = 150;
    this->velocidadeAtual = 110;
    
    ledcAttachPin(this->pinPWM, this->canalPWM);
}

int Motor::getPinIN1(){
    return this->pinIN1;
}

int Motor::getPinIN2(){
    return this->pinIN2;
}

int Motor::getPinPWM(){
    return this->pinPWM;
}

int Motor::getVelocidadeMaxima(){
    return this->velocidadeMaxima;
}

void Motor::setVelocidadeMaxima(int velocidadeMaxima){
    this->velocidadeMaxima = velocidadeMaxima;
}

int Motor::getVelocidadeMinima(){
    return this->velocidadeMinima;
}

void Motor::setVelocidadeMinima(int velocidadeMinima){
    this->velocidadeMinima = velocidadeMinima;
}

int Motor::getVelocidadeAtual(){
    return this->velocidadeAtual;
}

void Motor::setVelocidadeAtual(int velocidadeAtual){
    if(velocidadeAtual > this->velocidadeMaxima && velocidadeAtual > 0)  
    {
        this->velocidadeAtual = this->velocidadeMaxima;
    }
    else if(velocidadeAtual < velocidadeMaxima && velocidadeAtual > 0)
    {
        this->velocidadeAtual = velocidadeAtual;
    }
    else if(velocidadeAtual <= 0)
    {
        this->velocidadeAtual = 0;
    }
    ledcWrite(this->canalPWM, this->velocidadeAtual);
}

int Motor::getCanalPWM(){
    return this->canalPWM;
}

void Motor::setCanalPWM(int canalPWM){
    this->canalPWM = canalPWM;
}