#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define ENDERECO 0x3f
#define COLUNAS 16
#define LINHAS 2

String leitura = "";
bool valueEntered = false;

LiquidCrystal_I2C lcd(ENDERECO, COLUNAS, LINHAS);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void horizontalScroll(String texto, byte index, int linha) {
  texto = texto + "  ";
  lcd.setCursor(0, linha);

  while (1) {
    if (index >= texto.length()) {
      index = 0;
    }

    if (Serial.available() > 0) {
      valueEntered = true;
      break;
    } else {
      lcd.setCursor(0, linha);
      String impressao = texto.substring(index) + texto.substring(index, 0);
      lcd.print(impressao);
      delay(750);
      index++;
    }
  }
}

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Ola, Pablo!");

  lcd.setCursor(0, 1);
  lcd.print("Tudo bom?");

  delay(3000);
}

void loop() {
  if (!valueEntered) {
    String texto = "Digite algo na Serial!";
    lcd.setCursor(0, 1);
    lcd.print(texto);

    byte tamanho = texto.length();

    for (byte i = 0; (i < tamanho) && (!valueEntered); i++) {
      lcd.clear();

      //Linha 0, apresentacao "estatica"
      lcd.setCursor(0, 0);
      lcd.print("Ola, Pablo!");

      horizontalScroll(texto, i, 1);
    }
  } else {
    leitura = "";
    if (Serial.available() > 0)  // 'Serial.available()' Monitora se algo foi enviado para porta serial
    {
      lcd.clear();
      leitura = Serial.readString();
      Serial.println(leitura);

      byte tamanho = leitura.length();

      if (tamanho >= 16) {
        // for (byte i = 0; i < tamanho; i++)
        // {
              horizontalScroll(leitura, 0, 0); //Scroll horizontal para o texto (texto rolando para esquerda)
        // }
      } else {
        lcd.setCursor(0, 0);
        lcd.print(leitura);
      }
    }
    valueEntered = true;
  }
}
