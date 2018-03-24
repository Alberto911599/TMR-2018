void colores(){
  on_color[0] = digitalRead(5);
  on_color[1] = digitalRead(7);
  on_color[2] = digitalRead(6);
}

void bouncing(){
  
  colores();
  
  //long int temp = millis(); 
      
  //Toque en meta
  if(on_color[0] == 1 && on_color[1] == 1){     
    
    if(on_color[2] == 1){
    
      avanzar(0);
      delay(800);
    
    }
 
    else{
   
      avanzar(1);
      delay(800);
    
    } 
    
  }
    
  else if(on_color[0] == 1){
    crashLimit = true;
    
    avanzar(5);
    delay(300);
    avanzar(2);
    delay(800);
    
    while(analogRead(A4)<500){
      avanzar(0);
      alineacion_bno(15, 345);
    }
    avanzar(1);
    delay(200);
    avanzar(-1);
    delay(100);
    direccion=-1;
  }

  else{
    crashLimit = true; 
    
    avanzar(6);
    delay(300);
    avanzar(3);
    delay(800);
    
    while(analogRead(A4)<500){
      avanzar(0);
      alineacion_bno(15, 345);
    }
    avanzar(1);
    delay(200);
    avanzar(-1);
    delay(100);
    direccion=-1;
  }
  
  avanzar(-1);
  delay(2);
 
//  while(millis() < temp + 300){
//          
//    avanzar(direccion);
//    delay(10);
//    colores();
//   
//    if(!(on_color[0] == 0 && on_color[1] == 0 && on_color[2] == 0)) {
//      bouncing();
//    }
//  
//  }
  
//  if((direccion == 4 || direccion == 6 || direccion == 3) && !viendo_Pelota)
//    x_pelota = 399;
//  if((direccion == 7 || direccion == 5 || direccion == 2) && !viendo_Pelota)
//    x_pelota = 0;
          
}
  
  


