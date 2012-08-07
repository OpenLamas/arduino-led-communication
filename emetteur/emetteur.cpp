#include <wiringPi.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

void tailleToBin(std::vector <int> &packet, int taille){
  std::vector <int> buffer(5, 0);
  for(int i=0;i<buffer.size();i++){
    buffer[i] = taille % 2;
    taille = (taille - taille % 2) / 2;
    if(taille == 0){
      break;
    }
  }
  packet.insert(packet.end(), buffer.begin(), buffer.end());
}

void stringToBin(std::vector <int> &packet, std::string msg){
  std::vector <int> buffer(7, 0);

  //printf("%d\n", msg[j]);
  
  for(int j=0;j<msg.size();j++){
    for(int i=1;i<buffer.size();i++){
      buffer[i] = msg[j] % 2;
      msg[j] = (msg[j] - (msg[j] % 2)) / 2;
      if(msg[j] == 0)
        break;
    }
    packet.insert(packet.end(), buffer.begin(), buffer.end());
    buffer.clear();
    buffer.resize(7);
  }
}

int main (void)
{
  int pin = 7;
  std::string msg = "";
  std::vector <int> packet(0,0);
  packet.push_back(1);
  printf("Raspberry Pi wiringPi blink test\n");

  if (wiringPiSetup() == -1)
   return 1;

  pinMode(pin, OUTPUT);

  std::cout << "Message : ";
  getline(std::cin, msg);
  if(msg.size() > 31){
    std::cout << std::endl << "Votre message est trop long" << std::endl;
    return 1;
  }
  
  tailleToBin(packet, (int) msg.size());
  stringToBin(packet, msg);
  
  for(int i=0;i<packet.size();i++){
  //digitalWrite(pin, packet[i]);
  printf("%d", packet[i]);
  delay(20);
  }
  printf("\n");
  
  return 0;
}