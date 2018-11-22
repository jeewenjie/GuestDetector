int buzzer = 13;             // Passive buzzer module
int sensor = 2;              // Passive IR sensor
int state = LOW;             // Default state = OFF; state = ON/OFF; ON = person detected, OFF = no person
int val = 0;                 // IR sensor variable 
unsigned char i;             // For counting

void setup() {
  pinMode(buzzer, OUTPUT);     
  pinMode(sensor, INPUT);    
  Serial.begin(9600);        
}

void loop(){
  val = digitalRead(sensor);   // Read from IR sensor 
  if (val == HIGH) {           // If value is HIGH, sensor detected something
      for (i = 0; i <2; i++)      // Sound buzzer
      {
         digitalWrite (buzzer, HIGH) ; // Future update could make the ringtone nicer?
         delay (1) ;
         digitalWrite (buzzer, LOW) ; 
         delay (1) ;
      }       
    delay(100);               
    
    if (state == LOW) {
      Serial.println("Person detected!");  // Serial print for troubleshooting
      state = HIGH ;            // Change state to "person detected"
    }
  } 
  else {
      digitalWrite(buzzer, LOW); // Ensure buzzer off 
      delay(200);            //
      
      if (state == HIGH){ // State is HIGH from previous loop.
        Serial.println("Nothing is happening.");  // Serial print for troubleshooting
        state = LOW;       // Reset state to LOW
    }
  }
}
