int destino;
int origen;

int s1 = 30;
int s2 = 31;
int s3 = 32;
int s4 = 33;

int girarder = 22;
int girarizq = 23;

void setup() {
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);

  pinMode(girarder, OUTPUT);
  pinMode(girarizq, OUTPUT);

  Serial.begin(9600);
  Serial3.begin(9600);
  Serial.print("Comenzamos");
}

// FUNCIONES
void ir_a_s1(){
  while (digitalRead(s1) == LOW) {
    digitalWrite(girarizq,LOW);
    digitalWrite(girarder,HIGH);
  }
  digitalWrite(girarder,LOW);    
}




// LOOP
void loop(){
    if (Serial3.available()>0)
    {
      destino=Serial3.read();
      if(destino=='a')
       {
         ir_a_s1();
       }
       if(destino=='r')
       {
         analogWrite(4,255);
         analogWrite(3,0);
         analogWrite(2,0);
       }
       if(destino=='a')
       {
         analogWrite(2,255);
         analogWrite(4,0);
         analogWrite(3,0);
       }
    }
}  




