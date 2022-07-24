const int analogInPin = A2;
const int analogOutPin = 9;

int sensorValue = 0;
int outputValue = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    //Leitura da entrada analogica 2
    sensorValue = analogRead(analogInPin);

    // Mapeamento da entrar e saida analogica
    outputValue = map(sensorValue, 0, 1023, 0, 255);

    // A funcao map converte uma entrada analogica (de 0 a 1023) em valores
    // de saida analogica (0 a 255), a depender do mapeamento.
    //Nesta situacao, tambem a opcao de usar o seguinte codigo:

    // analogWrite(analogOutPin, sensorValue / 4); Dividir por 4 os valores de entrada

    //Escrita em uma saida analogica
    analogWrite(analogOutPin, outputValue);

    // Resultados:
    Serial.print("sensor = ");
    Serial.print(sensorValue);
    Serial.print("\t output = ");
    Serial.println(outputValue);

    delay(2);
}