# Classic ESP32 Pin Usage

## Source
For more detailed information, visit: [RandomNerdTutorials ESP32 Pinout Reference](https://randomnerdtutorials.com/esp32-pinout-reference-gpios/)

## Important Considerations

### Safe Pins for General Use (Input/Output)
- GPIO 4, 13, 16-19, 21-23, 25-27, 32-33
- These pins have no special considerations and are safe for both input and output

### Input-Only Pins
- GPIO 34-39
- These pins can ONLY be used as inputs
- No internal pull-up/pull-down resistors

### Pins to Avoid
- GPIO 6-11 (connected to integrated SPI flash)
- Do not use these in your projects

### ADC Considerations
- ADC1 (GPIO 32-39): Can be used when WiFi is active
- ADC2 (GPIO 0, 2, 4, 12-15, 25-27): Cannot be used when WiFi is active

### Maximum Current
- 40mA per GPIO pin

## Detailed Pin Table

| GPIO | Input      | Output | Notes |
|------|-----------|--------|------------------------------------------------------------|
| 0    | pulled up | OK     | outputs PWM signal at boot, must be LOW to enter flashing mode |
| 1    | TX pin    | OK     | debug output at boot |
| 2    | OK        | OK     | connected to on-board LED, must be left floating or LOW to enter flashing mode |
| 3    | OK        | RX pin | HIGH at boot |
| 4    | OK        | OK     |  |
| 5    | OK        | OK     | outputs PWM signal at boot, strapping pin |
| 6    | x         | x      | connected to the integrated SPI flash |
| 7    | x         | x      | connected to the integrated SPI flash |
| 8    | x         | x      | connected to the integrated SPI flash |
| 9    | x         | x      | connected to the integrated SPI flash |
| 10   | x         | x      | connected to the integrated SPI flash |
| 11   | x         | x      | connected to the integrated SPI flash |
| 12   | OK        | OK     | boot fails if pulled high, strapping pin |
| 13   | OK        | OK     |  |
| 14   | OK        | OK     | outputs PWM signal at boot |
| 15   | OK        | OK     | outputs PWM signal at boot, strapping pin |
| 16   | OK        | OK     |  |
| 17   | OK        | OK     |  |
| 18   | OK        | OK     |  |
| 19   | OK        | OK     |  |
| 21   | OK        | OK     |  |
| 22   | OK        | OK     |  |
| 23   | OK        | OK     |  |
| 25   | OK        | OK     |  |
| 26   | OK        | OK     |  |
| 27   | OK        | OK     |  |
| 32   | OK        | OK     |  |
| 33   | OK        | OK     |  |
| 34   | OK        |        | input only |
| 35   | OK        |        | input only |
| 36   | OK        |        | input only |
| 39   | OK        |        | input only |

## Common Pin Functions

### Default UART (Programming)
- GPIO 1 (TX)
- GPIO 3 (RX)

### Default I2C
- GPIO 21 (SDA)
- GPIO 22 (SCL)

### Default SPI (VSPI)
- GPIO 23 (MOSI)
- GPIO 19 (MISO)
- GPIO 18 (CLK)
- GPIO 5  (CS)

### DAC Pins
- GPIO 25 (DAC1)
- GPIO 26 (DAC2)

