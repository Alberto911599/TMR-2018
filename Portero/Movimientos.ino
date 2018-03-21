void avanzar(int evento) {
  switch (evento) {
    case -2:
    for(int i = 0; i < 8; i++){
      digitalWrite(motores[i], HIGH); 
    }
//      Serial.println("Esperando...");
    break;
    case -1:
      for(int i = 0; i < 8; i++){
        digitalWrite(motores[i], LOW); 
      }
//      Serial.println("Esperando...");
    break;
    case 0://0
      for(int i = 0; i < 8; i++){
        if(i % 2 == 0)
          digitalWrite(motores[i], LOW);
        else
          digitalWrite(motores[i], HIGH);
      }      
//      Serial.println("Retrocediendo");
      break;
    case 1://1
      for(int i = 0; i < 8; i++){
        if(i % 2 == 0)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Avanzando");
      break;
    case 2://2
      for(int i = 0; i < 8; i++){
        if(i == 0 || i == 3 || i == 4 || i == 7)
          digitalWrite(motores[i], LOW);
        else
          digitalWrite(motores[i], HIGH);
      }
//      Serial.println("Izquierdeando");
    break;
    case 3://3
      for(int i = 0; i < 8; i++){
        if(i == 0 || i == 3 || i == 4 || i == 7)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Derecheando");
    break;
    case 4://4
      for(int i = 0; i < 8; i++){
        if(i == 3 || i == 7)
          digitalWrite(motores[i], HIGH);
         else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Diagonal Back Derecha");
    break;
    case 5://5
      for(int i = 0; i < 8; i++){
        if(i == 2 || i == 6)
          digitalWrite(motores[i], HIGH);
         else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Diagonal Front Izquierda");
    break;
    case 6://6
      for(int i = 0; i < 8; i++){
        if(i == 0 || i == 4)
          digitalWrite(motores[i], HIGH);
         else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Diagonal Front Derecha");
    break;
    case 7://7
      for(int i = 0; i < 8; i++){
        if(i == 1 || i == 5)
          digitalWrite(motores[i], HIGH);
         else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Diagnoal Back Izquierda");
    break;
    case 8:
      for(int i = 0; i < 8; i++){
       if(i == 1 || i == 3 || i == 4 || i == 6)
         digitalWrite(motores[i], HIGH);
       else
         digitalWrite(motores[i], LOW);
      }
    break;
    case 9:
      for(int i = 0; i < 8; i++){
       if(i == 1 || i == 3 || i == 4 || i == 6)
         digitalWrite(motores[i], LOW);
       else
         digitalWrite(motores[i], HIGH);
      }
    break;
  }
}

//Funcion utilizada para ir hacia algun objetivo ya identificado
//en este caso catch la pelota y fire la porteria
void recorrido(int i){
  if(i > 100 && i < 220){
//    Serial.println("Adelante");
    direccion = -1;
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
