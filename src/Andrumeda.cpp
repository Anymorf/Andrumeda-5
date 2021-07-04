#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

#include <Fonts/FreeSerif18pt7b.h>  // Add a custom font FreeSerif12pt7b
#include <Fonts/FreeSerif12pt7b.h>  // Add a custom font FreeSerif12pt7b
#include <TFT_ILI9163C.h>

#include <Audio.h>

// Color definitions
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF

// Declare pins for the display:
#define TFT_CS     14
#define TFT_RST    10  // You can also connect this to the Arduino reset in which case, set this #define pin to -1!
#define TFT_DC     15
//#define _TFTWIDTH      128//the REAL W resolution of the TFT
//#define _TFTHEIGHT    128//the REAL H resolution of the TFT

// Create display:
TFT_ILI9163C tft = TFT_ILI9163C(TFT_CS, TFT_DC, TFT_RST);


// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=265,233.75
AudioOutputI2S           i2s1;           //xy=619,276
AudioConnection          patchCord1(waveform1, 0, i2s1, 0);
AudioConnection          patchCord2(waveform1, 0, i2s1, 1);
//AudioControlSGTL5000     sgtl5000_1;     //xy=641.0000152587891,216.75000667572021
// GUItool: end automatically generated code

int Variable1;  // Create a variable to have something dynamic to show on the display
int treshold = 200;
float a = 0;
int pinValue = 0;
int count = 200;  // Create a variable for calibration TIMEs

int atreshold(){
    // Write to the display the text "Hello":
  tft.setCursor(0, 1);  // Set position (x,y)
  tft.setTextColor(WHITE);  // Set color of text. First is the color of text and after is color of background
  tft.setTextSize(2);  // Set text size. Goes from 0 (the smallest) to 20 (very big)
  tft.println("Calibration");  // Print a text or value
  int b,c = 0;
  for (int i = 0; i < count; i++)
  {
    b = analogRead(22);
    c = c + b;
  }  
  int a22 = c / count;  

  //int a22 = analogRead(22); 
  int avalue = map(a22, 0, 1023, 1023,0);
  tft.fillScreen(GREEN); // (BLACK);  // Fill screen with black
  return avalue;
}


