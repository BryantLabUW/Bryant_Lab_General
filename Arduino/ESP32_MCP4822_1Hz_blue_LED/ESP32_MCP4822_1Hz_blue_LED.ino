#define LED_PIN_0 2  // Pin where the onboard LED is connected
#define LED_PIN_1 13  // Pin where your LED is connected

bool blinking = false; // Variable to control the blinking state

void setup() {
  pinMode(LED_PIN_0, OUTPUT);        // Set LED pin as output
  pinMode(LED_PIN_1, OUTPUT);        // Set LED pin as output
  Serial.begin(115200);            // Start serial communication at 115200 baud
}

void loop() {
   if (Serial.available()) {
    char command = Serial.read();  // Read the incoming command
    if (command == 's') {
      blinking = true;              // Start blinking
      Serial.println("Blinking ON");
      } else if (command == 'p') {
      blinking = false;             // Stop blinking
      digitalWrite(LED_PIN_0, LOW);   // Ensure LED is off
      digitalWrite(LED_PIN_1, LOW); 
      Serial.println("Blinking OFF");
    }
  }
  
if (blinking) {
      digitalWrite(LED_PIN_0, HIGH);     // Turn the LED on
      digitalWrite(LED_PIN_1, HIGH);     // Turn the LED on
      Serial.println("LED ON");         // Print status to Serial Monitor
      delay(1000);                      // Wait for 1 second
      digitalWrite(LED_PIN_0, LOW);     // Turn the LED on
      digitalWrite(LED_PIN_1, LOW);     // Turn the LED on
      Serial.println("LED OFF"); 
      delay(1000); 
}

}