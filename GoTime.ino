#include <arduino.h>

#define BUTTON_PIN 2

void readInput();
void onButtonDown();
void onButtonUp();

int input;
int previousInput;

void setup()
{
    pinMode(BUTTON_PIN, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);

    input = LOW;
    digitalWrite(BUTTON_PIN, LOW);
    digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
    readInput();
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
