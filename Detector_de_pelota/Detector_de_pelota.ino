
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
int motores[10] = {42, 40, 36, 38, 9, 10, 11, 12, 26, 28};
int enable[5] = {3, 4, 8, 13, 2};

//PORTERIA SWITCH
int porteria = 53;

/////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////DECLARACION DE VARIABLES/////////////////////////////////////////
Pixy pixy;                                        //1 = Rojo; 2 = Naranja 3 = Amarilla; 4 = Porteria Azul
                                                  //5 = Cyan; 6 = Verde; 7 = Morada; 

Adafruit_BNO055 bno = Adafruit_BNO055(55);        //Declaracion del BNO
                                                   
bool viendo_Pelota;                                                                    
bool viendo_porteria;
bool viendo_izquierda;
bool viendo_derecha;
bool alineado;
bool equipo; 
int signature_porteria;
int signature_izquierda;
int signature_derecha;
int on_color[3] = {7,5,6};                        //000 = libre; 010 = derecha; 100 = izquierda; 111 = meta rival; 110 = propia meta
int x_pelota, y_pelota;                           
int y_porteria;                                   
int x_porteria;                                   
int izquierda_height;
int derecha_height;
int rotacion;
int contador_pelota = 0;
int contador_porteria = 0;
int contador_izquierda = 0;
int contador_derecha = 0;
int contador_alineacion = 0;
uint16_t blocks;                                  
unsigned int direccion;                           

//////////////////////////////////////////  ////////////////////////////////////////////////////////////////  

                                                  

void setup() {
  
  //Inicializacion de pixy y BNO
  pixy.init();
  bno.begin();
  bno.setExtCrystalUse(true);
  
  //Declarar los pines de los motores como salidas
  for(int i = 0; i < 10; i++){
    pinMode(motores[i], OUTPUT);
  }
  
  //Declarar los enables como salidas
  for(int i = 0; i < 5; i++){
    pinMode(enable[i], OUTPUT);
    analogWrite(enable[i], 160);
  }
//    analogWrite(enable[1], 170);
  
  //Declarar los pines de las fotorressistencias como entradas
  for(int i = 0; i < 3; i++){
    pinMode(on_color[i], INPUT);
  }
  
  //Switch de porteria
  pinMode(porteria, INPUT);
  //equipo = true;
  
  //Indicamos que colores estaran a la izquierda y a la derecha
  signature_porteria = equipo ? 3 : 6;
  signature_izquierda = equipo ? 5 : 4;
  signature_derecha = equipo ? 7 : 1; 
  
  for(int i =0; i < 100; i++)
    equipo = digitalRead(porteria);
}

void loop() {
  avanzar(analisis_de_datos());
//  {42, 40, 36, 38, 9, 10, 11, 12, 26, 28};
//  scanPixy();
//  if(viendo_Pelota)
//    digitalWrite(42, HIGH);
//  else
//    digitalWrite(42, LOW);
//  if(viendo_porteria)
//    digitalWrite(11, HIGH);
//  else
//    digitalWrite(11, LOW);
//  if(viendo_izquierda)
//    digitalWrite(36, HIGH);
//  else
//    digitalWrite(36, LOW);
//  if(viendo_derecha)
//    digitalWrite(9, HIGH);
//  else
//    digitalWrite(9, LOW);
}
