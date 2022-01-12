#define B 13
#define A 12
#define F 11
#define G 10
#define E 9
#define D 8
#define C 7

void setup()
{
  for(int i = 7; i <= 13; i++)
  {
  	pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}
int temp;
void loop()
{
  temp = map(analogRead(A0),20,358,-40,125);
  if(temp < 0)
  {
  	showDigit('f');
  }else 
  {
    if(temp > 25)
  	{
      showDigit('c');
  	}else
  	{
      showDigit('d');
  	}
  }
  
  
  Serial.println(temp);
  delay(200);
	
}

void showDigit(char digit)
{
	digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
  	digitalWrite(D, LOW);
  	digitalWrite(E, LOW);
  	digitalWrite(F, LOW);
  	digitalWrite(G, LOW);
  
  switch(digit)
  {
  	case 'f':
    	digitalWrite(A, HIGH);
        digitalWrite(F, HIGH);
    	digitalWrite(E, HIGH);
    	digitalWrite(G, HIGH);
    break;
    case 'c': 
        digitalWrite(A, HIGH);
        digitalWrite(F, HIGH);
    	digitalWrite(E, HIGH);
    	digitalWrite(D, HIGH);
    break;
    case 'd':
        digitalWrite(G, HIGH);
    break;
  }
}