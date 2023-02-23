int s1 = 30;
int s2 = 31;
int s3 = 32;
int s4 = 33;
int start = 37;
int tope = 36;
int pausa = 35;
int girarder = 22;
int girarizq = 23;
int indefinido;
byte origen;



void setup() {
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(start, INPUT);
  pinMode(tope, INPUT);
  pinMode(pausa, INPUT);
  pinMode(girarder, OUTPUT);
  pinMode(girarizq, OUTPUT);
  Serial.begin(9600);
}

void  funcion1()
{
  if(digitalRead(s2)==1)
  {
    origen=2;
  }
  if(digitalRead(s3)==1)
  {
    origen=3;
  }
  while((digitalRead(s4)==0)&&(digitalRead(pausa)==0)&& (origen==2))
  {
    digitalWrite(girarder,0);
    digitalWrite(girarizq,1);
  }
  digitalWrite(girarder,0);
  digitalWrite(girarizq,0);


  if(origen==2)
  {
    while((digitalRead(s4)==0)&&(digitalRead(pausa)==0)&&(origen==3))
  {
    digitalWrite(girarder,1);
    digitalWrite(girarizq,0);
  }
  digitalWrite(girarder,0);
  digitalWrite(girarizq,0);
  }
}

void funcion2()
{
  if ((digitalRead(pausa)==1)&& digitalRead(girarder)==1)
    {
     while (digitalRead(start)==1)
      {
      digitalWrite(girarder,1);
      digitalWrite(girarizq,0);
      }
    
   digitalWrite (girarder,0);
   digitalWrite (girarizq,0);}

   if ((digitalRead(pausa)==1)&& digitalRead(girarizq)==1)
    {
      while (digitalRead(start)==1)
      {
      digitalWrite(girarder,0);
      digitalWrite(girarizq,1);
      }
    
   digitalWrite (girarder,0);
   digitalWrite (girarizq,0);}
}



void loop() 
{
  if(((digitalRead(start)==1)&&(digitalRead(pausa)==0)&&(digitalRead(s2)==1)||(digitalRead(s3)==1)))
  {
  
  funcion1();
   
   Serial.println("la banda gira a la izquuierda");
   
    
  
  }
  if(((digitalRead(start)==1)&&(digitalRead(pausa)==0)&&(digitalRead(s2)==0)||(digitalRead(s3)==1)))
  {
  
  funcion1();
   
   Serial.println("la banda gira a la derecha");
   
    
  
  }
  if((digitalRead(start)==1)&&(digitalRead(pausa)==0)&&((digitalRead(s1)==1)||(digitalRead(s3)==1)))
  {

    funcion2();
  
   Serial.println("la banda esta en pausa");
  }

  
   
  }