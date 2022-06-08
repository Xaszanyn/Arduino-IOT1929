#include "WiFiEsp.h"
#include "secrets.h"
#include "ThingSpeak.h"

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
int keyIndex = 0;
WiFiEspClient  client;

#ifndef HAVE_HWSERIAL1
#include "SoftwareSerial.h"
SoftwareSerial Serial1(6, 7);
#define ESP_BAUDRATE  19200
#else
#define ESP_BAUDRATE  115200
#endif

unsigned long counterChannelNumber = SECRET_CH_ID_COUNTER;
const char * myCounterReadAPIKey = SECRET_READ_APIKEY_COUNTER;
unsigned int counterFieldNumber = 1; 

long current = 0;

void setup() {
  Serial.begin(115200);  
  while(!Serial){ ; }
  
  setEspBaudRate(ESP_BAUDRATE);

  while (!Serial){ ; }

  Serial.print("Searching for ESP8266...");
  
  WiFi.init(&Serial1);

  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);
  }
  Serial.println("found it!");
  play(220.00, 100);
  play(277.18, 100);
  lastplay(246.94, 100);
    
  ThingSpeak.begin(client);
}

void loop() {

  int statusCode = 0;
  
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);
      play(233.08, 100);
      play(293.66, 100);
      lastplay(261.63, 100);
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected");
    for(int hz = 220; hz <= 276; hz ++) {
      play(hz, 5);
    }
    play(277.18, 15);
    play(329.63, 100);
    lastplay(440.00, 300);
  }

  long count = ThingSpeak.readLongField(counterChannelNumber, counterFieldNumber, myCounterReadAPIKey);  

  statusCode = ThingSpeak.getLastReadStatus();
  if(statusCode == 200){
    Serial.println("Counter: " + String(count));
  }
  else{
    Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
  }

  if(current != 0 && current != count) {
    Serial.println("<<< New order! >>>");
    play(440.00, 100);
    play(739.99, 100);
    play(493.88, 100);
    play(659.25, 100);
    lastplay(554.37, 200);
  }

  current = count;
  
  delay(15000);
}

void setEspBaudRate(unsigned long baudrate){
  long rates[6] = {115200,74880,57600,38400,19200,9600};

  Serial.print("Setting ESP8266 baudrate to ");
  Serial.print(baudrate);
  Serial.println("...");
  lastplay(220.00, 100);
  delay(100);
  lastplay(220.00, 100);

  for(int i = 0; i < 6; i++){
    Serial1.begin(rates[i]);
    delay(100);
    Serial1.print("AT+UART_DEF=");
    Serial1.print(baudrate);
    Serial1.print(",8,1,0,0\r\n");
    delay(100);  
  }
    
  Serial1.begin(baudrate);
}

void play(int note, int duration){
  tone(9, note);
  delay(duration);
}
void lastplay(int note, int duration){
  tone(9, note);
  delay(duration);
  noTone(9);
}
