#include "SPI.h"
#include "PN532_SPI.h"
#include "snep.h"
#include "NdefMessage.h"

PN532_SPI pn532spi(SPI, 10);
SNEP nfc(pn532spi);
uint8_t ndefBuf[128];

void setup() {
    Serial.begin(9600);
    Serial.println("NFC Peer to Peer Example - Send Message");
}

void loop() {
    Serial.println("Send a message to Peer");
    
    NdefMessage message = NdefMessage();
    message.addUriRecord("whatsthewifi://");

    
    int messageSize = message.getEncodedSize();
    if (messageSize > sizeof(ndefBuf)) {
        Serial.println("ndefBuf is too small");
    }

    message.encode(ndefBuf);
    if (0 >= nfc.write(ndefBuf, messageSize)) {
        Serial.println("Failed");
    } else {
        Serial.println("Success");
    }

    delay(3000);
}
