int LED = 13; //LED_BUILTIN contem o numero da porta na qual esta instalada o led padrao do arduino, no caso do UNO eh o 13
char buffer[9];

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600); //velocidade de transmissão de bits (baud rate) Padrao eh 9600
  Serial.println("Arduino");

}

void loop() {
  
  digitalWrite(LED, HIGH); // HIGH, saida alta, 1
  sprintf(buffer, "Saida: %d", digitalRead(LED));
  Serial.println(buffer);
  delay(2000);
  
  digitalWrite(LED, LOW); // LOW, saida baixa, 0
  sprintf(buffer, "Saida: %d", digitalRead(LED));
  Serial.println(buffer);
  delay(4000); 

}
