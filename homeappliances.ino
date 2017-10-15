#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); //TX, RX  pins of arduino respetively
String command;
void setup()
{
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(7, OUTPUT);
  
}

void loop() 
{
  while (BT.available())
         {  //Check if there is an available byte to read
          delay(10); //Delay added to make thing stable
        char c = BT.read(); //Conduct a serial read
            command += c; //build the string.
          } 
        if (command.length() > 0) 
      {
        Serial.println(command);
        if(command == "light on") //this command will be given as an input to switch on light1
      {
          digitalWrite(7, HIGH);
      }
        else if(command == "light off") //this command will be given as an input to switch off light1 simillarly other commands work
      {
          digitalWrite(7, LOW);
       }
    command="";
    }
} //Reset the variable

