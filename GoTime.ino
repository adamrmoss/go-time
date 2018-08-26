#include <arduino.h>
#include <Wire.h>

#include "LiquidCrystal_I2C.h"

#define BUTTON_PIN 2

#define LIQUID_CRYSTAL_I2C_ADDRESS 0x3f
#define LIQUID_CRYSTAL_COLUMNS 16
#define LIQUID_CRYSTAL_ROWS 2

void initializePins();
void initializeSerial();
void initializeLcd();
void readInput();
void onButtonDown();
void onButtonUp();
void writeText();

int input;
int previousInput;
LiquidCrystal_I2C lcd(LIQUID_CRYSTAL_I2C_ADDRESS, LIQUID_CRYSTAL_COLUMNS, LIQUID_CRYSTAL_ROWS);

void setup()
{
    initializePins();
    initializeSerial();
    initializeLcd();
}

void initializePins()
{
    pinMode(BUTTON_PIN, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);

    input = LOW;
    digitalWrite(BUTTON_PIN, LOW);
    digitalWrite(LED_BUILTIN, LOW);
}

void initializeSerial()
{
    initializeLcd();

    Serial.begin(9600);
    while (!Serial) { }
    Serial.println("\nIt's Go Time!");
}

void initializeLcd()
{
    lcd.begin();
    lcd.backlight();
    lcd.print("It's Go Time!");
    lcd.blink();
}

void loop()
{
    readInput();
    writeText();
}

void readInput()
{
    delay(50);
    previousInput = input;
    input = digitalRead(BUTTON_PIN);

    if (previousInput == input)
    {
        return;
    }

    if (input == HIGH)
    {
        onButtonDown();
    }
    else
    {
        onButtonUp();
    }
}

void onButtonDown()
{
    digitalWrite(LED_BUILTIN, HIGH);
}

void onButtonUp()
{
    digitalWrite(LED_BUILTIN, LOW);
}

void writeText()
{

}
