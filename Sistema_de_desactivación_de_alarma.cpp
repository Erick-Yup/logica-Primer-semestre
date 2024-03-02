#include <Keypad.h>     // importa libreria Keypad


const byte FILAS = 4;     // define numero de filas
const byte COLUMNAS = 4;    // define numero de columnas
char keys[FILAS][COLUMNAS] = {    // define la distribucion de teclas
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinesFilas[FILAS] = {9,8,7,6};   // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] = {5,4,3,2}; // pines correspondientes a las columnas

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  // crea objeto

char TECLA;       // almacena la tecla presionada
char CLAVE[7];        // almacena en un array 6 digitos ingresados
char CLAVE_MAESTRA[7] = "123456";   // almacena en un array la contraseña maestra
byte INDICE = 0;      // indice del array
int correcto = 10;   //Pin del led verde
int incorrecto = 11; //Pin del led rojo
int bocina = 12; //Pin de la Bocina

  
void setup()
{
 Serial.begin(9600);      // inicializa comunicacion serie
  pinMode(correcto,OUTPUT);
  pinMode(incorrecto,OUTPUT);
  pinMode(bocina,OUTPUT);
}

void loop(){
  TECLA = teclado.getKey();   // obtiene tecla presionada y asigna a variable
  if (TECLA)        // comprueba que se haya presionado una tecla
  {
    CLAVE[INDICE] = TECLA;    // almacena en array la tecla presionada
    INDICE++;       // incrementa indice en uno
    Serial.print(TECLA);    // envia a monitor serial la tecla presionada
  }

  if(INDICE == 6)       // si ya se almacenaron los 6 digitos
  {
    if(!strcmp(CLAVE, CLAVE_MAESTRA)){   // compara clave ingresada con clave maestra
      // strcomp devuele 0 cuando son iguales
      Serial.println(" Correcta");  // imprime en monitor serial que es correcta la clave
      digitalWrite(correcto, HIGH);
      delay(1000);
      digitalWrite(correcto, LOW);
      INDICE = 0;
    }
    else {
      Serial.println(" Incorrecta");  // imprime en monitor serial que es incorrecta la clave
	  digitalWrite(incorrecto,HIGH);
      delay(2000);
      digitalWrite(incorrecto,LOW);
      digitalWrite(bocina,HIGH);
      delay(5000);
      digitalWrite(bocina,LOW);
    INDICE = 0;
  }
 }
}