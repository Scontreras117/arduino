
int start;
int tope;
int pausa;

int destino;

byte origen;

void setup()
  {
    Serial.begin(9600);
    Serial3.begin(9600);
    Serial.print("Comenzamos");
}

void loop(){
  if (Serial.available()>0)
    {
      destino=Serial.parseInt();
      if(destino==1)
       {
         Serial3.print(1);
       }
       if(destino==2)
       {
         Serial3.print(2);
       }
       if(destino==3)
       {
         Serial3.print(3);
       }
       if(destino==4)
       {
         Serial3.print(4);
       }
    }
}