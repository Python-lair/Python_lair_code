#include <LiquidCrystal_I2C.h> // Подключаем библиотеку для QAPASS 1602

const int mSensorPin = A0; // Задаем пин для датчика влажности почвы
const int wSensorPin = A1; // Задаем пин для датчика уровня воды
const int rPin = 8; // Задаем пин для реле
const int l1Pin = 3; // Задаем пин для светодиода
const int l2Pin = 4; // Задаем пин для светодиода
const int bPin = 6; // Задаем пин для кнопки

int displayPower = 0;
int prevBtnState = 0;

LiquidCrystal_I2C LCD(0x27,16,2); // присваиваем имя LCD для дисплея

void setup() {

  Serial.begin(9600);
  LCD.init(); // инициализация LCD дисплея
  LCD.backlight(); // включение подсветки дисплея

  pinMode(mSensorPin, INPUT);
  pinMode(wSensorPin, INPUT);
  pinMode(rPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(l1Pin, OUTPUT);
  pinMode(l2Pin, OUTPUT);
}

void loop() {
  
  int moisture = analogRead(mSensorPin);
  int water = analogRead(wSensorPin);
  Serial.println(moisture);
  Serial.println(moisture);

  if (moisture < 300) {
    digitalWrite(rPin, HIGH);
    digitalWrite(rPin, HIGH);
  }  

  else {
    digitalWrite(rPin, LOW);
    digitalWrite(l1Pin, LOW);
  }

  if (water < 100) {
    digitalWrite(l2Pin, HIGH);
  }  

  else {
    digitalWrite(l2Pin, LOW);
  }

//-----------------------------------------------------------------------------

  LCD.setCursor(0, 0);     // ставим курсор на 0 символ первой строки
  LCD.print("moisture: ");     // печатаем сообщение на первой строке
  LCD.print(moisture);

  LCD.setCursor(0, 1);     // ставим курсор на 0 символ второй строки
  LCD.print("water:  ");     // печатаем сообщение на первой строке
  LCD.print(water);

//-----------------------------------------------------------------------------

  int btnState = digitalRead(bPin);

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
