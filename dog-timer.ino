////////////////////////////////////////////////////////////////////////////
// DISPLAY
// image to code converter at https://javl.github.io/image2cpp/
// display library at https://github.com/adafruit/Adafruit-GFX-Library
// https://adafruit.github.io/Adafruit-GFX-Library/html/functions_func.html
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1    // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// LOGO
#define LOGO_WIDTH 128
#define LOGO_HEIGHT 64

static const unsigned char PROGMEM logo_bmp[] =
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x0f, 0xc7, 0xc0, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x87, 0xc0, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x03, 0x80, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x03, 0x83, 0xf3, 0xcf, 0x1c, 0x1e, 0x07, 0x8c, 0x3e, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00,
        0x03, 0x03, 0x8f, 0xf3, 0xcf, 0x1c, 0x3f, 0x1f, 0xcc, 0x7f, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00,
        0x03, 0xff, 0x8e, 0x31, 0xc7, 0x1c, 0x73, 0x98, 0xc0, 0xe7, 0x00, 0x00, 0x00, 0x19, 0x20, 0x00,
        0x03, 0xff, 0x9c, 0x31, 0xc7, 0x1c, 0xe3, 0x38, 0xc0, 0xe0, 0x00, 0x00, 0x00, 0x33, 0x20, 0x00,
        0x03, 0xff, 0x9c, 0x31, 0xc7, 0x1c, 0xef, 0x3b, 0xc0, 0xf8, 0x00, 0x00, 0x00, 0x66, 0x20, 0x00,
        0x03, 0x03, 0x9c, 0x31, 0xc7, 0x1c, 0xfe, 0x3f, 0x80, 0x7e, 0x00, 0x00, 0x00, 0xc4, 0x20, 0x00,
        0x03, 0x03, 0x9c, 0x31, 0xc7, 0x1c, 0xf0, 0x3c, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x88, 0x30, 0x00,
        0x03, 0x03, 0x9c, 0x71, 0xc7, 0x1c, 0xe0, 0x38, 0x00, 0xc7, 0x00, 0x00, 0x01, 0x18, 0x30, 0x00,
        0x07, 0x83, 0x9e, 0x70, 0xff, 0x1c, 0x7b, 0x1c, 0xc0, 0xc7, 0x00, 0x00, 0x03, 0x10, 0x30, 0x00,
        0x0f, 0xc7, 0xcf, 0xf8, 0xfb, 0x3e, 0x7f, 0x1f, 0xc0, 0xfe, 0x00, 0x00, 0x06, 0x30, 0x30, 0x00,
        0x07, 0x87, 0x87, 0xb8, 0x03, 0x3e, 0x1e, 0x07, 0x80, 0x78, 0x00, 0x00, 0x0c, 0x20, 0x10, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x60, 0x10, 0x00,
        0x00, 0x00, 0x00, 0x01, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x40, 0x10, 0x00,
        0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xc0, 0x10, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x80, 0x10, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x80, 0x10, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xc0, 0x80, 0x10, 0x00,
        0x07, 0xfc, 0x00, 0x00, 0x00, 0x78, 0x00, 0x1f, 0xe0, 0x00, 0x03, 0xc0, 0x61, 0x84, 0x10, 0x00,
        0x0f, 0xfe, 0x00, 0x00, 0x00, 0x18, 0x00, 0x30, 0x3e, 0x00, 0x06, 0x00, 0x01, 0x04, 0x10, 0x00,
        0x03, 0xfe, 0x00, 0x00, 0x00, 0x18, 0x00, 0x30, 0x03, 0xe0, 0x18, 0x00, 0x01, 0x0c, 0x10, 0x00,
        0x03, 0x0c, 0x38, 0x0f, 0x01, 0xf8, 0x00, 0x3e, 0x00, 0x78, 0x30, 0x00, 0x01, 0x88, 0x10, 0x00,
        0x03, 0x00, 0xfe, 0x1f, 0xc3, 0xf8, 0x00, 0x23, 0xe0, 0x07, 0x60, 0x00, 0x00, 0xf8, 0x30, 0x00,
        0x03, 0x01, 0xcf, 0x39, 0xc7, 0x38, 0x00, 0x20, 0x38, 0x01, 0xc0, 0x00, 0x00, 0x30, 0x30, 0x00,
        0x03, 0xf9, 0xc7, 0x30, 0xe6, 0x18, 0x00, 0x10, 0x07, 0x01, 0x80, 0x00, 0x00, 0x10, 0x20, 0x00,
        0x03, 0xf9, 0x87, 0x70, 0xee, 0x18, 0x00, 0x10, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00,
        0x03, 0x01, 0x87, 0x70, 0xee, 0x18, 0x00, 0x08, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00,
        0x03, 0x01, 0x87, 0x70, 0xee, 0x18, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00,
        0x03, 0x01, 0xc7, 0x70, 0xee, 0x18, 0x00, 0x06, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00,
        0x07, 0x01, 0xc6, 0x39, 0xc7, 0x38, 0x00, 0x02, 0x00, 0x02, 0x00, 0x04, 0x00, 0x00, 0xc0, 0x00,
        0x0f, 0xc0, 0xfe, 0x3f, 0xc7, 0xfe, 0x00, 0x03, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x80, 0x00,
        0x0f, 0xc0, 0x7c, 0x1f, 0x03, 0xde, 0x00, 0x01, 0x80, 0x01, 0x00, 0x06, 0x03, 0xc1, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x02, 0x07, 0xe1, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x41, 0x00, 0x02, 0x07, 0xc2, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x33, 0x00, 0x03, 0x07, 0x02, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x03, 0x00, 0x01, 0x80, 0x02, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x03, 0x80, 0x80, 0x02, 0x00, 0x00,
        0x07, 0xfc, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x07, 0xc0, 0x03, 0x02, 0x00, 0x00,
        0x0f, 0xfe, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x0f, 0xc0, 0x01, 0x82, 0x00, 0x00,
        0x0f, 0xfe, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x0f, 0x00, 0x38, 0xc2, 0x00, 0x00,
        0x0c, 0xee, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0xf8, 0x43, 0x00, 0x00,
        0x00, 0xe0, 0xf7, 0xbd, 0xf0, 0x7e, 0x7f, 0x80, 0x00, 0x00, 0x40, 0x09, 0xf8, 0x23, 0x80, 0x01,
        0x00, 0xe0, 0xf3, 0xff, 0xf8, 0xff, 0x7f, 0x80, 0x00, 0x00, 0x20, 0x11, 0xf8, 0x26, 0x60, 0x07,
        0x00, 0xe0, 0x71, 0xcf, 0x38, 0xe7, 0x39, 0x80, 0x00, 0x00, 0x30, 0x10, 0xf8, 0x26, 0x30, 0x1c,
        0x00, 0xe0, 0x71, 0xc6, 0x39, 0xc7, 0x38, 0x00, 0x00, 0x00, 0x18, 0x10, 0x70, 0x24, 0x1c, 0x70,
        0x00, 0xe0, 0x71, 0x86, 0x39, 0xfe, 0x38, 0x00, 0x00, 0x00, 0x08, 0x10, 0x18, 0x64, 0x87, 0xc0,
        0x00, 0xe0, 0x71, 0x86, 0x39, 0xfc, 0x38, 0x00, 0x00, 0x00, 0x04, 0x10, 0x09, 0xc4, 0x80, 0x00,
        0x00, 0xe0, 0x71, 0x86, 0x39, 0xc0, 0x38, 0x00, 0x00, 0x00, 0x03, 0x18, 0x1e, 0x84, 0x80, 0x00,
        0x00, 0xe0, 0x71, 0x86, 0x38, 0xe0, 0x38, 0x00, 0x00, 0x00, 0x01, 0x8c, 0x70, 0x8c, 0x80, 0x00,
        0x01, 0xf0, 0xf3, 0xcf, 0x7c, 0xff, 0x7c, 0x00, 0x00, 0x00, 0x00, 0xc7, 0xe1, 0x88, 0x80, 0x00,
        0x03, 0xf0, 0xfb, 0xff, 0x7c, 0x7e, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x60, 0xff, 0x18, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x18, 0x10, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x30, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x01, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x01, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00};

