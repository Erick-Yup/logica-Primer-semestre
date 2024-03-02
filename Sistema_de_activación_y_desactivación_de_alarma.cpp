
#include <Keypad.h>     
// importa libreria Keypad

const byte FILAS = 4; //Filas del keyboalrd 
const byte COLUMNAS = 4; //Columnas del keyboard
char keys[FILAS][COLUMNAS] = { //Araid con el valos de cada button
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte pinesFilas[FILAS] = {9,8,7,6}; //Pines digitales de las filas
byte pinesColumnas[COLUMNAS] = {5,4,3,2}; // Pines digitales de las columnas

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS); //Creación de una variable teclado

char TECLA; //Tecla seleccionada
char CLAVE[7]; //Creación de string de 7 caracteres
char CLAVE_MAESTRA[7] = "123456"; //Clave pre-creada
byte INDICE = 0; //Iniciacion de la clave
int SENSOR = 11; 
int RECOLECTOR = 10;
int BOCINA = 12;
int DISTANCIA;
int DURACION;
int Var = 1; //Estado de la Alarma

void setup(){
  Serial.begin(9600);
  pinMode(SENSOR, OUTPUT);
  pinMode(RECOLECTOR, INPUT);
  pinMode(BOCINA, OUTPUT);
}

void loop(){
  digitalWrite(SENSOR, HIGH);
  delay(10);
  digitalWrite(SENSOR,LOW);
  DURACION = pulseIn(RECOLECTOR,HIGH);
  DISTANCIA = DURACION / 58.2;
  delay(1000);
  TECLA = teclado.getKey();
  if(DISTANCIA >= 7 && Var == 1){
    Serial.println(DISTANCIA);
    digitalWrite(BOCINA, HIGH);
    delay(5000);
    digitalWrite(BOCINA, LOW);
  }
  if(TECLA){
    CLAVE[INDICE] = TECLA;
    INDICE++;
    Serial.println(TECLA);
  }
  if (INDICE == 6){
    if(!strcmp(CLAVE, CLAVE_MAESTRA)){
      Serial.println(" correcta");
      INDICE = 0;
      Var = 0; 
      delay(5000);
    } 
    else{
      Serial.println(" incorrecta");
      INDICE = 0;
      Var = 1;
    }
    if(Var == 0 && DISTANCIA =>7){
    }
    else{
      Var = 1;
    }
  }
}