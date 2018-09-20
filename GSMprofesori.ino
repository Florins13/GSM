#define BUZZER 13
#define SENSORPIN 4
#include <SoftwareSerial.h>
SoftwareSerial modem(2, 3); // RX | TX

int sensorState = 0, lastState=0;         // variable for reading the pushbutton status
 
void setup() {
  delay(2000);
  pinMode(BUZZER, OUTPUT);      
  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); 
  
  Serial.begin(57600);
  Serial.println("Modem test");
  modem.begin(57600); // 38400 / 9600 / 19200
  delay(1000);
  modem.print("AT+CSCS=\"GSM\"\r"); //
  delay(1000);
  modem.print("AT+CMGF=1\r");    // tip text
  
}
 
void loop(){
  while (Serial.available() > 0) {
    modem.write(Serial.read());

  }

  while (modem.available() > 0) {
    Serial.write(modem.read());
  } 
  sensorState = digitalRead(SENSORPIN); // just for test
  Serial.println("valoare="); // just for testing
  Serial.println(sensorState); // just for testing
 
  if (sensorState == LOW) {       
    digitalWrite(BUZZER, LOW);
    mesaj1();
    mesaj2(); 
    mesaj3();
    mesaj4();
    mesaj5();
    mesaj6(); 
  } 
  else {
    // turn LED off:
    digitalWrite(BUZZER, HIGH); 
  }
  
  if (sensorState && !lastState) {
    Serial.println("Unbroken");
  } 
  if (!sensorState && lastState) {
    Serial.println("Broken");
  }
  lastState = sensorState;
}


void mesaj1(){
 // modem.print("AT+CSCS=\"GSM\"\r"); //
  //delay(500);
  modem.print("AT+CMGF=1\r");    // tip text
  delay(500);
  modem.print("AT+CMGS=\"+40xxxxxxxxx\"\r");    // Numarul de telefon la care urmeaza sa fie trimis mesajul
  delay(500);
  modem.print("Mesaj1 \r");   // Textul mesajului
  delay(500);
  modem.write(0x1A);  //comandă pentru trimiterea unui mesaj text CTRL-Z
  modem.write(26);
  delay(1000);
}

void mesaj2(){
 // modem.print("AT+CSCS=\"GSM\"\r"); //
 // delay(500);
  modem.print("AT+CMGF=1\r");    // tip text
  delay(500);
  modem.print("AT+CMGS=\"+40xxxxxxxxx\"\r");    // Numarul de telefon la care urmeaza sa fie trimis mesajul
  delay(500);
  modem.print("Mesaj2 \r");   // Textul mesajului
  delay(500);
  modem.write(0x1A);  //comandă pentru trimiterea unui mesaj text CTRL-Z
  modem.write(26);
  delay(1000);  
}

void mesaj3(){
 // modem.print("AT+CSCS=\"GSM\"\r"); //
 // delay(500);
  modem.print("AT+CMGF=1\r");    // tip text
  delay(500);
  modem.print("AT+CMGS=\"+40xxxxxxxxx\"\r");    // Numarul de telefon la care urmeaza sa fie trimis mesajul
  delay(500);
  modem.print("Mesaj3 \r");   // Textul mesajului
  delay(500);
  modem.write(0x1A);  //comandă pentru trimiterea unui mesaj text CTRL-Z
  modem.write(26);
  delay(1000);  
}

void mesaj4(){
 // modem.print("AT+CSCS=\"GSM\"\r"); //
 // delay(500);
  modem.print("AT+CMGF=1\r");    // tip text
  delay(500);
  modem.print("AT+CMGS=\"+40xxxxxxxxx\"\r");    // Numarul de telefon la care urmeaza sa fie trimis mesajul
  delay(500);
  modem.print("Mesaj4 \r");   // Textul mesajului
  delay(500);
  modem.write(0x1A);  //comandă pentru trimiterea unui mesaj text CTRL-Z
  modem.write(26);
  delay(1000);  
}

void mesaj5(){
 // modem.print("AT+CSCS=\"GSM\"\r"); //
 // delay(500);
  modem.print("AT+CMGF=1\r");    // tip text
  delay(500);
  modem.print("AT+CMGS=\"+40xxxxxxxxx\"\r");    // Numarul de telefon la care urmeaza sa fie trimis mesajul
  delay(500);
  modem.print("Mesaj5 \r");   // Textul mesajului
  delay(500);
  modem.write(0x1A);  //comandă pentru trimiterea unui mesaj text CTRL-Z
  modem.write(26);
  delay(1000);
 
}

void mesaj6(){
 // modem.print("AT+CSCS=\"GSM\"\r"); //
 // delay(500);
  modem.print("AT+CMGF=1\r");    // tip text
  delay(500);
  modem.print("AT+CMGS=\"+40xxxxxxxxx\"\r");    // Numarul de telefon la care urmeaza sa fie trimis mesajul
  delay(500);
  modem.print("Mesaj6\r");   // Textul mesajului
  delay(500);
  modem.write(0x1A);  //comandă pentru trimiterea unui mesaj text CTRL-Z
  modem.write(26);
  delay(1000);  
}

