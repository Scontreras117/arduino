
int senal;
int envio;

byte origen;

void setup()
  {
    Serial.begin(9600);
    Serial3.begin(9600);
    Serial.print("Comenzamos");
}

///////////////// FUNCIONES //////////////////////////////////
void flush() {
  while (Serial.available()>0) {
      Serial.read();
  }
}
//////////
void pintar_led() {
  if (Serial3.available()>0) {
    senal = Serial3.parseInt();
    Serial.println('senal: ');
    Serial.println(senal);
  }
}



void loop(){
  if (Serial3.available()>0) {
    if (Serial.available()>0)
      {
        envio=Serial.parseInt();
        Serial3.print(envio);
        flush();
      }
  }
}
