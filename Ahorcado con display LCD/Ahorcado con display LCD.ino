#include <LiquidCrystal.h>
#include <string.h>
#define NOBOTON 0
#define BOTON1 1
#define BOTON2 2
#define BOTON3 3
#define BOTON4 4
#define CANTIDADLETRAS 16

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup()
{
    pinMode(8, INPUT);
    pinMode(9, INPUT);
    pinMode(10, INPUT);
    lcd.begin(16, 2);
    lcd.setCursor(13,0);
    Serial.begin(9600);
}
char palabraOculta[CANTIDADLETRAS] = "A";
char letraActual = 'A';
int botonAntes = LOW;
int i;
int vidas = 3;
int letrasCorrectas = 0;
  
void loop()
{
  int restarLetra = digitalRead(8);
  int sumarLetra = digitalRead(10);
  int probarLetra = digitalRead(9);
  lcd.setCursor(15,1);
  lcd.print(vidas);
  mostrarLetraActual();
  if(controlarLetraActual(restarLetra, sumarLetra, probarLetra) == 0)
  {
    vidas--;
    if(vidas == 0)
    {
      lcd.clear();
      lcd.setCursor(4,1);
      lcd.print("PERDISTE");
      delay(500);
      lcd.clear();
      vidas = 3;
      letraActual = 'A';
    }
  }else
  {
    letrasCorrectas++;
    if(letrasCorrectas == CANTIDADLETRAS)
    {
      lcd.clear();
      lcd.setCursor(4,1);
      lcd.print("GANASTE");
      delay(500);
      lcd.clear();
      vidas = 3;
      letraActual = 'A';
    }
  }
  verificarBotonAntes(restarLetra, sumarLetra, probarLetra);
  
  
      
    

  delay(50);
  
}


int escribirLetras(char letraActual)
{
  int rtn = 0;
  for(int i=0;i<CANTIDADLETRAS;i++)
  {
    if(palabraOculta[i] == letraActual)
    {
      lcd.setCursor(i,1);
      lcd.print(letraActual);
      rtn = 1;
    }
  }
  return rtn;
}

void mostrarLetraActual()
{
  if(letraActual > 'Z')
  {
    letraActual = 'A';
  }
  else
  {
    if(letraActual < 'A')
    {
      letraActual = 'Z';
    }
  }
  lcd.setCursor(5,0);
  lcd.print(letraActual);
}

int controlarLetraActual(int restar, int sumar, int probar)
{
  int rtn;
  if(restar && botonAntes == LOW)
  {
    letraActual--;
  }
  
  if(sumar && botonAntes == LOW)
  {
    letraActual++;
  }
  
  if(probar && botonAntes == LOW)
  {
    rtn = escribirLetras(letraActual);
  }
  return rtn;
}

void verificarBotonAntes(int restar, int sumar, int probar)
{
  if(restar || sumar || probar)
  {
    botonAntes = HIGH;
  }
  else
  {
    botonAntes = LOW;
  }
}