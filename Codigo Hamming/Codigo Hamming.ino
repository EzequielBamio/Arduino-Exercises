#define P1 6
#define P2 7
#define D3 8
#define P4 9
#define D5 10
#define D6 11
#define D7 12

#define paridadInput1 2
#define paridadInput2 A5
#define paridadInput4 A3

#define dateInput7 A0
#define dateInput6 A1
#define dateInput5 A2
#define dateInput3 A4

#define ENRX1 5 
#define ENRX2 4 
#define ENRX3 3 

void setup()
{
  for(int i = 3; i <= 12; i++)
  {
  	pinMode(i, OUTPUT);
  }
  
  pinMode(dateInput7, INPUT_PULLUP);
  pinMode(dateInput6, INPUT_PULLUP);
  pinMode(dateInput5, INPUT_PULLUP);
  pinMode(dateInput3, INPUT_PULLUP);
  pinMode(paridadInput4, INPUT_PULLUP);
  pinMode(paridadInput2, INPUT_PULLUP);
  pinMode(paridadInput1, INPUT_PULLUP);

}

void loop()
{
	onLamp();
  	//
    if(calculateParity(digitalRead(paridadInput1),digitalRead(dateInput3), digitalRead(dateInput5) ,digitalRead(dateInput7)) == 0)
    {
      digitalWrite(ENRX1, HIGH);

    }else
    {
      digitalWrite(ENRX1, LOW);;
    }
	//
  	//
    if(calculateParityWitchFive(digitalRead(paridadInput2),digitalRead(dateInput3), digitalRead(dateInput5), digitalRead(dateInput6), digitalRead(dateInput7)) == 0)
    {
      digitalWrite(ENRX2, HIGH);

    }else
    {
      digitalWrite(ENRX2, LOW);;
    }
	//
  	//
    if(calculateParity(digitalRead(paridadInput4),digitalRead(dateInput5), digitalRead(dateInput6) ,digitalRead(dateInput7)) == 0)
    {
      digitalWrite(ENRX3, HIGH);

    }else
    {
      digitalWrite(ENRX3, LOW);;
    }
	//

  
}

int calculateParityWitchFive(int d1, int d2, int d3, int d4, int d5)
{
	int rtn = 0;
  	int sumaTotal = d1+d2+d3+d4;
  	if(sumaTotal % 2 == 0)
  	{
    	rtn = 1;
  	}
  
  	return rtn;
}
int calculateParity(int d1, int d2, int d3, int d4)
{
	int rtn = 0;
  	int sumaTotal = d1+d2+d3+d4;
  	if(sumaTotal % 2 == 0)
  	{
    	rtn = 1;
  	}
  
  	return rtn;
}

void onLamp()
{
	digitalWrite(P1, digitalRead(paridadInput1));
  	digitalWrite(P2, digitalRead(paridadInput2));    
	digitalWrite(P4, digitalRead(paridadInput4));
  
  	digitalWrite(D3, digitalRead(dateInput3));    
	digitalWrite(D5, digitalRead(dateInput5)); 
  	digitalWrite(D6, digitalRead(dateInput6));    
	digitalWrite(D7, digitalRead(dateInput7)); 
}