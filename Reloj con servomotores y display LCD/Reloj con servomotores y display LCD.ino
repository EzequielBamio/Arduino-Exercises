#include <LiquidCrystal.h>
#include <Servo.h>

#define BOTON_HOR 12
#define BOTON_MIN 11
#define BOTON_SEG 10
#define SERVO_HOR A1
#define SERVO_MIN A2
#define SERVO_SEG A3

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

Servo servo_A1;
Servo servo_A2;
Servo servo_A3;

int hor=23,min=59,seg=0;
int aum_hor=0;
int aum_min=0;
int aum_seg=0;

void relojEnCero()
{
  hor = 0;
  min = 0;
  seg = 0;
  servo_A1.write(0);
  servo_A2.write(0);
  servo_A3.write(0);
}
void mostrarHora(int hor, int min, int seg)
{
  //HORA
  if(hor < 10)
  {
    lcd.print('0');
  }
  lcd.print(hor);
  lcd.print(':');
  //MIN
  if(min < 10)
  {
    lcd.print('0');
  }
  lcd.print(min);
  lcd.print(':');
  //SEG
   if(seg < 10)
  {
    lcd.print('0');
  }
  lcd.print(seg);
}
void aumentarHora()
{
  aum_seg = digitalRead(BOTON_SEG);
  if(aum_seg == HIGH)
  {
    seg++;
  }
  aum_min = digitalRead(BOTON_MIN);
  if(aum_min == HIGH)
  {
    min++;
  }
  aum_hor = digitalRead(BOTON_HOR);
  if(aum_hor == HIGH)
  {
    hor++;
  }
}
void setup()
{
  servo_A1.attach(SERVO_HOR);
  servo_A2.attach(SERVO_MIN);
  servo_A3.attach(SERVO_SEG);
  lcd.begin(16, 2);
}

void loop()
{
  //POS DE CURSOR
  lcd.setCursor(3,1);

  mostrarHora(hor, min, seg);
  //
  servo_A3.write(seg*3);
  seg++;
  delay(20);
  if(seg > 59)
  {
  	seg = 0;
    min++;
    servo_A2.write(min*3);
  }
  if(min > 59)
  {
    min = 0;
  	hor++;
    servo_A1.write(hor*7.5);
  }
  if(hor > 23)
  {
    relojEnCero();
  }
  
  aumentarHora();
 
  
}