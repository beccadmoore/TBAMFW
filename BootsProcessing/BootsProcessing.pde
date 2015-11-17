import processing.serial.*;

Serial myPort;  // Create object from Serial class
boolean firstContact;
int rx = 0;

void setup() {
  printArray( Serial.list() );
  myPort = new Serial(this, Serial.list()[2], 9600);
  size(400, 400);
}

void draw()
{
  if (rx == 56) { 
   background(0); 
  } 
  else if (rx == 57){
   background(255); 
  }
}


void serialEvent(Serial myPort){
 int inByte = myPort.read();
 if(firstContact == false){
  if(inByte == 'A'){
    myPort.clear();
    firstContact = true;
    myPort.write('A');
  }
 }
 else{
   println(inByte);
   rx = inByte;
   //rx = str(inByte);
   myPort.write('A');
 }
}