//bool giro(int lower, int upper){
//  
//  sensors_event_t event; 
//  bno.getEvent(&event);
//  rotacion = event.orientation.x;
//  return (rotacion < lower || rotacion > upper);
//}

  

//void alnbno(int lower, int upper){
//  int temp;
//       
//  if(huawei > 180)
//    temp = rotacion > (huawei + 180) % 360 && rotacion < huawei ? 9 : 8;
//    
//  else
//    temp = rotacion > huawei  && rotacion < huawei + 180 ? 8 : 9;
//      
//  while(giro(lower, upper)){
//    avanzar(temp);
//    
//    colores();
//   
//    if(!(on_color[0] == 0 && on_color[1] == 0 && on_color[2] == 0)) {
//      bouncing();
//    }
//    
//  }
//  avanzar(-1);
//  delay(5);
//}

void alineacion_bno(int lower, int upper){
  
  sensors_event_t event; 
  bno.getEvent(&event);
  rotacion = event.orientation.x;
  
//  Serial.print("angulo = ");
//  Serial.println(rotacion);

  if(rotacion > 15 && rotacion < 345){
    
      int temp = rotacion > 180 ? 9 : 8;
      
      avanzar(temp);
      delayMicroseconds(800);
  }
}


