#ifndef ROTARYKEYBOARD_H
#define ROTARYKEYBOARD_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Encoder.h>
#include <EncoderButton.h>

class RotaryKeyboard {
public:
    RotaryKeyboard(LiquidCrystal_I2C &lcd_,
                   Encoder &encoder_,
                   EncoderButton &button_,
                   const char* chars,
                   byte backspaceCharIndex_,
                   byte saveCharIndex_,
                   byte cancelCharIndex_,
                   byte arrowCharIndex_);

    void begin();
    void start(String prompt_, void (*onSave_)(String), void (*onCancel_)());
    void update();
    bool isActive();

private:
    LiquidCrystal_I2C &lcd;
    Encoder &encoder;
    EncoderButton &button;
    const char* characters;
    int charLength;

    byte arrowCharIndex;
    byte backspaceIndex;
    byte saveIndex;
    byte cancelIndex;

    byte arrowChar[8];
    byte backspaceChar[8];
    byte saveChar[8];
    byte cancelChar[8];

    static RotaryKeyboard* instance;

    static void handleClick(EncoderButton &b);
    static void handleLongPress(EncoderButton &b);
    static void handleDoubleClick(EncoderButton &b);

    void initCustomChars();
    void updateDisplay();
    void printChar(char c);
    void handleChar(char selectedChar);

    void onClick(EncoderButton &eb);
    void onLongPress(EncoderButton &eb);
    void onDoubleClick(EncoderButton &eb);

    String promptText;
    String currentValue;
    int scrollPos;
    long lastEncCount;
    int prevCenterCharIndex;
    char prevChars[20];
    static const int windowSize = 20;

    void (*saveCallback)(String);
    void (*cancelCallback)();
    bool active = false;
};

#endif
