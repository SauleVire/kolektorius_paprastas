// Tutorial:
// http://www.hacktronics.com/Tutorials/arduino-1-wire-tutorial.html
//define input pin for 1-wire bus
#define ONE_WIRE_BUS 2 //ds18b20 davikliu pajungimo isvadas 
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
// Assign the addresses of your 1-Wire temp sensors.
// See the tutorial on how to obtain these addresses:
// http://www.hacktronics.com/Tutorials/arduino-1-wire-address-finder.html


//- kolektoriaus davikliu geri adresai
DeviceAddress KolektoriausDaviklioAdresas = {0x28, 0x1F, 0x34, 0xDD, 0x03, 0x00, 0x00, 0x82};
DeviceAddress BoilerioDaviklioAdresas = {0x28, 0xAA, 0x48, 0x97, 0x03, 0x00, 0x00, 0xD9};
//{0x28, 0xD3, 0x72, 0x97, 0x03, 0x00, 0x00, 0xEE};//daviklis testams


// paprograme davikliu adresams spausdinti
void printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    // zero pad the address if necessary
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}
//paprograme temperaturoms spausdinti
void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
  if (tempC == -127.00) {
    Serial.print("Temperaturos matavimo klaida");
  } else {
    Serial.print("C: ");
    Serial.print(tempC);
  }
}

