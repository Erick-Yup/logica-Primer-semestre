const int pot=0; //Potenciometro de Humedad
int humedad; //Almacenamos el valor de la humedad

void setup() {

Serial.begin(9600); //Inica la comunicación con el LCD con una velocidad de 9600 baudios
pinMode(2,OUTPUT); //Inica el pin digital 2 como salida
}

void loop() {
humedad = analogRead (pot) / 10; //Lee el valor de humedad y lo almacena en pot/10
Serial.println(humedad);
if(humedad<65){  //Lee el valor de humedad y temperatura y los compara
digitalWrite(2, HIGH); //Activa sistema de riego

} else {
  digitalWrite(2, LOW); //Desactiva el sistema de riego
}
  delay(2000); //Delay
}