#include <wiringPi.h>
#include <stdio.h>
#include <vector>
#include <iostream>

void charToBin(std::vector <int> &buffer, char lettre){
  printf("%d\n", lettre);
  for(int i=1;i<buffer.size();i++){
    buffer[i] = lettre % 2;
    lettre = (lettre - (lettre % 2)) / 2;
    if(lettre == 0)
      break;
  }
}
int main (void)
{
  int pin = 7;
  char msg;
  std::vector <int> packet(10,0);
  packet[0] = 1;
  printf("Raspberry Pi wiringPi blink test\n");

  if (wiringPiSetup() == -1)
   return 1;

  pinMode(pin, OUTPUT);

  printf("Lettre : ");
  msg = getchar();
  charToBin(packet, msg); 
  
  for(int i=0;i<packet.size();i++){
  digitalWrite(pin, packet[i]);
  printf("%d", packet[i]);
  delay(20);
  }
  printf("\n");
  
  return 0;
}
