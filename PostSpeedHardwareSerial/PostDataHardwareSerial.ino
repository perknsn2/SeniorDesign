const char SSID_ESP[] = "Test";
const char SSID_KEY[] = "helloworld";

void setup_ESP();
void postData();

int post = 0;

void setup() {
  Serial.begin(115200);
  delay(2000);
  setup_ESP();  
}

void loop() {
  if( post == 10)
    post = 0;
  postData(false, false, post);
  post++;
  delay(7000);
}


