// Bucle principal del programa
void loop()
{
  currentMillis = millis(); // Obtiene el tiempo actual en milisegundos
  currentMicros = micros(); // Obtiene el tiempo actual en microsegundos
  Button(); // Llama a la función Button() para manejar el botón

  // Sección de código para el modo manual...
  if (!playmode)
  {
    if (currentMillis - previousMillis1 > 25)
    {
      if (arrayStep < top)
      {
        previousMillis1 = currentMillis;
        readPot(); // Lee los valores de los potenciómetros
        mapping(); // Mapea los valores a milisegundos para los servos
        move_servo(); // Establece la nueva posición del servo
      }
    }
  }

  // Sección de código para el modo de reproducción...
  else if (playmode)
  {
    if (Step)
    {
      digitalWrite(13, HIGH); // Enciende el LED en el pin digital 13
      if (arrayStep < arrayMax)
      {
        arrayStep += 1;
        Read();
        calculate();
        Step = 0;
        digitalWrite(13, LOW); // Apaga el LED en el pin digital 13
      }
      else
      {
        arrayStep = 0;
        calc_pause();
        countverz = 0;
        while (countverz < verz)
        {
          countverz += 1;
          calc_pause();
          digitalWrite(13, HIGH); delay(25);
          digitalWrite(13, LOW); delay(975);
        }
      }
    }
    else
    {
      if (currentMicros - previousMicros > time)
      {
        previousMicros = currentMicros;
        play_servo();
      }
    }
  }

  // Bucle de espera hasta que se presione el botón de pausa...
  while (digitalRead(4) == false)
  {
    digitalWrite(13, HIGH); delay(500);
    digitalWrite(13, LOW); delay(500);
  }

  // Comentario: Sección de salida de texto por el puerto serial (comentada para mayor concisión)
  // ...
}
