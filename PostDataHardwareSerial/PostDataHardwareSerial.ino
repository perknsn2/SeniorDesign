const char SSID_ESP[] = "Test2";
const char SSID_KEY[] = "helloworld";

void setup_ESP();
void postData();

//int post = 0;

void setup() {
  Serial.begin(115200 );
  delay(2000);
}

void loop() {
  //if( post == 10)
    //post = 0;
  //postData(false, false, post);
  //post++;
  setup_ESP(); 
  postData(true, false, 123); 
  //delay(000);
}


