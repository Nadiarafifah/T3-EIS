#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
#define PIR_sensor A0
#define m11 0
#define m12 1
int hp;
void setup()
{
  lcd.begin(16, 2);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(PIR_sensor, INPUT);
  lcd.print(" PROJECT EIS ");
  lcd.setCursor(0, 1);
  lcd.print(" PINTU OTOMATIS ");
  delay(200);
  lcd.clear();
  lcd.print("MULAI");
  delay(150);
}
bool i;

void loop()
{
  hp = digitalRead(PIR_sensor);

      while(hp==1)
        {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Lewat");
          lcd.setCursor(0, 1);
          lcd.print(" pintu terbuka ");
          digitalWrite(m11, HIGH); // pintu terbuka
          digitalWrite(m12, LOW);
          delay(500);
          i = false;
          break;
        }
       while (hp==0)
        {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(" Tidak lewat ");
          lcd.setCursor(0,1);
          lcd.print(" Pintu tertutup ");
          digitalWrite(m11, LOW); // Pintu tertutup
          digitalWrite(m12, LOW);
          delay(300);
          i = true;
          break;
        }
      
}