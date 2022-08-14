#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


bool alon = true;
int tempo = 120;

int buzzer = 11;

#include "Wire.h"
const int MPU_ADDR = 0x68;
int16_t accelerometer_x, accelerometer_y, accelerometer_z;
int16_t gyro_x, gyro_y, gyro_z;
int16_t temperature;
char tmp_str[7];
char* convert_int16_to_str(int16_t i) {
  sprintf(tmp_str, "%6d", i);
  return tmp_str;
}
int melody[] = {
  

  
  NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
  NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
  NOTE_A4,4, NOTE_A4,4, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16,

  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,//4
  NOTE_E5,4, NOTE_E5,4, NOTE_E5,4, NOTE_F5,-8, NOTE_C5,16,
  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
  
  NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
  NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,

  NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
  NOTE_C5,4, NOTE_A4,-8, NOTE_C5,16, NOTE_E5,2,

  NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
  NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,

  NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
  
};


int notes = sizeof(melody) / sizeof(melody[0]) / 2;


int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

#include <Wire.h>
#include <ds3231.h>
#include <LiquidCrystal.h>
int VRx = A0;
int VRy = A1;
int SW = 6;
int pot1 = A3;
int pot2 = A4;
int hr;
int bm;
int buzz = 9;
int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;
bool alar = false;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include <dht.h>
#include <Servo.h>

Servo myservo; 
int pos = 0;
int sw;
#define dht_apin A2 // Analog Pin sensor is connected to
 
dht DHT;
struct ts t; 
char state = 't';
int hours;
int minutes;
#include <Servo.h>



void setup() {
  delay(500);
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  myservo.attach(9);
  Wire.endTransmission(true);
  DS3231_init(DS3231_CONTROL_INTCN);
  lcd.begin(16, 2);
  pinMode(SW, INPUT_PULLUP);
  pinMode(buzz, OUTPUT);
  digitalWrite(buzz, LOW);
}
 
