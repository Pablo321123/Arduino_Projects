//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define ENDERECO 0x3f
#define COLUNAS 16
#define LINHAS 2

LiquidCrystal_I2C lcd(ENDERECO, COLUNAS, LINHAS); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
    lcd.init();      // INICIA A COMUNICAÇÃO COM O DISPLAY
    lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
    lcd.clear();     // LIMPA O DISPLAY

    lcd.print("- HELLO WORLD! -");
    delay(5000);         // DELAY DE 5 SEGUNDOS
    lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
    lcd.print("Fim do Setup ()");
    delay(5000); // DELAY DE 5 SEGUNDOS

    lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY
    delay(2000);       // DELAY DE 2 SEGUNDOS
    lcd.backlight();   // LIGA A ILUMINAÇÃO DO DISPLAY
    delay(2000);       // DELAY DE 2 SEGUNDOS

    lcd.clear(); // LIMPA O DISPLAY
                 //lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY

    // lcd.setCursor(3, 0);
    // lcd.print("Hello, world!");
    // lcd.setCursor(2, 1);
    // lcd.print("Arduino!");
}

void loop()
{
    //lcd.clear(); //Nao utilizar desta forma, pois faz com que os caracteres fique "piscando"
    lcd.print("- Ola, Mundo! -");
    lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
    lcd.print("Fim do Setup ()");
}