
int start;
int tope;
int pausa;

int envio;

byte origen;

void setup()
  {
    Serial.begin(9600);
    Serial3.begin(9600);
    Serial.print("Comenzamos");
}

void flush() {
  while (Serial.available()>0) {
      Serial.read();
  }
}

void loop(){
  if (Serial.available()>0)
    {
      envio=Serial.parseInt();
      Serial3.print(envio);
      flush();
    }
}