// Display variables
boolean refresh; // Marker requesting display refresh

////////////////////////////////
// ENCODER
#include <SimpleRotary.h>
// https://github.com/mprograms/SimpleRotary
// Pin A, Pin B, Button Pin
SimpleRotary rotary(1, 0, 5);

byte encState;
byte buttonState;

#define ENC_LEFT 1
#define ENC_RIGHT 2

////////////////////////////////
// SOLENOIDS

// Define Pins
#define SOLENOID_RIGHT 8 // RIGHT SOLENOID (not installed yet)
#define SOLENOID_LEFT 4  // LEFT SOLENOID
#define EXT_TRIGGER 15

///////////////////////////////
// TIMER

unsigned long startTime = 0;
boolean timerState = 0;
const int interval = 15; // predefined alarm setting interval
boolean timerDone = true;
byte oneMinute = 0;
boolean checkTimer = false;

//   spinning indicator  - \ | /
char runIndicator[4] = {45, 92, 124, 47};
byte count4 = 0;

// solenoids and trigger
bool primedTrigger[3] = {false, false, false}; // triggers that are ready to fire

///////////////////////////////
// MENU ITEMS

#define MENU_RIGHT 0
#define MENU_LEFT 1
#define MENU_DISPENSER 2
#define MENU_RESET 3
#define MENU_REPEAT 4

