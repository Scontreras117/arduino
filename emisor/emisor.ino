
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
      destino=Serial.read();
      if(destino=='a')
       {
         Serial3.print('a');
       }
       if(destino=='b')
       {
         Serial3.print('b');
       }
       if(destino=='c')
       {
         Serial3.print('c');
       }
       if(destino=='d')
       {
         Serial3.print('d');
       }
    }
}