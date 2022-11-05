#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <time.h>
#include <AsyncElegantOTA.h>
#include "Adafruit_GFX.h"
#include "Adafruit_HT1632.h"
#include "Main.h"

#define NTP_SERVER "europe.pool.ntp.org"           
#define TZ "CET-1CEST,M3.5.0/02,M10.5.0/03"   

#define HT_DATA 12
#define HT_WR 14
#define HT_CS 27
#define HT_CS2 26
#define RELAY_PIN 25
#define DHT_PIN 33
#define LIGHT_PIN 32
#define DHTTYPE DHT11

const char *WIFI_SSID = "xxx";
const char *WIFI_PASSWORD = "xxx";

WiFiClient espClient;
AsyncWebServer server(80);
Adafruit_HT1632LEDMatrix matrix = Adafruit_HT1632LEDMatrix(HT_DATA, HT_WR, HT_CS, HT_CS2);
Main* _main;
char gameState[100];

uint32_t sntp_update_delay_MS_rfc_not_less_than_15000 ()
{
  return 1 * 60 * 60 * 1000UL; // 1 hours
}

uint32_t sntp_startup_delay_MS_rfc_not_less_than_60000 ()
{
  return 60000UL;
}

void setupWifi()
{
	WiFi.mode(WIFI_STA);
	WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
	Serial.println(F("\nConnecting to WiFi"));

	while (WiFi.status() != WL_CONNECTED)
	{
		Serial.print(F("."));
		delay(100);
	}

	Serial.print(F("\nWifi IP: "));
	Serial.println(WiFi.localIP());
}

void setupOTA()
{
	server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){ 
		_main->getDisplayMode(gameState);
		request->send(200, "text/plain", gameState); 
	});
	server.on("/clock", HTTP_GET, [](AsyncWebServerRequest *request){
		_main->getDisplayMode(gameState);
		request->send(200, "text/plain", gameState);
	});
	AsyncElegantOTA.begin(&server);
	server.begin();
	Serial.print(F("OTA server OK "));
}

void setup()
{
	Serial.begin(115200);
	pinMode(RELAY_PIN, OUTPUT);
	digitalWrite(RELAY_PIN, HIGH);
	matrix.begin(ADA_HT1632_COMMON_16NMOS);
    matrix.setBrightness(0);

	setupWifi();
	setupOTA();

	delay(500);
    digitalWrite(RELAY_PIN, LOW);
	matrix.clearScreen();
	_main = new Main(TZ, NTP_SERVER, &matrix, DHT_PIN, DHTTYPE);
	Serial.print(F("Setup OK"));
}

void loop()
{
	_main->loop();
	delay(70);
}