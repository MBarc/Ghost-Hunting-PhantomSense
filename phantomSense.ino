#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Pin definitions
#define TOUCH_SENSOR_PIN 7
#define DHT_FRONT_LEFT_PIN 4
#define DHT_FRONT_RIGHT_PIN 5
#define DHT_AMBIENT_PIN 6
#define FRONT_LEFT_LED_PIN 2
#define FRONT_RIGHT_LED_PIN 3

// DHT type
#define DHTTYPE DHT11

// Threshold for significant temperature drop (in degrees Celsius)
#define TEMP_DROP_THRESHOLD 2.0

// DHT sensor objects
DHT dhtFrontLeft(DHT_FRONT_LEFT_PIN, DHTTYPE);
DHT dhtFrontRight(DHT_FRONT_RIGHT_PIN, DHTTYPE);
DHT dhtAmbient(DHT_AMBIENT_PIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  // Initialize touch sensor pin
  pinMode(TOUCH_SENSOR_PIN, INPUT);

  // Initialize LED pins
  pinMode(FRONT_LEFT_LED_PIN, OUTPUT);
  pinMode(FRONT_RIGHT_LED_PIN, OUTPUT);
  digitalWrite(FRONT_LEFT_LED_PIN, LOW);
  digitalWrite(FRONT_RIGHT_LED_PIN, LOW);

  // Initialize DHT sensors
  dhtFrontLeft.begin();
  dhtFrontRight.begin();
  dhtAmbient.begin();

  Serial.println("Device initialized. Waiting for operation...");
}

void loop() {
  // Read touch sensor
  int touchState = digitalRead(TOUCH_SENSOR_PIN);

  if (touchState == LOW) {
    Serial.println("Touch detected. Turning on front right LED.");
    digitalWrite(FRONT_RIGHT_LED_PIN, LOW);
  } else {
    Serial.println("Touch not detected! Turning off front right LED.");
    digitalWrite(FRONT_RIGHT_LED_PIN, HIGH);
  }


  // Read temperatures from DHT sensors
  float tempFrontLeft = dhtFrontLeft.readTemperature();
  float tempFrontRight = dhtFrontRight.readTemperature();
  float tempAmbient = dhtAmbient.readTemperature();

  Serial.print("Front Left: ");
  Serial.println(tempFrontLeft);
  Serial.print("Front Right: ");
  Serial.println(tempFrontRight);
  Serial.print("Ambient: ");
  Serial.println(tempAmbient);

  // Check if any readings failed
  if (isnan(tempFrontLeft) || isnan(tempFrontRight) || isnan(tempAmbient)) {
    Serial.println("Error: Failed to read temperature from one or more sensors.");
    return;
  }

  // Print temperature readings
  Serial.print("Front Left Temperature: ");
  Serial.print(tempFrontLeft);
  Serial.println(" °C");

  Serial.print("Front Right Temperature: ");
  Serial.print(tempFrontRight);
  Serial.println(" °C");

  Serial.print("Ambient Temperature: ");
  Serial.print(tempAmbient);
  Serial.println(" °C");

  // Control front left LED based on temperature comparison
  if (tempFrontLeft < tempAmbient && tempFrontRight < tempAmbient) {
    Serial.println("Both front sensors are colder than ambient. Turning on front left LED.");
    digitalWrite(FRONT_LEFT_LED_PIN, HIGH);
  } else {
    Serial.println("One or both front sensors are not colder than ambient. Turning off front left LED.");
    digitalWrite(FRONT_LEFT_LED_PIN, LOW);
  }
}
