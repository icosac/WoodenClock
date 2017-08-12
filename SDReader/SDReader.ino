/*
  SD card read/write

 This example shows how to read and write data to and from an SD card file
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain. 
 */
 
#include <SPI.h>
#include <SD.h>
#include <TMRpcm.h>

TMRpcm tmrpcm;

void(* resetFunc) (void) = 0; 

void setup(){
  tmrpcm.speakerPin = 9;
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  Serial.begin(9600);
  if (!SD.begin(7)) {
    Serial.println("SD fail");
    return;
  }
  else {
    Serial.println("Yeah");
  }
  tmrpcm.setVolume(4);
  tmrpcm.play("Allarm.wav");
}


void loop(){  }



//File myFile;
//
//void setup() {
//  // Open serial communications and wait for port to open:
//  Serial.begin(9600);
//  while (!Serial) {
//    ; // wait for serial port to connect. Needed for native USB port only
//  }
//  Serial.print("Initializing SD card...");
//
//  if (!SD.begin(7)) {
//    Serial.println("initialization failed!");
//    return;
//  }
//  Serial.println("initialization done.");
//  myFile = SD.open("prova.txt", FILE_READ);
//  Serial.println(myFile);
//  if (myFile) {
//    Serial.println("prova.txt:");
//    while (myFile.available()) {
//      Serial.write(myFile.read());
//    }
//    // close the file:
//    myFile.close();
//  } else {
//    // if the file didn't open, print an error:
//    Serial.println("error opening prova.txt");
//  }
//}
//
//void loop() {
//  // nothing happens after setup
//}


