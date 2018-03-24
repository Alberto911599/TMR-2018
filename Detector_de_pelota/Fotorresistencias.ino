void colores(){
  on_color[0] = digitalRead(5);
  on_color[1] = digitalRead(7);
  on_color[2] = digitalRead(6);
}

void bouncing(){
  
  colores();
  
  long int temp = millis(); 
      
  //Toque en meta
  if(on_color[0] == 1 && on_color[1] == 1){     
    
    if(on_color[2] == 1){
    
      direccion = 0;
    
    }
 
    else{
    
      direccion = 1;
    
    } 
    
  }
    
  else if(on_color[0] == 1){
    
    direccion = 3;
    
  }

  else{
    
    direccion = 2;
    
  }
  
  acelera();
  while(millis() < temp + 100){
          
    avanzar(direccion);
    delay(50*multiplicador);
    colores();
   
    if(!(on_color[0] == 0 && on_color[1] == 0 && on_color[2] == 0)) {
      bouncing();
    }
  
  }
  
  afloja();
  if((direccion == 4 || direccion == 6 || direccion == 3) && !viendo_Pelota)
    x_pelota = 399;
  if((direccion == 7 || direccion == 5 || direccion == 2) && !viendo_Pelota)
    x_pelota = 0;
          
}
  
  


