int analisis_de_datos(){
  
  colores();
  
//  Area libre, no se hatocado ninguna linea de salida
  if((on_color[0] == 0 && on_color[1] == 0  && on_color[2] == 0)){
    
    alineacion_bno(10, 340);
    
    scanPixy();
    
    if(viendo_Pelota){
      
      recorrido(x_pelota);
      
    }
    
    else{
      
      direccion = -1;
      
    }
    
  }
  
  else{
    
    bouncing();
    
  }
  
  return direccion;
  
}
    
