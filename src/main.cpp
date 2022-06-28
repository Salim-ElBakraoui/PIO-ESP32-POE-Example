#include <Arduino.h>
#include <CApp.h>

CApp* pApp;

#define STATIC_IP     "10.100.0.217"
#define GATEWAY_IP    "10.255.7.81"
#define DNS_IP        "10.255.7.82"
#define NET_MASK      (0b11111111000000000000000000000000)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pApp = new CApp(STATIC_IP, GATEWAY_IP, DNS_IP, NET_MASK);
  pApp->Run();
}

void loop() {
  // put your main code here, to run repeatedly:
  vTaskDelay(20);
}