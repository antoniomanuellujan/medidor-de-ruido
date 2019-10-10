//Archivo original propiedad del IES Laurel de la Reina (La Zubia - Granada)
// Modificado por Antonio Luján (IES Santa María de los Baños - Murcia)

const int numeromuestras=128;//muestras tomadas para una lectura
int muestras;// reserva 2 bytes para la variable muestras
long senal;// reserva 4 bytes para la variable senal
long promedioLectura;


const long nivel1=190000;// marca el cambio del verde al amarillo
const long nivel2=200000;// marca el cambio del amarillo al rojo

int nivel_verde = 1; 
int nivel_amarillo = 2;
int nivel_rojo = 3;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);  
}

void loop() {
  long sumamuestras=0;
  for (int i=0; i<numeromuestras; i++) {
    muestras=analogRead(A0);
    delay(10);// lee cada muestra con retardo de 10ms
    senal=senal*senal; //"dispara" las diferencias entre valores 
    sumamuestras=sumamuestras+senal;
  }
  promedioLectura=sumamuestras/numeromuestras;
 
  if (promedioLectura < nivel1) {      
      Serial.write(nivel_verde); //envía al serial un número que identifica el nivel verde
    //Serial.println(nivel_verde);
    } 
    
    if ((promedioLectura > nivel1) & (promedioLectura < nivel2)) {
 
     Serial.write(nivel_amarillo); //envía al serial un número que identifica el nivel amarillo
   // Serial.println(nivel_amarillo);
     }
     
     if (promedioLectura > nivel2) { 

    
    Serial.write(nivel_rojo); //envía al serial un número que identifica el nivel rojo
   //Serial.println(nivel_rojo);
     }
//Serial.println(promedioLectura); // Puede ser útil para calibrar
}
 
