#include <SoftwareSerial.h> //Library for UART communications with ESP8266
#include <Wire.h> //Library for I2C communications

#define ESP8266_RX 4
#define ESP8266_TX 5

//SSID + KEY
const char SSID_ESP[] = "Mobile";
const char SSID_KEY[] = "helloworld";

//MODES
const char CWMODE = '1';//CWMODE 1=STATION, 2=APMODE, 3=BOTH
const char CIPMUX = '1';//CWMODE 0=Single Connection, 1=Multiple Connections

SoftwareSerial ESP8266(ESP8266_RX, ESP8266_TX);// initialize WiFi Module

//Functions
boolean setup_ESP();

//Global Variables

//Keywords for ESP8266
const char keyword_OK[] = "OK";
const char keyword_Ready[] = "Ready";
const char keyword_no_change[] = "no change";
const char keyword_blank[] = "#&";
const char keyword_ip[] = "192.";
const char keyword_rn[] = "\r\n";
const char keyword_quote[] = "\"";
const char keyword_carrot[] = ">";
const char keyword_sendok[] = "SEND OK";
const char keyword_linkdisc[] = "Unlink";

//Start setup
void setup() {
  //Pin Modes for ESP TX/RX
  pinMode(ESP8266_rxPin, INPUT);
  pinMode(ESP8266_txPin, OUTPUT);

  Wire.begin();        // join i2c bus (address optional for master)
  
  ESP8266.begin(9600);//default baudrate for ESP
  ESP8266.listen();//not needed unless using other software serial instances
  Serial.begin(115200); //for status and debug
  delay(5000);//delay before kicking things off
  
  setup_ESP();//call setup_ESP function
}

//Start functions
void loop() {
  //I2C read
   // request reading from sensor
  Wire.requestFrom(112, 2);    // request 2 bytes from slave device #112
  // device address is specified in datasheet
  // the address specified in the datasheet is 224 (0xE0)
  // but i2c adressing uses the high 7 bits so it's 112
  if (2 <= Wire.available()) { // if two bytes were received
    reading = Wire.read();  // receive high byte (overwrites previous reading)
    reading = reading << 8;    // shift high byte to be high 8 bits
    reading |= Wire.read(); // receive low byte as lower 8 bits
    Serial.println(reading);   // print the reading
  }

  delay(500);
  
}
