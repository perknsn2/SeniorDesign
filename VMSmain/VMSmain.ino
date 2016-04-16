//VMS Main Code V0.1
//Debug version

#include <SoftwareSerial.h> //Using software serial to connect to UART devices

//Software Serial Pins
#define ESP_TX 4
#define ESP_RX 5

//SSID + KEY
const char SSID_ESP[] = "Mobile";
const char SSID_KEY[] = "helloworld";

SoftwareSerial ESP(ESP_RX, ESP_TX); //Define ESP8266

//Function Definitions
boolean setup_ESP();
boolean read_ESP(const char keyword1[], int key_size, int timeout_val, byte mode);
void timeout_start();
boolean timeout_check(int timeout_ms);
void serial_dump_ESP();

//Global Veriables
unsigned long timeout_start_val;
char scratch_data_from_ESP[20];//first byte is the length of bytes
char payload[150];
byte payload_size=0, counter=0;
char ip_address[16];


//ESP8266 Keywords 
const char CWMODE = '1';//CWMODE 1=STATION, 2=APMODE, 3=BOTH
const char CIPMUX = '1';//CWMODE 0=Single Connection, 1=Multiple Connections
const char keyword_OK[] = "OK";
const char keyword_ready[] = "ready";
const char keyword_no_change[] = "no change";
const char keyword_blank[] = "#&";
const char keyword_ip[] = "192.";
const char keyword_rn[] = "\r\n";
const char keyword_quote[] = "\"";
const char keyword_carrot[] = ">";
const char keyword_sendok[] = "SEND OK";
const char keyword_linkdisc[] = "Unlink";

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
  
}