void setup()  // Start of setup
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(22, INPUT_PULLUP);
  digitalWrite(13, HIGH);
  digitalWrite(0,LOW);
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);

  
{//Audio setup:
  //AudioMemory(20);   
  //sgtl5000_1.enable();
  //sgtl5000_1.volume(0.6);
  //waveform1.begin(WAVEFORM_SAWTOOTH);
  ///////waveform1.amplitude(0.75);
  //waveform1.frequency(240.00);
  //waveform1.pulseWidth(0.15);

  AudioMemory(4);
  AudioNoInterrupts();
  waveform1.begin(WAVEFORM_SAWTOOTH);
  waveform1.frequency(240.00);
  waveform1.pulseWidth(0.15);
  //sine1.frequency(440);
  //sine1.amplitude(0.5);
  AudioInterrupts();
}
{// Display setup:

  // Use this initializer if you're using a TFT
  tft.begin();  // Initialize 
  //tft.setRotation(rotation);
  tft.fillScreen(); // (BLACK);  // Fill screen with black

  tft.setRotation(2);  // Set orientation of the display. Values are from 0 to 3. If not declared, orientation would be 0,
                         // which is portrait mode.

  tft.setTextWrap(false);  // By default, long lines of text are set to automatically “wrap” back to the leftmost column.
                           // To override this behavior (so text will run off the right side of the display - useful for
                           // scrolling marquee effects), use setTextWrap(false). The normal wrapping behavior is restored
                           // with setTextWrap(true).




  // We are going to print on the display everything that is static on the setup, to leave the loop free for dynamic elements:
}
{  // Hello Screen

  // Start using a custom font:
  tft.setFont(&FreeSerif12pt7b);  // Set a custom font
  tft.setTextSize(0);  // Set text size. We are using custom font so you should always set text size as 0
  tft.setCursor(0, 20);  // Set position (x,y)
  tft.setTextColor(WHITE);  // Set color of text. First is the color of text and after is color of background
  tft.println("Sev");  // Print a text or value
  tft.setCursor(35, 35);  // Set position (x,y)
  tft.setTextColor(YELLOW);  // Set color of text. First is the color of text and after is color of background
  tft.println("Electo");  // Print a text or value
  tft.setCursor(70, 55);  // Set position (x,y)
  tft.setTextColor(GREEN);  // Set color of text. First is the color of text and after is color of background
  tft.println("Zvuk");  // Print a text or value

  // Start using a custom font:
  tft.setFont(&FreeSerif18pt7b);  // Set a custom font
  tft.setTextSize(0);  // Set text size. We are using custom font so you should always set text size as 0
  tft.setCursor(0, 75);  // Set position (x,y)
  tft.setTextColor(RED);  // Set color of text. First is the color of text and after is color of background
  tft.println("Prezents");  // Print a text or value

  tft.setFont(&FreeSerif12pt7b);  // Set a custom font
  tft.setTextSize(0);  // Set text size. We are using custom font so you should always set text size as 0
  tft.setCursor(0, 100);  // Set position (x,y)
  tft.setTextColor(WHITE);  // Set color of text. First is the color of text and after is color of background
  tft.println("Andrumeda 5");  // Print a text or value

tft.setFont();
    // Start using a custom font:
  //tft.setFont(&FreeSerif18pt7b);  // Set a custom font
  tft.setTextSize(1);  // Set text size. We are using custom font so you should always set text size as 0
  tft.setCursor(0, 120);  // Set position (x,y)
  tft.setTextColor(RED);  // Set color of text. First is the color of text and after is color of background
  tft.println("Rev 0.12");  // Print a text or value

  

  delay(5000);

  tft.fillScreen(); // (BLACK);  // Fill screen with black
}

  treshold = atreshold();
  tft.fillScreen(); // (BLACK);  // Fill screen with black

  // Write to the display the text "Hello":
  tft.setCursor(0, 1);  // Set position (x,y)
  tft.setTextColor(WHITE);  // Set color of text. First is the color of text and after is color of background
  tft.setTextSize(2);  // Set text size. Goes from 0 (the smallest) to 20 (very big)
  tft.println("Andrumeda");  // Print a text or value


  // Start using a custom font:
  tft.setFont(&FreeSerif18pt7b);  // Set a custom font
  tft.setTextSize(0);  // Set text size. We are using custom font so you should always set text size as 0

  // Write to the display the text "World":
  tft.setCursor(1, 50);  // Set position (x,y)
  tft.setTextColor(RED);  // Set color of text. We are using custom font so there is no background color supported
  tft.println("5 ver 0.1");  // Print a text or value

  // Stop using a custom font:
  tft.setFont();  // Reset to standard font, to stop using any custom font previously set

  // Draw line:
  tft.drawLine(0, 55, 127, 55, CYAN);  // Draw line (x0,y0,x1,y1,color)

  // Draw rectangle:
  tft.drawRect(0, 60, 60, 30, CYAN);  // Draw rectangle (x,y,width,height,color)
                                             // It draws from the location to down-right
                                             
  // Draw rounded rectangle:
  tft.drawRoundRect(68, 60, 60, 30, 10, CYAN);  // Draw rounded rectangle (x,y,width,height,radius,color)
                                                       // It draws from the location to down-right


  // Draw triangle:
  tft.drawTriangle(60,120,    70,94,    80,120, YELLOW);  // Draw triangle (x0,y0,x1,y1,x2,y2,color)


  // Draw filled triangle:
  tft.fillTriangle(100,120,    110,94,    120,120, CYAN);  // Draw filled triangle (x0,y0,x1,y1,x2,y2,color)

  //  Draw circle:
  //tft.drawCircle(15, 124, 14, GREEN);  //  Draw circle (x,y,radius,color)

  // Draw rounded rectangle and fill:
  //tft.fillRoundRect(88, 28, 40, 27, 5, 0xF81B);  // Draw rounded filled rectangle (x,y,width,height,color)
  


}  // End of setup


