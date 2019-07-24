#include <SPI.h>
#include "mcp_can.h"

#define in1 2
#define in2 3

long unsigned int rxId;

unsigned long rcvTime;

unsigned char len = 0;
unsigned char buf[8];


const int SPI_CS_PIN = 10;


MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

void setup()
{
    Serial.begin(115200);

    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);
    
    while (CAN_OK != CAN.begin(CAN_250KBPS))              // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Module Failed to Initialized");
        Serial.println("Retrying....");
        delay(200);
    }    
    Serial.println("CAN BUS Module Initialized!");
    Serial.println("Time\t\tPGN\t\tByte0\tByte1\tByte2\tByte3\tByte4\tByte5\tByte6\tByte7");    
}


void loop()
{
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   
    if(CAN_MSGAVAIL == CAN.checkReceive())            // check if data coming
    {

        rcvTime = millis();
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

        rxId= CAN.getCanId();

        Serial.print(rcvTime);
        Serial.print("\t\t");
        Serial.print("0x");
        Serial.print(rxId, HEX);
        Serial.print("\t");

        digitalWrite(in1, HIGH);
        digitalWrite(in2, HIGH);
   
        for(int i = 0; i<len; i++)    // print the data
        {
            if(buf[i] > 15){
              Serial.print("0x");
              Serial.print(buf[i], HEX);    
            }
          else{
              Serial.print("0x0");
              Serial.print(buf[i], HEX);
          }  
            
            //Serial.print("0x");
            //Serial.print(buf[i], HEX);
            
            Serial.print("\t");            
        }
        Serial.println();
        delay(5000);
    }
}
