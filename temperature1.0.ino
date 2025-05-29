#include <DHT.h> // подключаем библиотеку для датчика
#include <Wire.h> // библиотека для управления устройствами по I2C 
#include <LiquidCrystal_I2C.h> // подключаем библиотеку для QAPASS 1602

DHT dht(2, DHT11); // сообщаем на каком порту будет датчик
LiquidCrystal_I2C LCD(0x27,16,2); // присваиваем имя LCD для дисплея

void setup() {
  dht.begin(); // запускаем датчик DHT22
  Serial.begin(9600); // подключаем монитор порта


  LCD.init(); // инициализация LCD дисплея
  LCD.backlight(); // включение подсветки дисплея

}

void loop() {
  
  float t = dht.readTemperature(); // задать переменной t значение температуры с датчика
  float h = dht.readHumidity(); // задать переменной h значение влажности с датчика

  Serial.print("Temperature: ");
  Serial.print(t); // выводим температуру на консоль
  Serial.print("Humidity: ");
  Serial.print(h); // выводим влажность на консоль

  LCD.setCursor(0, 0);     // ставим курсор на 0 символ первой строки
  LCD.print("Temp: ");     // печатаем сообщение на первой строке
  LCD.print(t);
  LCD.print(" C");
  
  LCD.setCursor(0, 1);     // ставим курсор на 0 символ второй строки
  LCD.print("Hum:  ");     // печатаем сообщение на первой строке
  LCD.print(h);
  LCD.print(" %");

  delay(10000);

}



