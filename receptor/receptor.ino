int destino;
int tiempo_pausa;
int arranque = 0;

int origen = 0;

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
void ir_a_s1() {
  while (digitalRead(s1) == LOW) {
    digitalWrite(girarizq, LOW);
    digitalWrite(girarder, HIGH);
  }
  digitalWrite(girarder, LOW);
}
//////
void ir_a_s2() {
  if (digitalRead(s1)) {
    while (digitalRead(s2) == LOW) {
      digitalWrite(girarder, LOW);
      digitalWrite(girarizq, HIGH);
    }
    digitalWrite(girarizq, LOW);
  }

  if ((digitalRead(s3) == HIGH) || (digitalRead(s4) == HIGH)) {
    while (digitalRead(s2) == LOW) {
      digitalWrite(girarizq, LOW);
      digitalWrite(girarder, HIGH);
    }
    digitalWrite(girarder, LOW);
  }
}
//////
void ir_a_s4() {
  while (digitalRead(s4) == LOW) {
    digitalWrite(girarizq, HIGH);
    digitalWrite(girarder, LOW);
  }
  digitalWrite(girarizq, LOW);
}
//////
void ir_a_s3() {
  if (digitalRead(s4)) {
    while (digitalRead(s3) == LOW) {
      digitalWrite(girarizq, LOW);
      digitalWrite(girarder, HIGH);
    }
    digitalWrite(girarder, LOW);
  }

  if ((digitalRead(s1) == HIGH) || (digitalRead(s2) == HIGH)) {
    while (digitalRead(s3) == LOW) {
      digitalWrite(girarder, LOW);
      digitalWrite(girarizq, HIGH);
    }
    digitalWrite(girarizq, LOW);
  }
}
///////
void leer_origen() {
  while (origen==0) {
    if (digitalRead(s1) == HIGH) {
      origen = 1;
    }
    if (digitalRead(s2) == HIGH) {
      origen = 2;
    }
    if (digitalRead(s3) == HIGH) {
      origen = 3;
    }
    if (digitalRead(s4) == HIGH) {
      origen = 4;
    }
  }
  Serial.println("origen:");
  Serial.println(origen);
}
//////
void regreso() {
  switch (origen) {
    case 1:
      ir_a_s1();
      break;
    case 2:
      ir_a_s2();
      break;
    case 3:
      ir_a_s3();
      break;
    case 4:
      ir_a_s4();
      break;
  }
}
//////
void leer_destino(){
  while (Serial3.available()==0) {
  }
  destino = Serial3.parseInt();
  Serial.println("destino:");
  Serial.println(destino);
}
//////
void leer_tiempo() {
  while (Serial3.available()==0) {
  }
  tiempo_pausa = Serial3.parseInt();
  Serial.println("tiempo de pausa:");
  Serial.println(tiempo_pausa);
}
///////
void leer_arranque() {
  while (Serial3.available()==0) {
  }
  arranque = Serial3.parseInt();
  Serial.println("arranque:");
  Serial.println(arranque);
}
///////
void pausa() {
  digitalWrite(girarizq, LOW);
  digitalWrite(girarder, LOW);

  int tiempo_anterior = millis();
  int tiempo_transcurrido = millis();
  while ((tiempo_transcurrido-tiempo_anterior) < tiempo_pausa*1000 ){
    tiempo_transcurrido = millis();
  }
}

// LOOP //////////////////////////////////////////////////
void loop() {
  leer_origen();
 
  leer_tiempo();

  leer_destino();

  leer_arranque();

  if (arranque==1) {
    if (destino == 1) {
      ir_a_s1();
    }
    if (destino == 2) {
      ir_a_s2();
    }
    if (destino == 3) {
      ir_a_s3();
    }
    if (destino == 4) {
      ir_a_s4();
    }
    pausa();
    regreso();
  }
}
