#include "DHT.h"
const int sensor_pin = A10;  /* Soil moisture sensor O/P pin */
int sensorPin = A0;
int sensorValue = 0;
DHT dht;

void setup() {
  Serial.begin(9600); /* Define baud rate for serial communication */
  Serial.println();
  Serial.println("Humidity (%)\tTemperature (C)\tMoisture Percentage (%)\trayonnement");
 pinMode(sensorPin, INPUT);
  dht.setup(2);   /* set pin for data communication */
}

void loop() {
 delay(dht.getMinimumSamplingPeriod());  /* Delay of amount equal to sampling period */
  float moisture_percentage;
  int sensor_analog;
  float humidity = dht.getHumidity();     /* Get humidity value */
  float temperature = dht.getTemperature(); /* Get temperature value */
   sensor_analog = analogRead(sensor_pin);
 sensorValue = analogRead(sensorPin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
    Serial.print(humidity);
  Serial.print("\t\t");
  Serial.print(temperature);
  Serial.print("\t\t");
  Serial.print(moisture_percentage);
  Serial.print("\t\t\t");
  Serial.println(sensorValue);
  
  delay(1000);
}
