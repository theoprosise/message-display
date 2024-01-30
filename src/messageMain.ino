#define ENABLE_GxEPD2_GFX 1
//Include necessary dependencies to run program
#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <WiFi.h>
#include <Arduino.h>
#include <Fonts/FreeSerifBold18pt7b.h>
#include "BitmapDisplay.h"
#include <HTTPClient.h>

BitmapDisplay bitmaps(display);

//Setup variables necessary for successful messaging
const char* ssid = "NETWORK SSID";
const char* psswd = "NETWORK PASSWORD";
const char* supabaseURL = "SUPABASE URL";
const char* supabaseKey = "SUPABASE API KEY";
const char* targetColumn = "Text";
const size_t bufferSize = 1024;
String checkMessage = "";
int checkInt = 0;

void setup() {

  //Initialize wireless conection
  Serial.begin(115200);
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, psswd);
  //Print wireless setup status
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }


  Serial.println();
  Serial.println("setup");
  delay(100);
  //Initialize display bitrate and color scheme
  display.init(115200);
  display.init(115200, true, 2, false);
  display.setRotation(2);
  display.setFont(&FreeSerifBold18pt7b);
  display.setTextColor(GxEPD_BLACK);
  int16_t tbx, tby;
  uint16_t tbw, tbh;
  //Get bounds of the setup message and print it
  display.getTextBounds("Beep Boop Setup", 0, 0, &tbx, &tby, &tbw, &tbh);
  // center bounding box by transposition of origin:
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  uint16_t y = ((display.height() - tbh) / 2) - tby;
  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    delay(5000);
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print("Beep Boop Setup");
    delay(5000);
  } while (display.nextPage());

  Serial.println("setup done");
}

void loop() {
  String messageYES = "Setting Up";
  HTTPClient http;
  http.begin(supabaseURL);
  http.addHeader("apikey", String(supabaseKey));
  int httpResponseCode = http.GET();
  if (httpResponseCode > 0) {
    // Read and parse the response
    String str = http.getString();
    Serial.println("Request made, and request printed:");
    Serial.println(str);
    const char* jsonString = str.c_str();
    int colonIndex = strchr(jsonString, ':') - jsonString;
    int quoteIndex = strchr(jsonString + colonIndex, '\"') - jsonString;
    int closingQuoteIndex = strchr(jsonString + quoteIndex + 1, '\"') - jsonString;
    int wordLength = closingQuoteIndex - quoteIndex - 1;
    char extractedWord[wordLength + 1];
    strncpy(extractedWord, jsonString + quoteIndex + 1, wordLength);
    extractedWord[wordLength] = '\0';
    messageYES = extractedWord;
    Serial.println("Here is extracted word:");
    Serial.println(extractedWord);

    //Fixes an infinite loop that occurs with the occasional message reset
    if (messageYES == checkMessage) {
      if (checkInt > 15000000) {
        checkInt = 4;
      }
      checkInt = checkInt + 1;
    } else {
      if (checkMessage == "Setting Up") {
        checkMessage = "";
      } else {
        checkMessage = messageYES;
      }
      checkInt = 0;
    }
  } else {
    Serial.print("HTTP Error code: ");
    Serial.println(httpResponseCode);
  }

  if (checkInt < 3) {
    display.setRotation(2);
    display.setFont(&FreeSerifBold18pt7b);
    display.setTextColor(GxEPD_BLACK);
    int16_t tbx, tby;
    uint16_t tbw, tbh;
    display.getTextBounds(messageYES, 0, 0, &tbx, &tby, &tbw, &tbh);
    // center bounding box by transposition of origin:
    uint16_t x = ((display.width() - tbw) / 2) - tbx;
    uint16_t y = ((display.height() - tbh) / 2) - tby;
    display.setFullWindow();
    display.firstPage();
    do {
      delay(10000);  
      display.setCursor(x, y);
      display.print(messageYES);
      delay(10000);
    } while (display.nextPage());
  }
  delay(1000);
}
