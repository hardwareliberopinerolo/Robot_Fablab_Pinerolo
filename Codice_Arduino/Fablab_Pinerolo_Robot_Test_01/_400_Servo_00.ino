// Función para mover los servos
void move_servo()
{
  servo_0.writeMicroseconds(ist[3]);
  servo_1.writeMicroseconds(ist[2]);
  servo_2.writeMicroseconds(ist[0]);
  servo_3.writeMicroseconds(ist[1]);
}


// Función para mover los servos durante la reproducción
void play_servo()
{
  steps += 1;
  if (steps < stepsMax)
  {
    if (steps == 20) time = del * 4;
    else if (steps == 40) time = del * 3;
    else if (steps == 80) time = del * 2;
    else if (steps == 100) time = del - 1;

    if (steps == stepsMax - 200) time = del * 2;
    else if (steps == stepsMax - 80) time = del * 3;
    else if (steps == stepsMax - 40) time = del * 4;
    else if (steps == stepsMax - 20) time = del * 5;

    ist[0] += dir[0];
    ist[1] += dir[1];
    ist[2] += dir[2];
    ist[3] += dir[3];

Serial.print(ist[3]); Serial.println(".."); //GB

    servo_0.writeMicroseconds(ist[3]);
    servo_1.writeMicroseconds(ist[2]);
    servo_2.writeMicroseconds(ist[0]);
    servo_3.writeMicroseconds(ist[1]);
  }
  else
  {
    Step = 1;
    steps = 0;
    playmode =0; //GB
    
  }
}
