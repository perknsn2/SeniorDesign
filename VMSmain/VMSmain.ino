//VMS Main Code V0.1
//Debug version

#include <SoftwareSerial.h> //Using software serial to connect to UART devices

//Software Serial Pins
#define ESP_TX 4
#define ESP_RX 5

//SSID + KEY
const char SSID_ESP[] = "Test";
const char SSID_KEY[] = "helloworld";

SoftwareSerial ESP(ESP_RX, ESP_TX); //Define ESP8266

//Function Definitions
boolean setup_ESP();
void postData();

//Global Veriables
int post = 0;

void setup(){
    //Setting up input and output pins
    pinMode(ESP_RX, INPUT);
    pinMode(ESP_TX, OUTPUT);
    ESP.begin(115200); //Initialize communication with ESP8266
    //ESP.listen();
    Serial.begin(115200); //Initialize debug serial
    Serial.println("Starting setup"); 
    delay(2000);
    setup_ESP(); 
    Serial.println("Finished setup"); 
}

void loop(){
  Serial.println("Starting loop"); 
  if( post == 10)
    post = 0;
  postData(false, false, post);
  post++;
  delay(7000);
}


