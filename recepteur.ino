void setup(){
 Serial.begin(9600);
}

int pw( int exponent)
{
    int out = 1;
    while (exponent--)
	 out *= 2;
    return out;
}

void loop(){
  int packet[10];
  char msg = 0;
  
  for(;;){ // Stand-by
    if(analogRead(0) > 700) // La séquance a commancé 
      break;
  }
  
  for(int i=0;i<10;i++){
    if(analogRead(0) > 700)
      packet[i] = 1;
    else
      packet[i] = 0;
    delay(20);
  }
  
  for(int i=1;i<10;i++){
    msg = msg + pw(i-1)*packet[i];
  }
  Serial.print(msg);
  delay(100);
}
