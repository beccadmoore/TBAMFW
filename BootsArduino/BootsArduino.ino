int switchPin = 4;                       // Switch connected to pin 4
static int state = 0;

void setup() {
  while(!Serial);
  Serial.begin(9600);                    // Start serial communication at 9600 bps
  pinMode(13, OUTPUT);
  pinMode(switchPin, INPUT);             // Set pin 0 as an input
  establishContact();
}

void establishContact(){
 while( Serial.available() <= 0){
   Serial.println('A');
   digitalWrite(13, state);
   state = !state;
   delay(300);
 }
}

void loop() {
  if(Serial.available() > 0){
     digitalWrite(13, state);
     state = !state;
    
    if (digitalRead(switchPin) == HIGH) {  // If switch is ON,
       Serial.write((byte)1);               // send 1 to Processing
       digitalWrite(13, HIGH);
    } else {                               // If the switch is not ON,
        Serial.write((byte)0);               // send 0 to Processing
        digitalWrite(13, LOW);
    }
  }
  delay(10);                            // Wait 100 milliseconds
}
