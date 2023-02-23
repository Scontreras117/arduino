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

// FUNCIONES /////////////////////////////////////////////////
void ir_a_s1(){
  while (digitalRead(s1) == LOW) {
    digitalWrite(girarizq,LOW);
    digitalWrite(girarder,HIGH);
  }
  digitalWrite(girarder,LOW);
}
//////
void ir_a_s2(){
  if (digitalRead(s1)) {
    while (digitalRead(s2) == LOW){
      digitalWrite(girarder,LOW);
      digitalWrite(girarizq,HIGH);
    } 
    digitalWrite(girarizq,LOW);
  }

  if ((digitalRead(s3) == HIGH)||(digitalRead(s4) == HIGH)) {
    while (digitalRead(s2) == LOW){
      digitalWrite(girarizq,LOW);
      digitalWrite(girarder,HIGH);
    } 
    digitalWrite(girarder,LOW);
  }
}
//////
void ir_a_s4(){
  while (digitalRead(s4) == LOW) {
    digitalWrite(girarizq,HIGH);
    digitalWrite(girarder,LOW);
  }
  digitalWrite(girarizq,LOW);
}
//////
void ir_a_s3(){
  if (digitalRead(s4)) {
    while (digitalRead(s3) == LOW){
      digitalWrite(girarizq,LOW);
      digitalWrite(girarder,HIGH);
    } 
    digitalWrite(girarder,LOW);
  }

  if ((digitalRead(s1) == HIGH)||(digitalRead(s2) == HIGH)) {
    while (digitalRead(s3) == LOW){
      digitalWrite(girarder,LOW);
      digitalWrite(girarizq,HIGH);
    } 
    digitalWrite(girarizq,LOW);
  }
}
// void regreso(origen){
//   switch (origen) {
//   case 'a':
//     // statements
//     break;
//   case 'b':
//     // statements
//     break;
//   case 'c':
//     // statements
//     break;
//   case 'd':
//     // statements
//     break;
// }  
// }

// LOOP //////////////////////////////////////////////////
void loop(){
    if (Serial3.available()>0)
    {
      destino=Serial3.parseInt();
      Serial.println(destino);
      if(destino==1)
       {
         ir_a_s1();
       }
        if(destino==2)
       {
         ir_a_s2();
       }
       if(destino==3)
       {
         ir_a_s3();
       }
       if(destino==4)
       {
         ir_a_s4();
       }
    }
}  




