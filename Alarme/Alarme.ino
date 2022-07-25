const int POTENCIOMETRO = A2;
const int RELE = 2;
const int LED_AMARELO = 9;
const int LED_VERDE = 4;
const int botao = 12;

int sensorValue = 0;
float tensao = 0.0;
int saidaAnalogica = 0;

bool pinBotaoRetencao();

void turnOn()
{
    digitalWrite(LED_AMARELO, HIGH);
}

void setup()
{
    pinMode(botao, INPUT_PULLUP);
    pinMode(LED_VERDE, INPUT_PULLUP);
    pinMode(LED_AMARELO, OUTPUT);
    pinMode(RELE, OUTPUT);
}

void loop()
{    
    sensorValue = analogRead(POTENCIOMETRO);
    tensao = 0.0049 * sensorValue;

    if (pinBotaoRetencao(botao))
    {
        if (tensao <= 1)
        {
            digitalWrite(LED_VERDE, HIGH);
            digitalWrite(LED_AMARELO, LOW);
            digitalWrite(RELE, HIGH);
        }
        else if (tensao <= 4)
        {
            digitalWrite(LED_VERDE, LOW);

            //Valores mapeados ao inves de 0 a 1023, colocaremos 204 a 818 para a variavao correta do LED dentro do intervalo de 1 < tensao <= 4
            saidaAnalogica = map(sensorValue, 204, 818, 0, 255); 
            
            analogWrite(LED_AMARELO, saidaAnalogica);
            digitalWrite(RELE, HIGH);
        }
        else
        {
            digitalWrite(LED_VERDE, LOW);
            digitalWrite(LED_AMARELO, LOW);
            digitalWrite(RELE, LOW);
        }
    }
    else
    {
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_AMARELO, LOW);
        digitalWrite(RELE, HIGH);
    }
}

//Controle de borda de descida do botao
bool pinBotaoRetencao(int pino)
{
#define TEMPO_DEBOUNCE 50
    // Efeito bounce: tempo de instabilidade (ocilacao) de estado (ligado e desligado)
    // ao ligar, ou desligar , o botao.

    bool estadoBotao;                    // Capturar o estado atual do botao
    static bool estadoBotaoAnt;          // Variavel para guardar o estado anterio do botao
    static bool estadoRet = true;        // captura o valor da retencao de estado. Se estiver desligado, liga e vice versa
    static unsigned long delayBotao = 0; //Variavel que vai controlar o debounce

    if ((millis() - delayBotao) > TEMPO_DEBOUNCE) // Sempre verificara se passou os 50 ms do tempo de debounce
    {
        estadoBotao = digitalRead(pino);

        if (estadoBotao && (estadoBotao != estadoBotaoAnt))
        {
            estadoRet = !estadoRet;
            delayBotao = millis(); //Captura o tempo atual que houve a mudanca de estado
        }
        estadoBotaoAnt = estadoBotao;
    }

    return estadoRet;
}