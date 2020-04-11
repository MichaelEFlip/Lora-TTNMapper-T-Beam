// Comment the next line to use ABP authentication on TTN. Leave it as it is to use recommended OTAA
//#define OTAA

#ifndef LORA_TTNMAPPER_TBEAM_CONFIG_INCLUDED
#define LORA_TTNMAPPER_TBEAM_CONFIG_INCLUDED

#ifndef OTAA
// UPDATE WITH YOUR TTN KEYS AND ADDR.
// Setting for ABP
static PROGMEM u1_t NWKSKEY[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; // LoRaWAN NwkSKey, network session key 
static u1_t PROGMEM APPSKEY[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; // LoRaWAN AppSKey, application session key 
static const u4_t DEVADDR = 0x00000000 ; // LoRaWAN end-device address (DevAddr)
#else
// Settings from OTAA device
static const u1_t PROGMEM DEVEUI[8]={ 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11 } ; // Device EUI, hex, lsb
static const u1_t PROGMEM APPEUI[8]={ 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11 }; // Application EUI, hex, lsb
static const u1_t PROGMEM APPKEY[16] = { 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11 }; // App Key, hex, msb

void os_getDevEui (u1_t* buf) { memcpy_P(buf, DEVEUI, 8);}
void os_getArtEui (u1_t* buf) { memcpy_P(buf, APPEUI, 8);}
void os_getDevKey (u1_t* buf) {  memcpy_P(buf, APPKEY, 16);}
#endif

#endif //LORA_TTNMAPPER_TBEAM_CONFIG_INCLUDED
