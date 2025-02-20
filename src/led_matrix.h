
#pragma once
#include "util.h"
#include <Adafruit_NeoMatrix.h>

// add this to platformio.ini
// lib_deps = 
//     adafruit/Adafruit GFX Library
//     adafruit/Adafruit NeoMatrix
//     adafruit/Adafruit NeoPixel

class LedMatrix : public Adafruit_NeoMatrix
{
public:
    LedMatrix(uint8_t pin, uint16_t width, uint16_t height)
        : Adafruit_NeoMatrix(width, height, pin,
                             NEO_MATRIX_BOTTOM + NEO_MATRIX_RIGHT +
                                 NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                             NEO_GRB + NEO_KHZ800)
    {
    }

    void init()
    {
        begin();
        setBrightness(100);
        setTextWrap(false);
    }

    void showText(const char *msg, uint16_t color)
    {
        fillScreen(0);
        setCursor(0, 0);
        setTextColor(color);
        print(msg);
        show();
    }

    elapsedMillis _sinceWaveMove = 0;

    int _wave_x_position = 0;

    void loop()
    {
        if (_sinceWaveMove > 20)
        {
            _sinceWaveMove = 0;

            _wave_x_position = util::wrapf(_wave_x_position + 1, 0, width());
            setVerticalWave(_wave_x_position, 5, Color(255, 100, 240));
            
        }
    }

    void setVerticalWave(int x_position, int x_width, uint16_t color)
    {
        printf("setVerticalWave: %d, %d\n", x_position, x_width);
        for (int x = 0; x < width(); x++)
        {
            fillScreen(0);

            int x_in_wave = x - x_position;
            x_in_wave = util::wrapf(x_in_wave, 0, x_width);

            if (x_in_wave <= x_width)
                drawVerticalLine(x, color);
        }
        show();
    }

    void drawVerticalLine(int16_t x, uint16_t color)
    {
        drawLine(x, 0, x, height() - 1, color);
    }
};