float mapInput(int readValue)
{
  digitalWrite(13, HIGH);
  int avalue = map(readValue, 0, 1023, 1023,0);
  float result = ((avalue - treshold)/1023.00);
  Serial.println(result);
  return result;
}


int adc()
{
  digitalWrite(13, HIGH);
  int a22 = analogRead(22);  
  int avalue = map(a22, 0, 1023, 1023,0);
  int result = (avalue - treshold);
  Serial.println(result);
  digitalWrite(13, LOW);
  return result;
}

void loop()  // Start of loop
{

  Variable1 = adc();
  // Convert Variable1 into a string, so we can change the text alignment to the right:
  // It can be also used to add or remove decimal numbers.
  char string[10];  // Create a character array of 10 characters
  // Convert float to a string:
  dtostrf(Variable1, 3, 0, string);  // (<variable>,<amount of digits we are going to use>,<amount of decimal digits>,<string name>)

  // We are going to print on the display everything that is dynamic on the loop, to refresh continuously:

  {// Левое окошко
    // Write to the display the Variable1 with left text alignment:
    tft.setCursor(10, 67);  // Set position (x,y)
    tft.setTextColor(WHITE, BLACK);
    if(treshold < 50)  // If Variable1 is less than 10...
    {
     tft.setTextColor(GREEN);  // Set color of text. First is the color of text and after is color of background
    }
    if(treshold >= 50)  // If Variable1 is less than 100...
    {
     tft.setTextColor(RED);  // Set color of text. First is the color of text and after is color of background
    }
    //tft.setTextColor(WHITE, BLACK);  // Set color of text. First is the color of text and after is color of background
    tft.setTextSize(2);  // Set text size. Goes from 0 (the smallest) to 20 (very big)
    tft.println(treshold);  // Print a text or value
    
    // There is a problem when we go, for example, from 100 to 99 because it doesn't automatically write a background on
    // the last digit we are not longer refreshing. We need to check how many digits are and fill the space remaining.

  }
  {//Правое окошко
    // Write to the display the string with right text alignment:
    tft.setCursor(75, 67);  // Set position (x,y)
    tft.setTextColor(GREEN, BLACK);  // Set color of text. First is the color of text and after is color of background
    tft.setTextSize(2);  // Set text size. Goes from 0 (the smallest) to 20 (very big)
    //Variable1 = adc();
    a = mapInput(Variable1);
    tft.println(a);  // Print a text or value

    // We are going to write the Variable1 with a custom text, so you can see the issues:
    
    // Draw a black square in the background to "clear" the previous text:
    // This is because we are going to use a custom font, and that doesn't support brackground color.
    // We are basically printing our own background. This will cause flickering, though.
    tft.fillRect(0, 90, 55, 34, BLACK);  // Draw filled rectangle (x,y,width,height,color)
  }
  {// текст внизу
    // Start using a custom font:
    tft.setFont(&FreeSerif12pt7b);  // Set a custom font
    tft.setTextSize(0);  // Set text size. We are using custom font so you should always set text size as 0


    // Write to the display the Variable1:
    tft.setCursor(0, 120);  // Set position (x,y)
    tft.setTextColor(MAGENTA);  // Set color of text. We are using custom font so there is no background color supported
    // tft.println(777);  // Print a text or value
    
    tft.println(Variable1);  // Print a text or value

    // Stop using a custom font:
    tft.setFont();  // Reset to standard font, to stop using any custom font previously set
  }
  pinValue = analogRead(22);
  waveform1.amplitude(mapInput(pinValue));
  delay(10);
}  // End of loop
