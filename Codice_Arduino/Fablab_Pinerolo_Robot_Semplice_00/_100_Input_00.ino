// Función para leer valores de los potenciómetros
void readPot()
{
  SensVal[0] = analogRead(sensorPin0);
  SensVal[1] = analogRead(sensorPin1);
  SensVal[2] = analogRead(sensorPin2);
  SensVal[3] = analogRead(sensorPin3);
  //Serial.print("Sensor4: ");
  //Serial.println(SensVal[3]);
}
