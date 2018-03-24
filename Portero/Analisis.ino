int analisis_de_datos(){
  
  colores();
  
//  Area libre, no se hatocado ninguna linea de salida
  if((on_color[0] == 0 && on_color[1] == 0  && on_color[2] == 0)){
    
    alineacion_bno(15, 345);
    
//    if(kalman() < 135){
//      while(kalman() < 150){
//        avanzar(0);
//        delay(30);
//      }
//    }
    
    scanPixy();
    
    if(viendo_Pelota){
      crashLimit=false;
      recorrido(x_pelota);
      
    }
    
    else{
      if(crashLimit)
        direccion = -1;
      
    }
    
  }
  
  else{
    
    bouncing();
    
  }
  
  return direccion;
  
}
    
