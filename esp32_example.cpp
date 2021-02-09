#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid     = "internet-box-name";
const char* password = "internet-box-password";
const char* serverName = "http://your.server.ip/php_example.php";

float temperature;
float humidite;
float pression;
float latitude;
float longitude;

void setup() {

  temperature = 20.0;
  humidite = 30.0;
  pression = 1010.0;
  latitude = 43.6044622;
  longitude = 1.4442469;

  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");

  while(WiFi.status() != WL_CONNECTED)
  { 
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  if (humidite < 60)
  {
    temperature += 0.1;
    humidite += 0.1;
    pression += 0.1;
    latitude += 0.01;
    longitude -= 0.01;
  }
  else
  {
    temperature = 20.0;
    humidite = 30.0;
    pression = 1010.0;
    latitude = 43.6044622;
    longitude = 1.4442469;
  }
  
  if(WiFi.status()== WL_CONNECTED){
    digitalWrite(LED, HIGH);
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    // Prepare HTTP post
    String httpRequestData = "temperature=" + String(temperature) + "&humidite=" + String(humidite)
                          + "&pression=" + String(pression) + "&latitude=" + String(latitude)
                          + "&longitude=" + String(longitude) + "";
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    // Send HTTP post
    int httpResponseCode = http.POST(httpRequestData);
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }

  delay(45000); 
}