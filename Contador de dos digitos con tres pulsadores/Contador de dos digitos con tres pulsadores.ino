#define A 12
#define B 13
#define C 7
#define D 8
#define E 9
#define F 11
#define G 10
#define SUBE 4
#define BAJA 3
#define RESET 5
#define DECENA A5
#define UNIDAD A4
#define APAGADOS 0
#define TIMEDISPLAYON 10

void setup()
{
  Serial.begin(9600);
  
  pinMode(BAJA, INPUT_PULLUP);
  pinMode(SUBE, INPUT_PULLUP);
  pinMode(RESET, INPUT_PULLUP);
  
  for(int i = 7; i <= 13; i++)
  {
  	pinMode(i, OUTPUT);
  }
  
  pinMode(UNIDAD, OUTPUT);
  pinMode(DECENA, OUTPUT);
  
  digitalWrite(UNIDAD, 0);
  digitalWrite(DECENA, 0);
  showNumber(0);
}

int countDigit = 0;
int valueSube = 1;
int valueBaja = 1;
int valueReset = 1;
int subePrevia = 1;
int bajaPrevia = 1;
int resetPrevia = 1;

void loop()
{
  int press = keyPress();
  
  if(press == SUBE)
  {
  	countDigit++;
    if(countDigit > 99)
    {
      countDigit = 0;
    }
  }
  if(press == BAJA)
  {
  	countDigit--;
    if(countDigit < 0)
    {
      countDigit = 99;
    }
  }
  if(press == RESET)
  {
  	countDigit = 0;
  }
 
  printCount(countDigit);
  
}

void printCount(int c) 
{
  	onDigit(APAGADOS);
	showNumber(c/10);
  	onDigit(DECENA);
    onDigit(APAGADOS);
 	showNumber(c - 10*((int)c/10));
  	onDigit(UNIDAD); 
   
}

int keyPress()
{ 
  int rtn = 0;
  valueSube = digitalRead(SUBE);
  valueBaja = digitalRead(BAJA);
  valueReset = digitalRead(RESET);
 
  if(valueSube == 1)  
  {
    subePrevia = 1; 
  }
  if(valueBaja == 1)
  {
  	bajaPrevia = 1;
  } 
  if(valueReset == 1)
  {
  	resetPrevia = 1;
  }
	 
  if(valueSube == 0 && valueSube != subePrevia)
  {
    subePrevia = valueSube;
    rtn = SUBE;
  }

  if(valueBaja == 0 && valueBaja != bajaPrevia)
  {
    bajaPrevia = valueBaja;
    rtn = BAJA;
  }

  if(valueReset == 0 && valueReset != resetPrevia)
  {
    resetPrevia = valueReset;
    rtn = RESET;
  }
  
 return rtn;
 
}

void onDigit(int digito)
{
	if (digito == UNIDAD)
    {
        digitalWrite(UNIDAD, 0); 
        digitalWrite(DECENA, 1);
      	delay(TIMEDISPLAYON);
    }else 
    {
      if (digito == DECENA)
      {
      	digitalWrite(UNIDAD, 1);
        digitalWrite(DECENA, 0);
      	delay(TIMEDISPLAYON);
      }else
      {
        digitalWrite(UNIDAD, 1);
        digitalWrite(DECENA, 1);
      }
    }
}



void showNumber(int number)
{
  switch(number)
  {
  	case 0:
    	showNumberZero();
    break;
    case 1:
    	showNumberOne();
    break;
    case 2:
    	showNumberTwo();
    break;
    case 3:
    	showNumberThree();
    break;
    case 4:
    	showNumberFour();
    break;
    case 5:
    	showNumberFive();
    break;
    case 6:
    	showNumberSix();
    break;
    case 7:
    	showNumberSeven();
    break;
    case 8:
    	showNumberEight();
    break;
    case 9:
    	showNumberNine();
    break;
  }
}

void showNumberZero()
{
  	digitalWrite(A, HIGH);
  	digitalWrite(F, HIGH);
  	digitalWrite(B, HIGH);
  	digitalWrite(G, LOW);
  	digitalWrite(C, HIGH);
	digitalWrite(E, HIGH);
	digitalWrite(D, HIGH);
}
void showNumberOne()
{
  	digitalWrite(A, LOW);
  	digitalWrite(F, LOW);
  	digitalWrite(B, HIGH);
  	digitalWrite(G, LOW);
  	digitalWrite(C, HIGH);
	digitalWrite(E, LOW);
	digitalWrite(D, LOW);
}
void showNumberTwo()
{
  	digitalWrite(A, HIGH);
  	digitalWrite(F, LOW);
  	digitalWrite(B, HIGH);
  	digitalWrite(G, HIGH);
  	digitalWrite(C, LOW);
	digitalWrite(E, HIGH);
	digitalWrite(D, HIGH);
}
void showNumberThree()
{
  	digitalWrite(A, HIGH);
  	digitalWrite(F, LOW);
  	digitalWrite(B, HIGH);
  	digitalWrite(G, HIGH);
  	digitalWrite(C, HIGH);
	digitalWrite(E, LOW);
	digitalWrite(D, HIGH);
}
void showNumberFour()
{
  	digitalWrite(A, LOW);
  	digitalWrite(F, HIGH);
  	digitalWrite(B, HIGH);
  	digitalWrite(G, HIGH);
  	digitalWrite(C, HIGH);
	digitalWrite(E, LOW);
	digitalWrite(D, LOW);
}
void showNumberFive()
{
  	digitalWrite(A, HIGH);
  	digitalWrite(F, HIGH);
  	digitalWrite(B, LOW);
  	digitalWrite(G, HIGH);
  	digitalWrite(C, HIGH);
	digitalWrite(E, LOW);
	digitalWrite(D, HIGH);
}
void showNumberSix()
{
  	digitalWrite(A, LOW);
  	digitalWrite(F, HIGH);
  	digitalWrite(B, LOW);
  	digitalWrite(G, HIGH);
  	digitalWrite(C, HIGH);
	digitalWrite(E, HIGH);
	digitalWrite(D, HIGH);
}
void showNumberSeven()
{
  	digitalWrite(A, HIGH);
  	digitalWrite(F, LOW);
  	digitalWrite(B, HIGH);
  	digitalWrite(G, LOW);
  	digitalWrite(C, HIGH);
	digitalWrite(E, LOW);
	digitalWrite(D, LOW);
}
void showNumberEight()
{
  	digitalWrite(A, HIGH);
  	digitalWrite(F, HIGH);
  	digitalWrite(B, HIGH);
  	digitalWrite(G, HIGH);
  	digitalWrite(C, HIGH);
	digitalWrite(E, HIGH);
	digitalWrite(D, HIGH);
}
void showNumberNine()
{
  	digitalWrite(A, HIGH);
  	digitalWrite(F, HIGH);
  	digitalWrite(B, HIGH);
  	digitalWrite(G, HIGH);
  	digitalWrite(C, HIGH);
	digitalWrite(E, LOW);
	digitalWrite(D, HIGH);
}