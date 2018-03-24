bool giro(int lower, int upper){
  
  sensors_event_t event; 
  bno.getEvent(&event);
  rotacion = event.orientation.x;
  return (rotacion < lower || rotacion > upper);
}

  

void alnbno(int lower, int upper){
  giro(lower, upper);
  int temp = rotacion < 27 ? 8 : 9;
  while(giro(lower, upper)){
    avanzar(temp);
    
  }
  avanzar(-1);
}

void alineacion_bno(){
    
  sensors_event_t event; 
  bno.getEvent(&event);
  rotacion = event.orientation.x;
  
//  Serial.print("angulo = ");
//  Serial.println(rotacion);

  if(rotacion > 40 && rotacion < 320){
    
       //contador_alineacion = 0;
    
      int temp = rotacion > 180 ? 9 : 8;
      
      avanzar(temp);
      delay(5);
  }
  avanzar(-1);
  delayMicroseconds(500);
}


