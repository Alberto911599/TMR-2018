//Funcion utilizada para ir hacia algun objetivo ya identificado
//en este caso catch la pelota y fire la porteria
void catch_fire(int i){
  if(i > 100 && i < 220){
//    Serial.println("Adelante");
    direccion = 1;
  }
  //La pelota esta a la izquierda
  else if(i <= 100){
//    Serial.println("Izquierda");
    direccion = 2;
  }
  //La pelota esta a la derecha
  else{
//    Serial.println("Derecha");
    direccion = 3;
  }
}

void catch_fire_direct(int i, int j){
  if(i > 100 && i < 220){
//    Serial.println("Adelante");
    direccion = 1;
  }
  //La pelota esta a la izquierda
  else if(i <= 100){
    //La peota esta muy cerca
    if(j > 110){
      //Izquierda
      direccion = 2;
    }
    //La pelota esta lejos
    else{
      //Frente izquierda
      direccion = 5;
    }
  }
  else{
    if(j > 110){
      //Derecha
      direccion = 3;
    }
    //La pelota esta lejos
    else{
      //Frente derecha
      direccion = 6;
    }
  }
}

//Funcion que se utiliza para buscar un objetivo
void find_objective(int i){
  //Si no se detecta, y la ultima vez que se vio fue en medio
  if( i >= 40 && i <= 280 ){
//    Serial.println("Se perdio de vista por distancia, echa reversa");
    direccion = 0;
  }
//  Si no se detecta, y la ultima vez que se vio i fue mayor a 270, el objetivo esta a la derecha
  else if(i > 280){
//    Serial.println("El objetivo salio por la derecha, diagonal hacia atras a la derecha");
    direccion = 4;
  }
  //Si no se detecta, y la ultima vez que se vio i fue menor a 50, el objetivo esta a la izquierda
  else{
//    Serial.println("El objetivo salio por la izquierda, diagonal hacia atras a la izuqierda");
    direccion = 7;
  }
}


//void simple_bouncing(){
//  int tiempo = 400;
//  int meta = 0;
//  scanPixy();
//  giro(15,345);
//  
//  //Toque en meta
//  if(on_color[0] == 1 && on_color[1] == 1){
//    
//    tiempo = 800;     
//    
//    if(on_color[2] == 1){
//    
//      meta = 1;
//      direccion = res_ant == 2 ? 4 : 7;
//      
//      while(viendo_Pelota){
//          scanPixy();
//          avanzar(-1); 
//      }   
//    
//  }
//    
//    else{
//      
//      meta = -1;
//      direccion = res_ant == 2 ? 6 : 5;          
//      
//    }
//      
//      
//  }
//  
//  else if(on_color[0] == 1){
//      //Rotacion incorrecta
//      if(rotacion < 350 && rotacion > 180)
//        direccion = 0;
//      //Rotacion correcta
//      else
//        direccion = 3;
//    
//    
//    res_ant = 2;
//    
//  }
//    //direccion = rotacion >= 5 || rotacion <= 355 ? 3 : 6; 
//    
//  else{
//      //Rotacion incorrecta
//      if(rotacion > 10 && rotacion < 180)
//        direccion = 0;
//      //Rotacion correcta
//      else 
//        direccion = 2;
//    
//    res_ant = 3;
//    
//  }
//    
//    if((direccion == 4 || direccion == 6 || direccion == 3) && !viendo_Pelota)
//      x_pelota = 399;
//    if((direccion == 7 || direccion == 5 || direccion == 2) && !viendo_Pelota)
//      x_pelota = 0;
//    
//    if(meta == 1){
//      avanzar(0);
//      delay(700);
//    }
//    if(meta == -1){
//      avanzar(1);
//      delay(700);
//    }
//    
//    avanzar(direccion);
//    delay(tiempo); 
//    
//}

int analisis_de_datos(){
  
//  Escanea donde estas parado
 colores(); 
 
 avanzar(10); 
  
//  Area libre, no se hatocado ninguna linea de salida
  if((on_color[0] == 0 && on_color[1] == 0  && on_color[2] == 0)){
    
    if(contador_alineacion < 550){
      contador_alineacion++;
    }
    
    alineacion_bno(40, 320);

// Alineate con la porteria  
    if(viendo_porteria && !alineado && contador_alineacion >= 500){
      alineacion_porteria();
    }
    
    scanPixy();
    
//  //Si no esta viendo la pelota, busca la pelota de acuerdo a la ultima vez que se vio
    if(!viendo_Pelota){
      //Buscala
//    //Serial.println("No estoy viendo la pelota y la estoy buscando");
      find_objective(x_pelota);
    }

    //Si estas viendo la pelota evalua si:
    else{
      //Si tengo posesion de la pelota
      //if(tengo_Pelota){
      //Ve a "disparar" hacia la porteria
        //catch_fire_direct(x_porteria, y_porteria);
      //}

      //Si no tengo la pelota, pero la estoy viendo
      //else{
//      Ve a atrapar la pelota  
        catch_fire_direct(x_pelota, y_pelota);
      //}
    }
  }

//  Si estoy en una linea
  else{
      bouncing();
   }
  return direccion;
}


