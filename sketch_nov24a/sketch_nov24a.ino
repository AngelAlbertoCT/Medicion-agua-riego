#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

//Configuracion wifi servidor
const char *ssid = "INFINITUM3BBE";
const char *password = "gFJgeQZ54Y";
String servidor = "http://funcionayaestoyharto.000webhostapp.com/index.php/jaime/input";
WiFiClient client;

//Definicion de pines
//int potPin = A0;
int val = 0;
int agua = A0;

int PIN_TRIG = 5;
int PIN_ECHO = 4;
float tiempo;
int distancia;
int btnPin = 5;
int led1 = 12;
int led2 = 13;

void setup()
{
  //pinMode(potPin, INPUT);
  pinMode(agua, INPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(9600);

  Serial.println("Conectando  a: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado!");

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  val = analogRead(agua);
  int porcAgua = map(val, 4, 560, 0, 100);

  //int distance = analogRead(agua);
  int btn = digitalRead(btnPin);

//--------------------------------

digitalWrite(PIN_TRIG, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   
   digitalWrite(PIN_TRIG, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(PIN_TRIG, LOW);

   // Espera antes de leer el eco
   delayMicroseconds(10);
   
   tiempo = pulseIn(PIN_ECHO, HIGH);
   distancia = tiempo/58.3;

//--------------------------------
  HTTPClient http;
  Serial.print("Numero actual: ");
  Serial.println(val);

  String sEnviado = "{ \"value1\": " + String(porcAgua) + ", \"value2\":" + String(distancia) + " }";
  Serial.println("Enviar a servidor: ");
  Serial.println("<- " + sEnviado);

  http.begin(client, servidor);
  http.addHeader("Content-Type", "application/json");
  int iCodigoRespuesta = http.POST(sEnviado);
  if (iCodigoRespuesta > 0)
  {

    Serial.println("Codigo de respuesta: " + String(iCodigoRespuesta));
    if (iCodigoRespuesta == 200)
    {
      String sRecibido = http.getString();
      Serial.println("Respuesta Servidor: ");
      Serial.println("-> " + sRecibido);
      DynamicJsonDocument doc(1024);
      deserializeJson(doc, sRecibido);

      // Obtener los valores del JSON
      bool valor1 = doc["response1"];
      bool valor2 = doc["response2"];

      Serial.println("Valor1: " + String(valor1));
      Serial.println("Valor2: " + String(valor2));
      if (String(valor1) == "1") {
        digitalWrite(led1, HIGH);

      } else {
        digitalWrite(led1, LOW);

      }
      if (String(valor2) == "1") {
        digitalWrite(led2, HIGH);
      } else {
        digitalWrite(led2, LOW);
      }

    }
  }
  else
  {
    Serial.print("error en envio de post: ");
    Serial.println(iCodigoRespuesta);
  }
  http.end();
  Serial.println("Espera...");
  delay(5000);

}
