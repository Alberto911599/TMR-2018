//Documentacion de la pixy camera: http://cmucam.org/projects/cmucam5/wiki/Arduino_API
#include <Pixy.h>
#include <PixyI2C.h>
#include <PixySPI_SS.h>
#include <PixyUART.h>
#include <SPI.h>
#include <Wire.h>
#include <TPixy.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

//MOTORES
int motores[8] = {40, 42, 38, 36, 10, 9, 12, 11};//23, 22, 24, 25, 43, 42, 40, 41, 29, 31};
int enable[5] = {3, 4, 8, 13, 2};

///////////////////////////////////////DECLARACION DE VARIABLES/////////////////////////////////////////
Pixy pixy;                                        //2 = pelota


Adafruit_BNO055 bno = Adafruit_BNO055(55);        //Declaracion del BNO


bool viendo_Pelota = true;
int distancia = 0;
int x_pelota = 0, y_pelota = 0; 
int contador_pelota = 0;
int rotacion = 0;
int on_color[3] = {7,5,6};                        //000 = libre; 010 = derecha; 100 = izquierda; 111 = meta rival; 110 = propia meta
unsigned int direccion = -1; 
uint16_t blocks;
//const int bajo = 348;
//const int alto = 18;
boolean crashLimit = false;


void setup(){
  
//  Serial.begin(9600);
    
  //Inicializacion de pixy y BNO
  pixy.init();
  bno.begin();
  bno.setExtCrystalUse(true);
  delay(10);
  
  //Declarar los pines de los motores como salidas
  for(int i = 0; i < 8; i++){
    pinMode(motores[i], OUTPUT);
  }
  
  //Declarar los enables como salidas
  for(int i = 0; i < 5; i++){
    pinMode(enable[i], OUTPUT);
    analogWrite(enable[i], 190);
  }
  
  analogWrite(enable[0],100);
  analogWrite(enable[1],100);
  
  
  //Declarar los pines de las fotorressistencias como entradas
  for(int i = 0; i < 3; i++){
    pinMode(on_color[i], INPUT);
  }
  
}


void loop(){
  avanzar(analisis_de_datos());
}
