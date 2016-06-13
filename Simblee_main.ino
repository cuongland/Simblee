int led_green = 7;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led_green, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led_green, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                     // wait for a second
  digitalWrite(led_green, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                     // wait for a second
}
