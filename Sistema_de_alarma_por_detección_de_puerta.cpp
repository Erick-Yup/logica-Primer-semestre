//Declaramos variables
// Sesor de Distancia
int SENSOR = 10; // Pin de Activacion del Sensor
int RECOLECTOR = 9; //Pin del Recolector de
int BOCINA = 3; //Pin digital de la bocina
int DURACION; //Recoleccion de datos
int DISTANCIA; //Distancia

void setup(){
  pinMode(SENSOR, OUTPUT);
  pinMode(RECOLECTOR, INPUT);
  pinMode(BOCINA, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(SENSOR, HIGH); //Encendemos el sensor
  delay(1);
  digitalWrite(SENSOR, LOW); //Apagamos el sensor
  DURACION = pulseIn(RECOLECTOR, HIGH); //Recolectamos los datos en duracion 
  //PulseIn devuelve valores en microsegundos
  DISTANCIA = DURACION / 58.2; //Convertimos los valores a cm
  // 58.2 constante de converción de microsegundos a centimetros
  Serial.println(DISTANCIA); //Imprimimos los valores en el serial monitor
  delay(100);
  if(DISTANCIA >= 7){
    digitalWrite(BOCINA, HIGH);
    delay(5000);
    digitalWrite(BOCINA, LOW);
  }
}