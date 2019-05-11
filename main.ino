#include "DHT.h"
const int sensor_pin = A10;  /* Soil moisture sensor O/P pin */
int sensorPin = A0;
int sensorValue = 0;
float Kc[]={,,,}; /* un tableau qui contient 3 cst on fixant la culture*/
DHT dht;
int relais=13;
pinMode(13,OUTPUT);  /* commande du relais */

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
  if humidity>50 
      float Et0=0.13*((2.065*sensorValue)+50)*temperature/(temperature+15);
else 
      ET0=0.13*((2.065*sensorValue)+50)*temperature/(temperature+15)*(1+(50-humidity)/70);
float ETc=ET0*Kc(rtc.getMonth());   
float Pu=(1.25*(Pt^0.824)-2.93)*10^(0.000955*ETc);  /* précipitation utile*/
int Ep,Er=, /* deux constantes à choisir après avoir installé le circuit hydrolique */
int EG=Ep*Er;   
float PEDV=20.3+2.14*(Vent^2)-2.29*(10^(-3))*(humidity^2);
float CEw=RSw/0.64;  // expérimental RS 
float CEe=RSe/0.64;
float FL=CEw/((5*CEe)-CEw);
float BT=100*(Etc-Pu+PEDV+BL)/EG;
float Rud=(O-Opc)/100*z*So;
float Qi=BT-Rud;// Qi quantité irrigé
if Qi>0 
int temps=Qi/dp;// dp débit de la pompe
 digitalWrite(relais,HIGH);
 delay(temps);
 digitalWrite(relais,LOW);
else 
digitalWrite(relais,LOW);
}

