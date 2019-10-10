/*
  fpbasicaelectricidad.blogspot.com
  Arduino + Processing: Semáforo de ruido
  ARCHIVOS DE PROCESSING CON POTENCIÓMETRO DE NIVEL
  
  MAYO DE 2016
  Modificado por Antonio Luján 10/10/2019
*/

import processing.serial.*; //Importamos la librería Serial
Serial port; //Nombre del puerto serie



int dato_puerto;
PImage imagen_rojo, imagen_amarillo, imagen_verde;

void setup()
{
 
  
  port = new Serial(this, Serial.list()[0] , 9600); //Abre el puerto serie /dev/ttyACM0
  size(450, 450); //Creamos una ventana de 450 píxeles de anchura por 450 píxeles de altura 
  imagen_rojo = loadImage("imagen_rojo.jpg");
  imagen_amarillo = loadImage("imagen_amarillo.jpg");
  imagen_verde = loadImage("imagen_verde.jpg");
  background(255,255,255);//Fondo de color blanco
  println(Serial.list()[0]);
}



 
void draw(){

  
  //Recibir datos del sonido del Arduino 
  if(port.available() > 0) // si hay algún dato disponible en el puerto
   {
     dato_puerto = port.read();//Lee el dato y lo almacena en la variable "dato_puerto"
     if (dato_puerto == 1){
       image(imagen_verde, 0, 0);
     }
     else if (dato_puerto == 3){
       image(imagen_rojo, 0, 0);
     }
     else{
       image(imagen_amarillo, 0, 0);
     }
     println(dato_puerto);
     delay(1000);
   }
   else 
   {
     println (" Arduino desconectado del puerto USB");
   }
      println (port.available());
}
