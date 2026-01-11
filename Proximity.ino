// ---------------------------
// Project 1: Smart Proximity System
// Hardware: Arduino Uno + HC-SR04 Ultrasonic Sensor + LED + Resistor
// ---------------------------

// Pin definitions
const int trigPin = 9;    // TRIG pin of HC-SR04
const int echoPin = 10;   // ECHO pin of HC-SR04
const int ledPin  = 6;    // LED pin

// Variables
long duration;            // Time for sound pulse to return
int distance;             // Calculated distance in cm
int threshold = 50;       // Distance threshold for detection

void setup() {
  // Define pin modes
  pinMode(trigPin, OUTPUT);   // TRIG sends pulse
  pinMode(echoPin, INPUT);    // ECHO receives pulse
  pinMode(ledPin, OUTPUT);    // LED controlled by Arduino

  digitalWrite(ledPin, LOW);  // LED OFF initially

  Serial.begin(9600);         // Optional: monitor distance
}

void loop() {
  // ---------------------------
  // Step 1: Trigger Ultrasonic Pulse
  // ---------------------------
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Step 2: Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Step 3: Convert time to distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");   // Optional debug
  Serial.print(distance);
  Serial.println(" cm");

  // ---------------------------
  // Step 4: Decision Logic
  // ---------------------------
  if (distance > 0 && distance < threshold) {
    // Object/person is close → LED ON
    digitalWrite(ledPin, HIGH);
  } else {
    // No object detected → LED OFF
    digitalWrite(ledPin, LOW);
  }

  delay(200); // Small delay to stabilize readings
}

