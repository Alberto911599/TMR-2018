int sharp(){
  return abs(analogRead(A4));
}

int kalman(){
  distancia = 0;
  for(int i = 0; i < 100; i++){
    distancia += sharp();
  }
  return (distancia /= 100);
}
