#include <Servo.h> 
// incluimos la libreria para Servomotores

Servo motor1; //Definimos como motor1 al Servomotor

int SERVO = 3; //Pin donde se conecto el ServoMotor
int PULSOMIN = 200; //Pulso de 1 milisegundo = 0 grados
int PULSOMAX = 2000; //Pulso de 2 milisegundos = 180 grados
int VALORPOT; //Valor que arroja el Potenciometro
int ANGULO; //Angulo que gira el servomotor
int POTENCIOMETRO = 0; //Pin al que esta conectado el Potenciometro

void setup(){ //Inicializamos los pines utilizados
  motor1.attach(SERVO, PULSOMIN, PULSOMAX); // Definimos los cáracteres del Servomotor
  //Las entradas Analogicas no requieren de inicialización
}

void loop(){
  VALORPOT = analogRead(POTENCIOMETRO); //Obtenemos el valor del Potenciometro y lo guardamos en la varable VALORPOT
  ANGULO = map(VALORPOT , 0 , 1023 , 0 , 180 ); //Obtenemos el valor del angulo con la funcion map 
  //map(Valores obtenidos del Potenciometro (VALORPOT), Valors que otorga el potenciometro(0, 1023), Valores dados al Servomotor(0,180)  
  motor1.write(ANGULO); //Le damos las instrucciones obtenidas de la variable ANGULO al Servomotor
  delay(20); //Le dejamos un delay de 20milisegundos entre cada cambio del potenciometro
}