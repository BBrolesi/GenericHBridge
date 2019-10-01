#ifndef hbridge_h
#define hbridge_h

class Motor
{
private:
    int pinIN1; //Pino de entrada 1
    int pinIN2; //Pino de entrada 2
    int pinPWM; //Pino do sinal PWM
    int velocidadeMaxima; //Velocidade de 0 a 255
    int velocidadeMinima; //Velocidade de 0 a 255
    int velocidadeAtual; //Velocidade de 0 a 255
    int canalPWM; //Canal gerador do Sinal de PWM, de 0 a 15
public:
    Motor();
    Motor(int pinIN1, int pinIN2, int pinPWM, int canalPWM);
    int getPinIN1(); //Retorna o pino de Entrada 1
    int getPinIN2(); //Retorna o pino de Entrada 2
    int getPinPWM(); //Retorna o pino de PWM
    int getVelocidadeMaxima(); //Retorna a velocidade maxima de rotação
    void setVelocidadeMaxima(int velocidadeMaxima); //Define a velocidade maxima de rotação
    int getVelocidadeMinima(); //Retorna a velocidade minima de rotação
    void setVelocidadeMinima(int velocidadeMinima); //Define a velocidade minima de rotação
    int getVelocidadeAtual(); //Retorna a velocidade atual de rotação
    void setVelocidadeAtual(int velocidadeAtual); //Define a velocidade atual de rotação
    int getCanalPWM(); //Retorna o canal PWM utilizado
    void setCanalPWM(int canalPWM); //Define o canal PWM a ser utilizado
};

#endif