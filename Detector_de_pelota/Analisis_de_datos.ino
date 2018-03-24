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


int analisis_de_datos(){
  
//  Escanea donde estas parado
 colores();  
  
//  Area libre, no se hatocado ninguna linea de salida
  if((on_color[0] == 0 && on_color[1] == 0  && on_color[2] == 0)){
    
//    if(contador_alineacion < 100){
//      contador_alineacion++;
//    }
    
    
    alineacion_bno();
    
    scanPixy();

 //Alineate con la porteria  
    if(viendo_porteria && !alineado){
      alineacion_porteria();
    }
    
    if(y_pelota > 100 && viendo_Pelota)
      avanzar(10);
      
    else
      avanzar(11);
    
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
        catch_fire(x_pelota);
      
    }
  }

//  Si estoy en una linea
  else{
      bouncing();
   }
   multiplicador = millis()/3000;
   multiplicador = multiplicador > 4 ? 4: multiplicador;
  return direccion;
}


