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

void loop(){
    if (Serial3.available()>0)
    {
      destino=Serial3.read();
      if(destino=='a')
       {
         digitalWrite(girarder,LOW);
         digitalWrite(girarizq,HIGH);
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







// /////////////////////////////////////////////////////////////77
ir_a_s1(origen);
   Serial.println("Yendo al S1");
   switch (origen) {
    case label1:
      // statements
      break;
    case label2:
      // statements
      break;
    default:
      // statements
      break;
  }
    
  
  }



