#include <DHT.h> // подключаем библиотеку для датчика
#include <Wire.h> // библиотека для управления устройствами по I2C 
#include <LiquidCrystal_I2C.h> // подключаем библиотеку для QAPASS 1602

DHT dht(2, DHT11); // сообщаем на каком порту будет датчик
LiquidCrystal_I2C LCD(0x27,16,2); // присваиваем имя LCD для дисплея

const int buttonPin = 6;

int displayPower = 0;
int prevBtnState = 0;

void setup() {
  dht.begin(); // запускаем датчик DHT 11
  Serial.begin(9600); // подключаем монитор порта


  LCD.init(); // инициализация LCD дисплея
  LCD.backlight(); // включение подсветки дисплея

  prevBtnState = digitalRead(buttonPin); 
}

void loop() {
  
  float t = dht.readTemperature(); // задать переменной t значение температуры с датчика
  float h = dht.readHumidity(); // задать переменной h значение влажности с датчика

  Serial.print("\n\rTemperature: ");
  Serial.print(t); // выводим температуру на консоль
  Serial.print("\n\rHumidity: ");
  Serial.print(h); // выводим влажность на консоль
  Serial.print("\n\r");
  //Serial.print();

  LCD.setCursor(0, 0);     // ставим курсор на 0 символ первой строки
  LCD.print("Temp: ");     // печатаем сообщение на первой строке
  LCD.print(t);
  LCD.print(" C");

  LCD.setCursor(0, 1);     // ставим курсор на 0 символ второй строки
  LCD.print("Hum:  ");     // печатаем сообщение на первой строке
  LCD.print(h);
  LCD.print(" %");



  int btnState = digitalRead(buttonPin);

  if (btnState == HIGH) { // проверяем состояние кнопки
    if (prevBtnState != btnState) { 
      if (displayPower == 0) { // проверяем включен ли дисплей
        LCD.backlight(); // включаем дисплей
        displayPower = 1;
      }      
      else {
        LCD.noBacklight(); //выключаем дисплей
        displayPower = 0;
      }
    }
  }

  prevBtnState = btnState;

}
