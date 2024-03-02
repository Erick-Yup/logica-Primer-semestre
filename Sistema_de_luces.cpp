int pinLDR = A0; //Pin Utilizado para el Fotoreceptor
int luzLDR = 0; //Almacena los datos del Fotoreceptor
int ledPin = 2; //Pin del LED

void setup() {
   Serial.begin(9600); //Inica la comunicación con el LCD con una velocidad de 9600 baudios
  pinMode(ledPin,OUTPUT); //Inica el pin digital 2 como salida
}

void loop() {
  luzLDR = analogRead(pinLDR); //Lee el valor de la luz y lo guarda en luz LRD
  
  if(luzLDR > 150){ // compara la luz
      digitalWrite(ledPin,LOW); //Activa el led
  } 
    else if(luzLDR < 150){
      digitalWrite(ledPin,HIGH); // Apaga el led
  } 
  delay(2000);
  Serial.println(luzLDR); //Imprime la iluminación recibida
}
