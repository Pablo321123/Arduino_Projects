#define INTERVALO 1500

extern volatile unsigned long timer0_millis; //Sobrescrita da variavel 'timer' do metodo millis();
int LED_ANALOGICO = 6;
int luminosidade = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(LED_ANALOGICO, INPUT_PULLUP);
}

void loop()
{   
    if (millis() % INTERVALO == 0)
    {
        luminosidade += 30;
        
        Serial.println(luminosidade);
        Serial.println(millis());
        
        delay(50); // Tempo de debounce, delay colocado para evitar o efeito da tripidação na variação mecânica da tensão no circuito initerno.
        analogWrite(LED_ANALOGICO, luminosidade);
    }
    else if (luminosidade > 255)
    {
        luminosidade = 0;
        timer0_millis = 0; //Variavel parar controlar o 'tempo interno' do arduino 
        
        Serial.println(luminosidade);
        Serial.println(millis());
        
        delay(50); // Tempo de debounce, delay colocado para evitar o efeito da tripidação na variação mecânica da tensão no circuito initerno.
        analogWrite(LED_ANALOGICO, luminosidade);        
    }

    //analogWrite(LED_ANALOGICO, luminosidade);
    //Serial.println(millis());

    //Aqui o tempo da tomada de decisão, 'ifs', impacta na execução!
    //Quando inserido, o codigo comentado acima, se comportou de uma forma inesperada, levando mais tempo que o normal para executar (1.5 segundos).
}
