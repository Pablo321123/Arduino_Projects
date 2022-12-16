
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define ENDERECO 0x3f
#define COLUNAS 16
#define LINHAS 2

//Constantes (Pinos digitais)
const int trig = 2;
const int echo = 3;  //PWM

LiquidCrystal_I2C lcd(ENDERECO, COLUNAS, LINHAS);

void setup() {

  // Inicializar Display
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // initialize serial communication:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  //Variaveis de distancias
  long duration = 0, inches = 0, cm = 0;

  //Gera um pulso no trig (disparo um som)
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  for (uint8_t i = 0; i < 3; i++) {

    //Lê o sinal do ping emitido pelo trig e retorna a duração é o tempo (em microssegundos) desde o envio do ping para a recepção de seu eco de um objeto.
    duration += pulseIn(echo, HIGH);

    delay(100);
  }

  duration = duration / 3;

  // Converter o tempo em distancia
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);



  Serial.print("Distancia media: ");
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("Distancia media: ");
  lcd.setCursor(0, 1);
  lcd.print(inches);
  lcd.setCursor(2, 1);
  lcd.print("in,");
  
  lcd.setCursor(6, 1);
  lcd.print(cm);
  lcd.setCursor(10, 1);
  lcd.print("cm");
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: https://www.parallax.com/package/ping-ultrasonic-distance-sensor-downloads/
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
