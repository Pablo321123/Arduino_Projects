int LED = LED_BUILTIN;
int rele = 7;
char texto[13];

void setup() {
   pinMode(2, INPUT_PULLUP); //pinMode esecifica a função do pino
                            // INPUT_PUllUP liga o resistor interno do arduino de modo a especificar sua saida inicial (sem flutuações)
   pinMode(LED, OUTPUT);
   pinMode(7, OUTPUT);   

   Serial.begin(9600);
   Serial.println("RELE: ");
}

void loop() {
  //digitalRead(2); //Ler a entrada do pino 2
  digitalWrite(LED,  !digitalRead(2)); //digitalWrite(13, oque escrever (ligar ou desligar))
  digitalWrite(rele, digitalRead(2)); // A shield de rele liga em 0 volts!!

  sprintf(texto, digitalRead(2) ? "Desligado: %d" : "Ligado: %d", digitalRead(2));
  Serial.println(texto);

//  if( digitalRead(2) == 0){    
//      sprintf(texto, "Desligado: %d", digitalRead(2))
//      Serial.println("Desligado")      
//  } else{
//      sprintf(texto, "Desligado: %d", digitalRead(2))
//      Serial.println("Desligado")
//  }

  

}
