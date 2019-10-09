/*
  fpbasicaelectricidad.blogspot.com
  Arduino + Processing: Semáforo de ruido
  ARCHIVOS DE PROCESSING CON POTENCIÓMETRO DE NIVEL
  
  MAYO DE 2016
*/

import processing.serial.*; //Importamos la librería Serial
Serial port; //Nombre del puerto serie

import controlP5.*;
ControlP5 cp5;

int dato_puerto;
PImage imagen_rojo, imagen_amarillo, imagen_verde;

void setup()
{
  
  port = new Serial(this, Serial.list()[0], 9600); //Abre el puerto serie COM3
  size(450, 450); //Creamos una ventana de 450 píxeles de anchura por 450 píxeles de altura 
  imagen_rojo = loadImage("triste.jpg");
  imagen_amarillo = loadImage("indiferente.jpg");
  imagen_verde = loadImage("riyendo.jpg");
  background(255,255,255);//Fondo de color blanco
  
  crea_potenciometro();
}

void crea_potenciometro() {
  
  cp5 = new ControlP5(this);
  
     
  cp5.addSlider("Sensibilidad")
     .setPosition(10,10)
     .setSize(100,20)
     .setRange(0,100)
     .setValue(50)
     ;

}

 
void draw()
{
  float s1=0, s2=0;
  
  // Mandar datos del potenciometro al arduino
  s1 = cp5.getController("Sensibilidad").getValue();
  if (s1 != s2) {
    port.write(int (s1));
    s2=s1;
  }
  
  
  //Recibir datos del sonido del Arduino 
  if(port.available() > 0) // si hay algún dato disponible en el puerto
   {
     dato_puerto = port.read();//Lee el dato y lo almacena en la variable "dato_puerto"
     if (dato_puerto == 20) image(imagen_verde, 0, 0);
     else if (dato_puerto == 22) image(imagen_rojo, 0, 0);
     else image(imagen_amarillo, 0, 0);
     //println(dato_puerto);
   }
   //else print (" Arduino desconectado del puerto USB");

}
