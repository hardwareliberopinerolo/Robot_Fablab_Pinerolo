#include <Servo.h> // Incluye la biblioteca para controlar servomotores

Servo servo_0; // Declaración del objeto para controlar el primer servo
Servo servo_1; // Declaración del objeto para controlar el segundo servo
Servo servo_2; // Declaración del objeto para controlar el tercer servo
Servo servo_3; // Declaración del objeto para controlar el cuarto servo

// Definición de pines analógicos para los potenciometros
int sensorPin0 = A0; 
int sensorPin1 = A1;
int sensorPin2 = A2; 
int sensorPin3 = A3; 

// Variables utilizadas en el programa
int count0, arrayStep, arrayMax, countverz, Taster, stepsMax, steps, time = 1000, del = 1000, temp;
int old_Taster;
unsigned int verz = 0;

long previousMillis1 = 0;
long previousMillis2 = 0;
long previousMillis3 = 0;
long previousMillis4 = 0;
long previousMicros = 0;
unsigned long currentMillis = millis();
unsigned long currentMicros = micros();

// Definición de arreglos para almacenar datos
int Delay[7] = {0, 0, 1, 3, 15, 60, 300}; // Mapeo de valores de potenciómetro a retraso en segundos
int SensVal[4]; // Almacena los valores de los sensores
float dif[4], ist[4], sol[4], dir[4]; // Variables para cálculos de diferencia y posición


#define max_prog_steps 10 //orgine era 180

int joint0[max_prog_steps]; // Almacena posiciones del servo 0
int joint1[max_prog_steps]; // Almacena posiciones del servo 1
int joint2[max_prog_steps]; // Almacena posiciones del servo 2
int joint3[max_prog_steps]; // Almacena posiciones del servo 3
int top = max_prog_steps - 1; // Índice máximo para los arreglos
boolean playmode = false, Step = false; // Modo de reproducción y paso
