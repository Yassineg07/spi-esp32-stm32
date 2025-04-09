#include <SPI.h>

// Define custom SPI pins (HSPI bus for ESP32-CAM)
#define SCK_PIN   14  // HSPI SCK
//#define MISO_PIN  12  // HSPI MISO (unused in this example)
#define MOSI_PIN  13  // HSPI MOSI
#define CS_PIN    15  // Chip Select (Slave Select) Hardware NSS (GPIO15)

const int ledPin = 33;

// Initialize the HSPI bus with custom pins
SPIClass hspi(HSPI);

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32-CAM SPI Master Initializing...");

  // Configure SPI pins
  hspi.begin(SCK_PIN, -1, MOSI_PIN, -1); // -1 = no hardware CS pin and no MISO
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH); // Deselect slave initially

  pinMode(ledPin, OUTPUT);
  blinkLED(2, 200);
}

void sendString(const char *str) {
  // Calculate string length (including null terminator)
  size_t len = strlen(str) + 1;

  // Send the string bytes over SPI
  hspi.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  digitalWrite(CS_PIN, LOW);

  for (size_t i = 0; i < len; i++) {
    hspi.transfer(str[i]); // Send each character
  }

  digitalWrite(CS_PIN, HIGH); // Deselect slave
  hspi.endTransaction();

  blinkLED(1, 200); 
}

void loop() {
 const char *message = "hello spi"; // String to send
  sendString(message);
  
  delay(1000); // Wait 1 second between transmissions
}

void blinkLED(int times, int duration) {
  while (times--) {
      digitalWrite(ledPin, LOW);
      delay(duration);
      digitalWrite(ledPin, HIGH);
      delay(duration);
  }
}