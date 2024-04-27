// Función para manejar el botón
void Button()
{
  if (digitalRead(6) == false)
  {
    delay(1);
    if (digitalRead(6) == true)
    {
      if (Taster == 0)
      {
        Taster = 1;
        previousMillis3 = currentMillis;
      }
      else if ((Taster == 1) && (currentMillis - previousMillis3 < 250))
      {
        Taster = 2;
      }
    }
  }

  if ((Taster == 1) && (currentMillis - previousMillis3 > 1000))
  {
    arrayStep += 1;
    arrayMax = arrayStep;
    record();
    Taster = 0;
    playmode = false;
    Serial.print("Record Step: "); Serial.println(arrayStep);
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
  }
  else if (Taster == 2)
  {
    arrayStep = 0;
    playmode = true;
    Taster = 0;
    Step = 1;
    Serial.println("playmode ");
    data_out();
    delay(250);
    digitalWrite(13, LOW);
  }

  if (currentMillis - previousMillis3 > 2000)
  {
    Taster = 0;
  }
}
