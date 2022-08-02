#define ENDERECO 0x3f
#define COLUNA 16
#define LINHA 2

#include <Wire.h> //Responsavel pela comunicacao I2C (Comunicacao Serial)
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(ENDERECO, COLUNA, LINHA);
int a = 0;

void setup()
{
    Serial.begin(9600);

    lcd.init();
    lcd.backlight();
    lcd.clear();
}

void loop()
{
    int pontos = 0;

    while (pontos < 3)
    {
        lcd.setCursor(0, 0);
        lcd.print(millis() / 1000);

        lcd.setCursor(0, 1);
        lcd.print("Segundos");

        lcd.setCursor(8, 1);
        lcd.print(pontos == 0 ? "." : pontos == 1 ? ".."
                                                  : "...");

        Serial.println(pontos);

        pontos++;
        delay(1000);
        //a = Serial.read();
    }
    lcd.clear();
}
