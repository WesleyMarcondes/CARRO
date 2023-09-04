//83 para
//para a direita o bluetooth lê 82;
//para a esquerda 76
//para frente 70
//para trás 66
//119 desliga LED dianteiro
//87 liga o LED dianteiro
//117 desliga o LED traseiro
//85 liga o LED traseiro
//118 desliga a buzina
//86 liga a buzina
//120 desliga o pisca alerta
//88 liga o pisca alerta
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(13, 12); //RX TX lembra do inverso
#define m6 6 //tras direita tras
#define m3 3 //tras direita frente
#define m4 4 //tras esquerda tras
#define m5 5 //tras esquerda frente
#define m8 8 //frente esquerda tras
#define m9 9 //frente direita tras
#define m10 10 //frente esquerda frente
#define m11 11 //frente direita frente
#define LED1 A0 //frente direito
#define LED2 A1 //tras direito
#define LED3 A2 //frente esquerdo
#define LED4 A3 //tras esquerdo
#define buzzer 7 

void parar() {
  digitalWrite(m6, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
  digitalWrite(m5, LOW);
  digitalWrite(m8, LOW);
  digitalWrite(m9, LOW);
  digitalWrite(m10, LOW);
  digitalWrite(m11, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED4, LOW);
}

void tras() {
  digitalWrite(m6, HIGH);
  digitalWrite(m3, LOW); //falso contato
  digitalWrite(m4, HIGH); 
  digitalWrite(m5, LOW); //falso contato
  digitalWrite(m8, HIGH);
  digitalWrite(m9, HIGH);
  digitalWrite(m10, LOW);
  digitalWrite(m11, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED4, HIGH);
}

void frente() {
  digitalWrite(m10, HIGH);
  digitalWrite(m11, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m5, HIGH);
}
void direita() {
  digitalWrite(m6, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
  digitalWrite(m5, HIGH);
  digitalWrite(m8, LOW);
  digitalWrite(m9, LOW);
  digitalWrite(m10, HIGH);
  digitalWrite(m11, LOW);
}
void esquerda() {
  digitalWrite(m6, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
  digitalWrite(m5, LOW);
  digitalWrite(m8, LOW);
  digitalWrite(m9, LOW);
  digitalWrite(m10, LOW);
  digitalWrite(m11, HIGH);
}

void buzina() {
  digitalWrite(buzzer, HIGH);
  /*delay(300);
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, HIGH);
  delay(300);*/
}

void farol() {
   digitalWrite(LED1, HIGH);
   digitalWrite(LED3, HIGH);
  }


void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600);
  pinMode(m6, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(m5, OUTPUT);
  pinMode(m8, OUTPUT);
  pinMode(m9, OUTPUT);
  pinMode(m10, OUTPUT);
  pinMode(m11, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int C = bluetooth.read();
  Serial.println(C);
  Serial.println(digitalRead(m8));

  if (C == 83) {
    parar();
  }

  if (C == 82) {
    direita();
  }
  if (C == 76) {
    esquerda();
  }

  if (C == 70) {
    frente();
  }

  if (C == 66) {
    tras();
  }

  if (C == 86) {
    buzina();
  } else if (C == 118){
    digitalWrite(buzzer, LOW);
  }

  if (C == 87) {
    farol();
  } else if (C == 119){
    digitalWrite(LED1, LOW);
    digitalWrite(LED3, LOW);
  }
}
