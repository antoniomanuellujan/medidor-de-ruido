#include <Wire.h> 

int releRojo=6;// su encendido marca un nivel mayor de 60DB
int releVerde=7;// su encendido marca un nivel menor de 50DB
int releAmbar=8;// su encendido indica valores comprendidos entre 50 y 60 DB

const int valormedio=0;
const int numeromuestras=128;//muestras utilizadas para obtener un promedio de lectura
int muestras;// reserva 2 bytes para la variable muestras
long senal;// reserva 4 bytes para la variable senal
long promedioLectura;

const int nivel1=30000;// marca el cambio de verde a Ã¡mbar
const long nivel2=150000;// marca el cambio de Ã¡mbar a rojo

void setup() {
Serial.begin(9600);
Serial.print("I.E.S. Santa MarÃ­a de los BaÃ±os");
  
  pinMode(A0, INPUT);
  pinMode(releRojo,OUTPUT);
  pinMode(releVerde, OUTPUT);
  pinMode(releAmbar,OUTPUT);
  
}

void loop() {
  long sumamuestras=0;
  for (int i=0; i<128; i++) {
    muestras=analogRead(A0);delay(10);// lee 128 muestras con retardo de 10ms
    senal=(muestras-valormedio); 
    senal=senal*senal; 
    sumamuestras=sumamuestras+senal;
  }
  promedioLectura=sumamuestras/128;
 
  if (promedioLectura < nivel1) {
    digitalWrite (releRojo,LOW);
    digitalWrite (releVerde, HIGH);
    digitalWrite (releAmbar, LOW);
      Serial.print("Sonido < 50 DB   ");
    } 
    
    if ((promedioLectura > nivel1) & (promedioLectura < nivel2)) {
    digitalWrite (releRojo,LOW);
    digitalWrite (releVerde, LOW);
    digitalWrite (releAmbar, HIGH);
     Serial.print("Sonido (50-60)DB");
     }
     
     if (promedioLectura > nivel2) { 
    digitalWrite (releRojo, HIGH);
    digitalWrite (releVerde, LOW); 
    digitalWrite (releAmbar, LOW); 
    
    Serial.print("Sonido > 60 DB  ");
     }
  Serial.print (promedioLectura); 
  Serial.print("   "); 
  Serial.print("nivel1=");
  Serial.print(nivel1);
  Serial.print("   "); 
  Serial.print("nivel2=");
  Serial.print(nivel2);
 if (promedioLectura<nivel1) {Serial.print("  LED VERDE");}
 
 if ((promedioLectura>nivel1) & (promedioLectura<nivel2)) {Serial.print("  LED BLANCO");}
 
 if (promedioLectura>nivel2) {Serial.print("  LED ROJO");}
  Serial.println();  
}
 

