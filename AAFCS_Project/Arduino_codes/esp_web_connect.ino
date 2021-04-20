//#include <ESP8266WiFi.h>
#include <ESP8266.h>

String AP = "B-LINK_C34ECA";
String PASS = "Esgngara999";
const char* ssid = "B-LINK_C34ECA";
const char* password = "Esgngara999";

int ledPin = 2; 
WiFiServer server(80);

void setup() 
{
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
                    //LED pin set yo LOW in default mode
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(100);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to WiFi");
  Serial.print("IP: ");  
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() 
{
  WiFiClient client = server.available();
  if (!client) {
  return;
  }

  while(!client.available()){
  }
  
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) 
  {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  } 
  if (request.indexOf("/LED=OFF") != -1)
  {
    digitalWrite(ledPin, LOW);
    value = LOW;
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one

  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print("LED status: "); 

  if(value == HIGH) 
  {
    client.print("ON");  
  } 
  else 
  {
    client.print("OFF");
  }
  client.println("<br><br>");
  client.println("Turn <a href=\"/LED=ON\">ON</a><br>");
  client.println("Turn <a href=\"/LED=OFF\">OFF</a><br>");
  client.println("</html>");

  Serial.println("");
}
