#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);
int led=D2;

void setup()
{
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  WiFi.begin("SSID","Password");
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print("..");
  }
  Serial.println("NodeMCU Connected..");
  Serial.println(WiFi.localIP());
  server.begin();
}
void loop()
{
  client=server.available();
  if(client==1)
  {
    String request=client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request=="GET /on HTTP/1.1")
    {
      digitalWrite(led,HIGH);
    }
    if(request=="GET /off HTTP/1.1")
    {
      digitalWrite(led,LOW);
    }
  }
}
