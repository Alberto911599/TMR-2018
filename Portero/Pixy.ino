void scanPixy(){
  
  int signature;
  int area_temp;
  
  
  blocks = pixy.getBlocks();
 
  viendo_Pelota = contador_pelota < 750;
  
  if(contador_pelota < 800)
    contador_pelota++;
  
  if(blocks){

    for (int h = 0; h < blocks; h++){
      
      signature = pixy.blocks[h].signature;
      area_temp = pixy.blocks[h].height * pixy.blocks[h].width;
      
      //Naranja Pelota
      if(signature == 2){

        if(area_temp > 10){
          contador_pelota = 0;
          x_pelota = pixy.blocks[h].x; //Regresa la coordenada x del centro del rectangulo (de 0 a 319)
          y_pelota = pixy.blocks[h].y; //Regresa la coordenada x del centro del rectangulo (de 0 a 199)
          
        }
        
      }
      
    }
  }
  
}

