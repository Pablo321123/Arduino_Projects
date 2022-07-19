int LED = LED_BUILTIN;

void setup() {
   pinMode(2, INPUT_PULLUP); //pinMode esecifica a função do pino
                            // INPUT_PUllUP liga o resistor interno do arduino de modo a especificar sua saida inicial (sem flutuações)
   pinMode(LED, OUTPUT);

   
}

void loop() {
  //digitalRead(2); //Ler a entrada do pino 2
  digitalWrite(LED,  !digitalRead(2));//digitalWrite(13, oque escrever (ligar ou desligar))

}
