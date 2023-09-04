//Programa: Carrinho de controle remoto bluetooth - CIEBP
//data: 01/09/2023
//Autor: CIEBP Araraquara

//informaçoes para programar o controle blouetooth 
/*informaçoes do controle blouetooth
QUANDO NEM UM COMANDO INFORMADO - 83 
para a direita o bluetooth lê - 82
para a esquerda 76
para frente 70 
para trás 66 
Desliga LED dianteiro - 119
Liga o LED dianteiro - 87
Desligar o LED traseiro - 117
Liga o LED traseiro - 85
Desligar a buzina - 118
Ligar a buzina - 86
Desligar o pisca alerta - 120
ligar o pisca alerta - 88*/

//carrega as bibliotecas 
#include <SoftwareSerial.h>

// Define os pinos de comunicação do modulo bluetooth
SoftwareSerial bluetooth(13, 12); //RX TX lembra do inverso (o rx do componente tx do arduino)

//Atribuindo nome aos pinos - variaveis- pederia ser intilizado int 
#define m6 6 //tras direita  
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

// FUNÇÃO PARAR - DESLIGA TODOS OS MOTORES
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

//FUNÇÃO TRAS - LIGA OS PINOS M3, M5, M8 E M9 - FAZZENDO O CARRO IR PARA TRAS
void tras() {
  digitalWrite(m6, HIGH);
  digitalWrite(m4, HIGH); 
  digitalWrite(m8, HIGH);
  digitalWrite(m9, HIGH);
  digitalWrite(LED2, HIGH);// liga led da ré
  digitalWrite(LED4, HIGH);// liga led da ré
}
//FUNÇÃO FRENTE - LIGA OS PINOS M10, M11, M3 E M5 - FAZENDO O CARRO IR PARA FRENTE
void frente() {
  digitalWrite(m10, HIGH);
  digitalWrite(m11, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m5, HIGH);
}
// FUNÇÃO DIREITA - LIGA OS PINOS M5 e M10 FAZENDO O CARRO VIARA PARA A DIREITA
void direita() {
  digitalWrite(m5, HIGH);
  digitalWrite(m10, HIGH);
}
// FUNÇÃO ESQUERDA - LIGA OS PINOS M3 e M11 FAZENDO O CARRO VIARA PARA A eSQUERDA
void esquerda() {
  digitalWrite(m3, HIGH);
  digitalWrite(m11, HIGH);
}
//FUNÇÃO BUNINA
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
//FUNÇÃO FAROL - LIGA PINO LED1 E LED 2
void farol() {
   digitalWrite(LED1, HIGH);
   digitalWrite(LED3, HIGH);
  }


void setup() {
  bluetooth.begin(9600); // COMOONICAÇÃO SERIAL BLUETOOTH
  Serial.begin(9600); // MONITOR SERIAL
  // DEFINE AS PORTAS COMO SAIDA DE INFORMAÇÃO
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

//INICIO DO CODIGO QUE VAI RODAR NO CARRINHO  
void loop() {
  int C = bluetooth.read(); //  A VARIAVEL C ARMAZENA A LEITURA DO BLUETOOTH
  Serial.println(C); //  A VARIAVEL C É IMPRESA NO MONITOR SERIAL 

// SE A VARIAVEL C FOR IGUAL A 83 - CHAMA AFUNÇÃO PARAR()
  if (C == 83) {
    parar();
  }

// SE A VARIAVEL C FOR IGUAL A 82 - CHAMA AFUNÇÃO DIREITA()
  if (C == 82) {
    direita();
  }

// SE A VARIAVEL C FOR IGUAL A 76 - CHAMA AFUNÇÃO ESQUERDA()  
  if (C == 76) {
    esquerda();
  }

// SE A VARIAVEL C FOR IGUAL A 70 - CHAMA AFUNÇÃO FRENTE()
  if (C == 70) {
    frente();
  }

// SE A VARIAVEL C FOR IGUAL A 66 - CHAMA AFUNÇÃO TRAS()
  if (C == 66) {
    tras();
  }

// SE A VARIAVEL C FOR IGUAL A 86 - CHAMA AFUNÇÃO BUZINA()
  if (C == 86) {
    buzina();
  } else if (C == 118){
    digitalWrite(buzzer, LOW);// DESLIGA BUZINA()
  }

// SE A VARIAVEL C FOR IGUAL A 87 - CHAMA AFUNÇÃO FAROL()
  if (C == 87) {
    farol();
  } else if (C == 119){
    digitalWrite(LED1, LOW);// DESLIGA FAROL
    digitalWrite(LED3, LOW);// DESLIGA FAROL
  }
}
