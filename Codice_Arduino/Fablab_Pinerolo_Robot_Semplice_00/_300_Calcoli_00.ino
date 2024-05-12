// Función para calcular el retraso entre movimientos
void calc_pause()
{
  readPot();
  temp = SensVal[3];
  if (temp < 0) temp = 0;
  temp = map(temp, 0, 680, 0, 6);
  verz = Delay[temp]; // verz = retraso en segundos
}

// Función para mapear valores de los potenciómetros a milisegundos
void mapping()
{
  ist[0] = map(SensVal[0], 150, 900, 600, 2400); // drehen
  ist[1] = map(SensVal[1], 1000, 100, 550, 2400); // Schulter
  ist[2] = map(SensVal[2], 120, 860, 400, 2500); // Hand
  ist[3] = map(SensVal[3], 1023, 0, 500, 2500); // Zange
}

// Función para almacenar posiciones en los arreglos
void record()
{
  joint0[arrayStep] = ist[0];
  joint1[arrayStep] = ist[1];
  joint2[arrayStep] = ist[2];
  joint3[arrayStep] = ist[3];
}

// Función para leer posiciones desde los arreglos
void Read()
{
  sol[0] = joint0[arrayStep];
  sol[1] = joint1[arrayStep];
  sol[2] = joint2[arrayStep];
  sol[3] = joint3[arrayStep];
}

// Función para calcular pasos individuales
void calculate()
{
  dif[0] = abs(ist[0] - sol[0]);
  dif[1] = abs(ist[1] - sol[1]);
  dif[2] = abs(ist[2] - sol[2]);
  dif[3] = abs(ist[3] - sol[3]);

  stepsMax = max(dif[0], dif[1]);
  stepsMax = max(stepsMax, dif[2]);
  stepsMax = max(stepsMax, dif[3]);

  if (stepsMax < 500)
    del = 1200;
  else
    del = 600;

  if (sol[0] < ist[0]) dir[0] = 0 - dif[0] / stepsMax;
  else
    dir[0] = dif[0] / stepsMax;
  if (sol[1] < ist[1]) dir[1] = 0 - dif[1] / stepsMax;
  else
    dir[1] = dif[1] / stepsMax;
  if (sol[2] < ist[2]) dir[2] = 0 - dif[2] / stepsMax;
  else
    dir[2] = dif[2] / stepsMax;
  if (sol[3] < ist[3]) dir[3] = 0 - dif[3] / stepsMax;
  else
    dir[3] = dif[3] / stepsMax;
}
