
#include <OneWire.h>
#include <DallasTemperature.h>
#include "davikliai.h"
#include "kolektorius.h"
//data logging timer
static long Temp_laikmatis;


// programos inicializavimas
void setup() {
  // start serial port:
  Serial.begin(9600);
  sensors.begin();
  // set the resolution to 12 bit (good enough?)
  sensors.setResolution(KolektoriausDaviklioAdresas, 12);
  sensors.setResolution(BoilerioDaviklioAdresas, 12);
  
Serial.println("Setup finished.");
  
pinMode(Siurblys, OUTPUT); digitalWrite(Siurblys, HIGH);
  
}
// pagrindinis programos ciklas,
//startas void loop()
void loop() {
  if (millis() > Temp_laikmatis + Temp_REQUEST_RATE) {
    Temp_laikmatis = millis();
  Serial.print("Requesting temperatures...");
  sensors.setWaitForConversion(true);
  sensors.requestTemperatures();
 
  Serial.println("DONE");
Serial.println("_____KOLEKTORIAUS_MATAVIMAI______");
float Kolektorius = sensors.getTempC(KolektoriausDaviklioAdresas);
Serial.print("Kolektorius: "); Serial.print(Kolektorius); 
//Serial.print(" Adresas- "),printAddress(KolektoriausDaviklioAdresas); 
Serial.println();
 
    float Boileris = sensors.getTempC(BoilerioDaviklioAdresas);
    Serial.print("Boileris: "); Serial.print(Boileris);
    //Serial.print(" Adresas- "),printAddress(BoilerioDaviklioAdresas); 
    Serial.println();

    //Startas-kolektoriaus ir boilerio temperaturu skirtumas, siurblio ijungimas
if (Kolektorius-Boileris>=skirtumasON)
      {digitalWrite(Siurblys, LOW);
      Serial.println("Siurblio busena- ON");
      }
if (Kolektorius-Boileris<=skirtumasOFF) 
      {digitalWrite(Siurblys, HIGH);
      Serial.println("Siurblio busena- OFF");
} 
//Finisas-kolektoriaus ir boilerio temperaturu skirtumas, siurblio ijungimas

}
}
// finisas void loop()