#define MENU_RIGHT_VALUE 10
#define MENU_LEFT_VALUE 11
#define MENU_DISPENSER_VALUE 12
#define MENU_RESET_VALUE 13
#define MENU_REPEAT_VALUE 14

#define MENU_START 5

unsigned int menuItemValue[5] = {}; // array containing timervalues (RIGHT, LEFT, DIS, Rep times, Rep interval)
unsigned int currentItem = MENU_RIGHT;

boolean selectToggle = false;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////// @note SETUP
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600);

  // encoder settings
  rotary.setDebounceDelay(2); // DEFAULT is 2ms
  rotary.setErrorDelay(0);    // basic error correction function for high speeds - DEFAULT is 200ms // Off is 0

  // set solenoid pins
  pinMode(SOLENOID_RIGHT, OUTPUT); // RIGHT
  pinMode(SOLENOID_LEFT, OUTPUT);  // LEFT
  pinMode(EXT_TRIGGER, OUTPUT);

  // initialize display
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { // I2C Address is 0x3C for the Display
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }

  drawLogo(1500); // Draw the logo, followed by a delay of specified time

  // Wait until button is pressed
  while (rotary.push() == 0)
  {
  }

  setDefault();   // set all default startup values
  refresh = true; // Show initial menu
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////// @note LOOP
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop()
{
  //////////////////////////////////////////////////////////////////////////
  ///////// @note TIMER Off
  if (timerState == 0)
  {
    // ENCODER
    encState = rotary.rotate();

    ///////////////////////////////
    // switch between menu items when no selection has been made
    if (selectToggle == false)
    {
      if (encState == ENC_LEFT && currentItem < MENU_START)
      {
        currentItem++;
        // if repeater is off skip interval and add another
        if (currentItem == MENU_REPEAT && menuItemValue[MENU_RESET] == 0)
        {
          currentItem++;
        }
        refresh = true;
      }

      if (encState == ENC_RIGHT && currentItem > MENU_RIGHT)
      {
        currentItem--;
        // if repeater is off skip interval and subtract another 1
        if (currentItem == MENU_REPEAT && menuItemValue[MENU_RESET] == 0)
        {
          currentItem--;
        }
        refresh = true;
      }
    }

    ////////////////////////////
    if (selectToggle == true) // change value of selected timer when a selection has been made
    {
      switch (currentItem)
      {
      case MENU_RESET_VALUE: // repeat times selector
        if (encState == ENC_LEFT && menuItemValue[currentItem - 10] < 50)
        {
          menuItemValue[currentItem - 10]++;
          refresh = true;
        }

        if (encState == ENC_RIGHT && menuItemValue[currentItem - 10] > 0)
        {
          menuItemValue[currentItem - 10]--;
          refresh = true;
        }
        break;

      default: // select a time on a timeslot
        // WHEN SMALLER THAN INTERVAL GO IN MINUTE STEPS
        // menuItemValue + 10 is always the value within an item ... have to -10 to access correct array entry
        // remainder to determine if a turn needs to shift the value to the nearest interval setting
        if (encState == ENC_LEFT && menuItemValue[currentItem - 10] <= interval)
        {
          menuItemValue[currentItem - 10]++;
          refresh = true;
        }
        if (encState == ENC_RIGHT && menuItemValue[currentItem - 10] <= interval)
        {
          if (menuItemValue[currentItem - 10] > 0)
          {
            menuItemValue[currentItem - 10]--;
          }
          refresh = true;
        }

        if (encState == ENC_LEFT && menuItemValue[currentItem - 10] > interval)
        { // clockwise
          int remainder = menuItemValue[currentItem - 10] % interval;
          if (remainder == 0)
          {
            menuItemValue[currentItem - 10] = menuItemValue[currentItem - 10] + interval;
          }
          else
          {
            menuItemValue[currentItem - 10] = menuItemValue[currentItem - 10] + interval - remainder;
          }
          refresh = true;
        }

        if (encState == ENC_RIGHT && menuItemValue[currentItem - 10] > interval)

        { // anti clockwise
          if (menuItemValue[currentItem - 10] > 0)
          {
            int remainder = menuItemValue[currentItem - 10] % interval;
            if (remainder == 0)
            {
              menuItemValue[currentItem - 10] = menuItemValue[currentItem - 10] - interval;
            }
            else
            {
              menuItemValue[currentItem - 10] = menuItemValue[currentItem - 10] - remainder;
            }
          }

          refresh = true;
        }

        // make sure repeat interval is at least 1
        if (menuItemValue[MENU_REPEAT] < 1)
        {
          menuItemValue[MENU_REPEAT] = 1;
        }

        break;
      }
    }

    // BUTTON
    buttonState = rotary.push();
    if (buttonState == 1 && currentItem != MENU_START) // 6 is the start button
    {
      selectToggle = !selectToggle;
      switch (selectToggle)
      {
      case true: // changing times
        if (currentItem < 10)
        {
          currentItem = currentItem + 10;
          refresh = true;
        }
        break;
      case false: // selecting timers
        if (currentItem >= 10)
        {
          currentItem = currentItem - 10;
          refresh = true;
        }
        break;
      }
    }
    // when pushing button on START
    if (buttonState == 1 && currentItem == MENU_START)
    {
      // turn timer on
      timerState = 1;
      oneMinute = 0; // reset oneMinute counter
      checkTimer = false;

      // primeSolenoids and trigger with timer of more than 0
      for (int i = MENU_RIGHT; i <= MENU_DISPENSER; i++)
      {
        if (menuItemValue[i] > 0)
        {
          primedTrigger[i] = true;
        }
        else
        {
          primedTrigger[i] = false;
        }
      }
      // capture time when timer was started, or restarted
      startTime = millis();
      // refresh display
      refresh = true;
    }
  }

  //////////////////////////////////////////////////////////////////////////
  ///////// @note TIMER ON
  if (timerState == 1)
  {
    // BUTTON
    buttonState = rotary.push();
    if (buttonState == 1)
    {
      timerState = 0; // turn timer off
      refresh = true;
    }

    // TIMER ROUTINE in quarter seconds. run every 250ms
    if (millis() - startTime >= 250)
    {
      // Serial.println(millis() - startTime); // check jitter
      runTimer();
      startTime = startTime + 250;
    }
  }

  /////////// DISPLAY - END OF LOOP CHECK
  // refresh menu if refresh flag has been set during loop
  if (refresh == true)
  {
    drawMenu();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// @note FUNCTIONS //////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setDefault()
{
  menuItemValue[0] = 0; // RIGHT
  menuItemValue[1] = 0; // LEFT
  menuItemValue[2] = 0; // dispenser
  menuItemValue[3] = 0; // dispenser repeat
  menuItemValue[4] = 5; // dispenser repeat interval
  timerState = 0;
  currentItem = 0;
  selectToggle = false;
  oneMinute = 0;
}

void drawMenu(void)
{
  display.clearDisplay();  // clear display buffer for re-write
  display.setCursor(0, 0); // Start at top-left corner
  display.setTextSize(1);  // Normal 1:1 pixel scale

  display.setTextColor(WHITE);                 // normal text // top 2 lines of text are always in yellow on this display
  display.println(F(" HAYLEE's FOOD TIMER ")); // headline

  if (timerState == 0)
  {
    display.println(F("---------------------")); // underline
    // reset runindicator
    count4 = 0;
  }
  // blinking run indicator on every refresh
  if (timerState == 1)
  {
    for (int i = 0; i < 21; i++) // fill whole line
    {
      {
        display.print(runIndicator[count4]); // underline spinning
      }
    }
    count4++;
    if (count4 > 3)
    {
      count4 = 0;
    }
    display.println();
  }

  // From 3rd line on in BLUE
  // right
  invertFontIfSelected(MENU_RIGHT);
  display.print(F("Right     "));
  // right time
  invertFontIfSelected(MENU_RIGHT_VALUE);
  if (menuItemValue[MENU_RIGHT] == 0)
  {
    display.println("Off");
  }
  else
  {
    HhMmDisplay(MENU_RIGHT);
  }
  // left
  invertFontIfSelected(MENU_LEFT);
  display.print(F("Left      "));
  // left time
  invertFontIfSelected(MENU_LEFT_VALUE);
  if (menuItemValue[MENU_LEFT] == 0)
  {
    display.println("Off");
  }
  else
  {
    HhMmDisplay(MENU_LEFT);
  }

  // Reoccuring
  invertFontIfSelected(MENU_DISPENSER);
  display.print(F("Dispenser "));

  // Reoccuring time
  invertFontIfSelected(MENU_DISPENSER_VALUE);
  if (menuItemValue[MENU_DISPENSER] == 0 && menuItemValue[MENU_RESET] == 0)
  {
    display.println("Off");
  }
  else
  {
    HhMmDisplay(MENU_DISPENSER);
  }

  // Repeater setting
  invertFontIfSelected(MENU_RESET);
  display.print(F(" ^Reset "));
  // Repeater option
  invertFontIfSelected(MENU_RESET_VALUE);
  if (menuItemValue[MENU_RESET] == 0)
  {
    display.print("  Off");
  }
  else
  {
    display.print(menuItemValue[MENU_RESET]);
    display.print("x ");
  }

  // repeat INTERVAL
  if (menuItemValue[MENU_RESET] != 0)
  {
    invertFontIfSelected(MENU_REPEAT);
    display.print(F("To "));
    invertFontIfSelected(MENU_REPEAT_VALUE);
    HhMmDisplay(MENU_REPEAT);
  }
  else
  {
    display.println();
  }
  // START BUTTON
  if (timerState == 0)
  {
    display.setTextColor(WHITE);
    display.print(F("      - "));
    invertFontIfSelected(MENU_START);
    display.print(F("START"));
    display.setTextColor(WHITE);
    display.print(F(" -      "));
  }
  if (timerState == 1)
  {
    invertFontIfSelected(MENU_START);
    display.print(F("      - STOP! -      "));
  }

  //////////////////
  // Display new buffer
  display.display();
  // and reset refresh trigger
  refresh = false;
}

// @note runtimer Fx
void runTimer(void)
{
  // check if all timers are done
  timerDone = true;
  for (int i = 0; i <= 3; i++)
  {
    if (menuItemValue[i] > 0)
    {
      timerDone = false;
    }
  }
  if (timerDone == true)
  {
    drawDone();
    drawLogo(1500);
    setDefault();
    refresh = true;
  }

  // count oneMinute in quarter seconds
  if (oneMinute < 239) // increase minute timer every 240 quarter seconds
  {
    oneMinute++;
  }
  else
  {
    oneMinute = 0;
    checkTimer = true;
  }

  // checkTimers after each minute
  if (checkTimer == true)
  {
    // check 0-2 timers
    for (int i = 0; i <= 2; i++)
    {
      if (menuItemValue[i] > 0)
      {
        menuItemValue[i]--;
      }

      if (menuItemValue[i] == 0) // WHEN A TIMER reaches 0
      {
        triggerSolenoid(i); // trigger a primed solenoid

        // check if repeater timer on 2 will need to be restarted after firing
        if (i == 2)
        {
          if (menuItemValue[3] > 0) // check number of remaining repeats
          {
            menuItemValue[3]--;                  // reduce repeat timer by one
            menuItemValue[2] = menuItemValue[4]; // restart dispenser timer on 3 with value from 4
            primedTrigger[2] = true;             // reprime trigger for dispenser
          }
        }
      }
    }
    checkTimer = false;
  }

  refresh = true;
}

// @note TRIGGER SOLENOID
void triggerSolenoid(int x)
{
  if (primedTrigger[x] == true)
  {
    // Serial.print("Triggering ");
    // Serial.println(x);
    switch (x)
    {
      // RIGHT
    case 0:
      digitalWrite(SOLENOID_RIGHT, 1); // activate
      delay(1500);
      digitalWrite(SOLENOID_RIGHT, 0); // deactivate
      break;
      // LEFT
    case 1:
      digitalWrite(SOLENOID_LEFT, 1); // activate
      delay(1500);
      digitalWrite(SOLENOID_LEFT, 0); // deactivate
      break;
      // Dispenser
    case 2:
      digitalWrite(EXT_TRIGGER, 1); // activate
      delay(400);
      digitalWrite(EXT_TRIGGER, 0); // deactivate
      break;

    default:
      Serial.println("trigger error");
      break;
    }
  }
  // un-prime the trigger
  primedTrigger[x] = false;
}

void HhMmDisplay(int x)
{
  if (menuItemValue[x] >= 60)
  {
    display.print(menuItemValue[x] / 60);
    display.print("h ");
  }
  display.print(menuItemValue[x] % 60);
  display.println("m");
}

void invertFontIfSelected(int x)
{
  if (x == currentItem)
  {
    display.setTextColor(BLACK, WHITE); // normal text
  }
  else
  {
    display.setTextColor(WHITE);
  }
}

void drawDone()
{
  display.clearDisplay(); // clear display buffer for next re-write
  display.setTextColor(WHITE);
  display.setTextSize(3);    // Normal 1:1 pixel scale
  display.setCursor(18, 20); // Start at top-left corner
  display.println(F("DONE!!"));
  display.display(); // display buffer
  while (rotary.push() == 0)
  { // halt until button is pressed
  }
}

void drawLogo(int x)
{
  display.clearDisplay();
  display.drawBitmap(
      (display.width() - LOGO_WIDTH) / 2,
      (display.height() - LOGO_HEIGHT) / 2,
      logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(x); // show display for specified time
}