void loop() {
  
  while(state == 't')
  {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);

  if(mapX > 400)
  {
    state = 'h';
  }
  if(mapX < -400)
  {
    state = 'p';
  }
  if(mapY >  400)
  {
    state = 'a';
  }
  DS3231_get(&t);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(t.mday);
  lcd.print("/");
  lcd.print(t.mon);
  lcd.print("/");
  lcd.print(t.year);
  lcd.setCursor(0, 1);
  lcd.print(t.hour);
  lcd.print(":");
  if(t.min < 10)
  {
    lcd.print("0");
  }
  lcd.print(t.min);
  lcd.print(":");
  if(t.sec < 10)
  {
    lcd.print("0");
  }
  lcd.print(t.sec);
  if(alar && t.hour == hours && minutes == t.min)
  {
    alarm();
    alar = false;
    alon = true;
  }
  if(t.hour < 10)
  {
    lcd.print("       :)");
  }
  else
  {
    lcd.print("      :)");
  }
  delay(1000);
  }
  if(state == 'h')
  {
    lcd.clear();
    for(int i = 0; i <= 20; i++)
    {
      DHT.read11(dht_apin);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(DHT.temperature);
      lcd.print((char)223);
      lcd.print("C");
      lcd.setCursor(0,1);
      lcd.print(DHT.humidity);
      lcd.print("%");
      if(DHT.temperature > 25)
      {
        lcd.setCursor(9,0);
        lcd.print("reduce");
        lcd.setCursor(9,1);
        lcd.print("temp");
      }
      else if(DHT.temperature < 20)
      {
        lcd.setCursor(9,0);
        lcd.print("raise");
        lcd.setCursor(9,1);
        lcd.print("temp");
      }
      delay(500);
    }
    state = 't';
    lcd.clear();
  }
  if(state == 'a')
  {
    for(int i = 0; i < 100; i++)
     {
      int temph = analogRead(pot1);
  int tempm = analogRead(pot2);
  hours = map(temph, 0, 1023, -1, 25);
  minutes = map(tempm, 0, 1023, -1, 63);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Hour: ");
  lcd.print(hours);
  lcd.setCursor(0,1);
  lcd.print("Minute: ");
  lcd.print(minutes);
  delay(200);
  
     }
     alar = true;
     state = 't';
  }
  if(state == 'p')
  {
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Pomodoro");
    delay(3000);
     for(int i = 0; i < 75; i++)
     {
      int temph = analogRead(pot1);
  int tempm = analogRead(pot2);
  hr = map(temph, 0, 1023, 20, 46);
  bm = map(tempm, 0, 1023, 3, 11);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Work: ");
  lcd.print(hr);
  lcd.setCursor(0,1);
  lcd.print("Break: ");
  lcd.print(bm);
  delay(100) ;
     }
     for (pos = 0; pos <= 180; pos += 1) { //open
    myservo.write(pos);             
  }

digitalWrite(buzz, HIGH);
delay(1000);
digitalWrite(buzz, LOW);
  for (pos = 180; pos >= 0; pos -= 1) { //close
    myservo.write(pos);                                 
  }
sw = analogRead(A7);

     while(sw < 500)
     {
      lcd.clear();
      for(int t = 0; t< hr; t++)
      {
         lcd.setCursor(6,0);
         lcd.print("Work");
               lcd.setCursor(5,1);
      if(t < 10)
      {
        lcd.print("0");
      }
      lcd.print(t);
      lcd.print(":");
         for(int s = 0; s < 60; s++)
         {
          sw = analogRead(A7);

          if(sw > 500)
          {
            lcd.clear();
            state = 't';
            break; 
          }
         lcd.setCursor(8,1);
         if(s < 10)
         {
          lcd.print("0");
         }
         lcd.print(s);
         delay(1000);
      }

     }
for (pos = 0; pos <= 180; pos += 1) { //open
    myservo.write(pos);             
  }

digitalWrite(buzz, HIGH);
delay(1000);
digitalWrite(buzz, LOW);

     for(int t = 0; t< bm; t++)
      {
         lcd.setCursor(5,0);
         lcd.print("Break");
               lcd.setCursor(5,1);
      if(t < 10)
      {
        lcd.print("0");
      }
      lcd.print(t);
      lcd.print(":");
         for(int s = 0; s < 60; s++)
         {
          sw = analogRead(A7);

          if(sw > 500)
          {
            lcd.clear();
            state = 't';
            break; 
          }
         lcd.setCursor(8,1);
         if(s < 10)
         {
          lcd.print("0");
         }
         lcd.print(s);
         delay(1000);
      }

     }
     digitalWrite(buzz, HIGH);
delay(1000);
digitalWrite(buzz, LOW);
delay(2000);
       for (pos = 180; pos >= 0; pos -= 1) { //close
    myservo.write(pos);                                 
  }
     }
     state = 't';
  }
}

void alarm()
{
  lcd.clear();
  lcd.print("WAKE UP!!");
 

  while(alon)
  {
    Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 7*2, true);
 
 
  accelerometer_x = Wire.read()<<8 | Wire.read();
  accelerometer_y = Wire.read()<<8 | Wire.read();
  accelerometer_z = Wire.read()<<8 | Wire.read();
  temperature = Wire.read()<<8 | Wire.read();
  gyro_x = Wire.read()<<8 | Wire.read();
  gyro_y = Wire.read()<<8 | Wire.read();
  gyro_z = Wire.read()<<8 | Wire.read();
  int a = ((accelerometer_x/1000)*(accelerometer_y/1000)*(accelerometer_z/1000));
  delay(5000);
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 7*2, true);
 
 
  accelerometer_x = Wire.read()<<8 | Wire.read();
  accelerometer_y = Wire.read()<<8 | Wire.read();
  accelerometer_z = Wire.read()<<8 | Wire.read();
  temperature = Wire.read()<<8 | Wire.read();
  gyro_x = Wire.read()<<8 | Wire.read();
  gyro_y = Wire.read()<<8 | Wire.read();
  gyro_z = Wire.read()<<8 | Wire.read();

  int b = ((accelerometer_x/1000)*(accelerometer_y/1000)*(accelerometer_z/1000));
  if(abs(a-b)>300)
  {
  alon = false;
  }
  else
  {
   alon = true;
  }  
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    divider = melody[thisNote + 1];
    if (divider > 0) {

      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {

      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; 
    }


    tone(buzz, melody[thisNote], noteDuration*0.9);


    delay(noteDuration);


    noTone(buzz);
  }
  }
}
