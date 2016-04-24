//VMS Main Code V0.1
//Debug version

#include <SoftwareSerial.h> //Using software serial to connect to UART devices

//Software Serial Pins
#define ESP_TX 4
#define ESP_RX 5

//SSID + KEY
const char SSID_ESP[] = "CentralPerk";
const char SSID_KEY[] = "smellycat";

SoftwareSerial ESP(ESP_RX, ESP_TX); //Define ESP8266

//Function Definitions
boolean setup_ESP();
boolean read_ESP(const char keyword1[], int key_size, int timeout_val, byte mode);
void timeout_start();
boolean timeout_check(int timeout_ms);
void serial_dump_ESP();
void ping();

//Global Veriables
unsigned long timeout_start_val;
char scratch_data_from_ESP[20];//first byte is the length of bytes
char payload[150];
byte payload_size=0, counter=0;
char ip_address[16];


//ESP8266 Keywords 
const char CIPMUX = '1';//CWMODE 0=Single Connection, 1=Multiple Connections


void setup(){
    //Setting up input and output pins
    pinMode(ESP_RX, INPUT);
    pinMode(ESP_TX, OUTPUT);
    
    ESP.begin(115200); //Initialize communication with ESP8266
    ESP.listen();
    Serial.begin(115200); //Initialize debug serial
    Serial.println("Vehicle Monitoring System");
    Serial.println("      Version: 0.1");
    Serial.println("--------------------------");
    delay(2000);
    setup_ESP(); //   
}

void loop(){
  ping();
  delay(7000);
}


