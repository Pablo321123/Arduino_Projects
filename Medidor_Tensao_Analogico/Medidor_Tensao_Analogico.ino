int POTENCIAL_PIN = A2;
int LED_PIN = 13; //Digital
int sensorValue = 0;
float tensao = 0.0;
char texto[60];

void setup()
{
    Serial.begin(9600);
    //Iniciar o pino que controlará o LED
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    // Ler a entrada digital do potenciometro
    sensorValue = analogRead(POTENCIAL_PIN);
    tensao = 0.0049 * sensorValue; // Equaçao obtida por meio de um polinomio interpolador
    
    Serial.print("Tensao: ");
    Serial.println(tensao, 2);

    sprintf(texto, "Valor: %d", sensorValue);
    Serial.println(texto);

    // Variar o tempo em que o led fica ligado a depender do valor lido do potenciometro
    digitalWrite(LED_PIN, HIGH);
    delay(sensorValue);
   
    digitalWrite(LED_PIN, LOW);
    delay(sensorValue);
    
}
