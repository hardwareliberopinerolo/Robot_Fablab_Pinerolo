// Configuración inicial del programa
void setup()
{
  pinMode(4, INPUT); // Configura el pin digital 4 como entrada
  pinMode(6, INPUT); // Configura el pin digital 6 como entrada

  pinMode(13, OUTPUT); // Configura el pin digital 13 como salida
  digitalWrite(13, HIGH); // Enciende el LED en el pin digital 13

  servo_0.attach(3); // Asocia el servo_0 al pin digital 3
  servo_1.attach(5); // Asocia el servo_1 al pin digital 10
  servo_2.attach(11); // Asocia el servo_2 al pin digital 9
  servo_3.attach(12); // Asocia el servo_3 al pin digital 11

  Serial.begin(115200); // Inicia la comunicación serial con una velocidad de 115200 baudios
  Serial.println("mini robot ready..."); // Imprime mensaje de inicio en el puerto serial
  digitalWrite(13, LOW); // Apaga el LED en el pin digital 13
}
