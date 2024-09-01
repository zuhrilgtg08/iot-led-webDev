#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);
const char* ssid = "Yolo";
const char* password = "#$456Yo2024";

const int pinLed1 = D1;
const int pinLed2 = D2;
const int pinLed3 = D3;
const int pinLed4 = D7;

bool ledTamuState = false;
bool ledKerjaState = false;
bool ledMakanState = false;
bool ledTerasState = false;

bool allOff = false;
bool allOn = false;

void setup() {
  Serial.begin(115200);

  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connect to Wifi Yolo");

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    Serial.print(".");
  }

  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/ruangTamu", HTTP_GET, getLedRuangTamu);
  server.on("/ruangKerja", HTTP_GET, getLedRuangKerja);
  server.on("/ruangMakan", HTTP_GET, getLedRuangMakan);
  server.on("/terasArea", HTTP_GET, getLedTerasArea);

  server.on("/ruangTamu", HTTP_POST, setLedRuangTamu);
  server.on("/ruangKerja", HTTP_POST, setLedRuangKerja);
  server.on("/ruangMakan", HTTP_POST, setLedRuangMakan);
  server.on("/terasArea", HTTP_POST, setLedTerasArea);

  // server.on("/alwaysOff", HTTP_GET, getAllMatikan);
  // server.on("/alwaysOff", HTTP_POST, setAllMatikan);

  server.begin();
  Serial.println("Server is Running....");
}

void loop() {
  server.handleClient();
}

void setLedRuangTamu() {
  ledTamuState = !ledTamuState;
  // true -> high(nyala) || false -> low(mati)
  digitalWrite(pinLed1, ledTamuState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledTamuState ? "ON" : "OFF");
}

void setLedRuangKerja() {
  ledKerjaState = !ledKerjaState;
  digitalWrite(pinLed2, ledKerjaState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledKerjaState ? "ON" : "OFF");
}

void setLedRuangMakan() {
  ledMakanState = !ledMakanState;
  digitalWrite(pinLed3, ledMakanState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledMakanState ? "ON" : "OFF");
}

void setLedTerasArea() {
  ledTerasState = !ledTerasState;
  digitalWrite(pinLed4, ledTerasState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledTerasState ? "ON" : "OFF");
}

void getLedRuangTamu() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledTamuState ? "ON" : "OFF");
}

void getLedRuangKerja() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledKerjaState ? "ON" : "OFF");
}

void getLedRuangMakan() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledMakanState ? "ON" : "OFF");
}

void getLedTerasArea() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledTerasState ? "ON" : "OFF");
}

// void setAllMatikan() {
//   allOff = !allOff;
//   digitalWrite(pinLed1, allOff ? LOW : HIGH);
//   digitalWrite(pinLed2, allOff ? LOW : HIGH);
//   digitalWrite(pinLed3, allOff ? LOW : HIGH);
//   digitalWrite(pinLed4, allOff ? LOW : HIGH);

//   server.sendHeader("Access-Control-Allow-Origin", "*");
//   server.send(200, "text/plain", "OFF");
// }

// void getAllMatikan() {
//   server.sendHeader("Access-Control-Allow-Origin", "*");
//   server.send(200, "text/plain", "OFF");
// }

// void getAllHidupkan() {

// }

// void getAllMatikan() {

// }