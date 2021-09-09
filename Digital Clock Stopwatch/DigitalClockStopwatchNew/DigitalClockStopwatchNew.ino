#include <Wire.h>
#include <RTC.h>
#include "FastLED.h"
#include <EEPROM.h>

FASTLED_USING_NAMESPACE

static DS3231 RTC;

#define G 7
#define F 8
#define A 3
#define B 2
#define E 4
#define D 5
#define C 6
#define DP 9

// Commonn cathodes control
#define GND1 A3
#define GND2 A2
#define GND3 A1
#define GND4 A0

int btnStateUp = 0;
int btnStateNext = 0;
int btnStateSet = 0;
int hour;
int jamm, jam1, jam2, min1, min2 ;
int tgl, bln, tgl1, tgl2, bln1, bln2;
byte di1, di2, di3, di4, di5, dj1, dj2, dm1, dm2;
int thn, thn1, thn2, thn3, thn4 ;
int har, har1, har2, har3, har4 ;
int hm, hm1, hm2, hm3, hm4 ;

byte cc = 0;
int sett = 0;
int upp = 0;
int next = 1;
byte Nmode = 0;

int stateU = 0;
int stateN = 0;
int stateS = 0;

byte n = 0;
byte l = 0;

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    9
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    19
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120

void setup()
{
  EEPROM.begin();
  hm = EEPROM.read(1);
  if (hm != 1)hm = 0;

  Serial.begin(9600);
  RTC.begin();
  DateTime jam1, jam2, min1, min2 ;
  DateTime tgl, bln, tgl1, tgl2, bln1, bln2;
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);

  pinMode(GND1, OUTPUT);
  pinMode(GND2, OUTPUT);
  pinMode(GND3, OUTPUT);
  pinMode(GND4, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);

  Serial.print("Is Clock Running: ");
  if (RTC.isRunning())
  {
    Serial.println("Yes");
    Serial.print(RTC.getWeek());
    Serial.print(" > ");
    Serial.print(RTC.getDay());
    Serial.print("-");
    Serial.print(RTC.getMonth());
    Serial.print("-");
    Serial.print(RTC.getYear());
    Serial.print(" ");
    Serial.print(RTC.getHours());
    Serial.print(":");
    Serial.print(RTC.getMinutes());
    Serial.print(":");
    Serial.print(RTC.getSeconds());
    Serial.print("");
    if (hm == CLOCK_H12)
    {
      switch (RTC.getMeridiem()) {
        case HOUR_AM:
          Serial.print(" AM");
          break;
        case HOUR_PM:
          Serial.print(" PM");
          break;
      }
    }
    Serial.println("");
    delay(1000);
  }
  else
  {
    delay(1500);

    Serial.println("No");
    Serial.println("Setting Time");
    //RTC.setHourMode(CLOCK_H12);
    RTC.setHourMode(CLOCK_H24);
    RTC.setDateTime(__DATE__, __TIME__);
    Serial.println("New Time Set");
    Serial.print(__DATE__);
    Serial.print(" ");
    Serial.println(__TIME__);
    RTC.startClock();
  }
  //  delay(3000); // 3 second delay for recovery

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);

  har = RTC.getWeek();
  //
  //  thn1 = thn / 1000;
  //  thn2 = (thn - (thn1 * 1000)) / 100;
  //  thn3 = (thn - (thn2 * 100)-(thn1 * 1000)) / 10;
  //  thn4 = (thn - (thn3 * 10)-(thn2 * 100)-(thn1 * 1000));
  //
  //  Serial.println(har);
  //  Serial.println(thn1);
  //  Serial.println(thn2);
  //  Serial.println(thn3);
  //  Serial.println(thn4);
}

typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm };

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns

void loolp() {
  analogWrite(GND1, 1023);
  analogWrite(GND2, 1023);
  analogWrite(GND3, 1023);
  analogWrite(GND4, 1023);
  digit1();
  delay(1000);
  analogWrite(GND1, 0);
  analogWrite(GND2, 0);
  analogWrite(GND3, 0);
  analogWrite(GND4, 0);
  digit1();
  delay(1000);
}

void loop()
{
  updateread();
  animasi();

  //    jamDigital();
  //  showDate();
}

