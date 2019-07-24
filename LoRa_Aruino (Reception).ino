// LoRa and Arduino at receiving end

#include <SPI.h>
#include <LoRa.h>

#define in1 2
#define in2 3

void setup() {
  Serial.begin(9600);
      
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
     
  while (!Serial);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
      
      digitalWrite(in1, HIGH);
      digitalWrite(in2, HIGH);
      delay(5000);
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
