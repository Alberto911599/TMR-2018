
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
int offset = 53;

/////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////DECLARACION DE VARIABLES/////////////////////////////////////////
Pixy pixy;                                        //1 = Rojo; 2 = Naranja 3 = Amarilla; 4 = Porteria Azul
                                                  //5 = Cyan; 6 = Verde; 7 = Morada; 

Adafruit_BNO055 bno = Adafruit_BNO055(55);        //Declaracion del BNO
                                                   
bool viendo_Pelota;                                                                    
bool viendo_porteria;
bool alineado; 
int bajo = 0;
int alto = 0;
int on_color[3] = {7,5,6};                        //000 = libre; 010 = derecha; 100 = izquierda; 111 = meta rival; 110 = propia meta
int x_pelota, y_pelota;                           
int y_porteria;                                   
int x_porteria;                                   
int rotacion = 0;
int huawei = 0;
int contador_pelota = 0;
int contador_porteria = 0;
int contador_alineacion = 0;
uint16_t blocks;                                  
unsigned int direccion;  
int sw;
int multiplicador = 0;
bool equipo = true;
int signature_porteria;


//////////////////////////////////////////  ////////////////////////////////////////////////////////////////  

                                                  

void setup() {
  
  //Serial.begin(9600);
  
  //Inicializacion de la pixy  
  pixy.init();
  
  //Inicializacion BNO
  bno.begin();
  bno.setExtCrystalUse(true);
  
//  //Switch de porteria
//  pinMode(offset, INPUT);
  
  //Declarar los pines de los motores como salidas
  for(int i = 0; i < 10; i++){
    pinMode(motores[i], OUTPUT);
  }
  
  //Declarar los enables como salidas
  for(int i = 0; i < 5; i++){
    pinMode(enable[i], OUTPUT);
    analogWrite(enable[i], 210);
  }

  //Declarar los pines de las fotorressistencias como entradas
  for(int i = 0; i < 3; i++){
    pinMode(on_color[i], INPUT);
  }
  
  signature_porteria = equipo ? 3 : 5;
  
}

void loop() {
   
  avanzar(analisis_de_datos());

}
