# SPI Communication Between ESP32 and STM32F4

This project demonstrates SPI communication between an ESP32 (acting as the SPI master) and an STM32F4 microcontroller (acting as the SPI slave). The ESP32 sends a string message to the STM32F4, which processes the received data and toggles an LED to indicate successful communication.

## Features

- **SPI Master (ESP32):**
  - Sends a predefined string message over SPI.
  - Uses the HSPI bus with custom GPIO pins for SPI communication.
  - Toggles an onboard LED to indicate data transmission.

- **SPI Slave (STM32F4):**
  - Receives data over SPI using interrupt-based communication.
  - Transmits the received data over UART for debugging.
  - Toggles an LED to indicate successful data reception.

## Hardware Requirements

- **ESP32-CAM** (or any ESP32 board with HSPI support).
- **STM32F407VG** microcontroller (or compatible STM32F4 series board).
- SPI-compatible wiring between ESP32 and STM32F4:
  - `SCK` (Clock)
  - `MOSI` (Master Out Slave In)
  - `NSS` (Chip Select)

## Software Requirements

- **Arduino IDE** for programming the ESP32.
- **STM32CubeIDE** for programming the STM32F4.
- STM32 HAL library for SPI and UART communication.

## Wiring Diagram

| ESP32 Pin | STM32 Pin |
|-----------|-----------|
| GPIO14 (SCK) | PA5 (SPI1_SCK) |
| GPIO13 (MOSI) | PA7 (SPI1_MOSI) |
| GPIO15 (CS)   | PA4 (SPI1_NSS)  |

## Project Structure

```
spi-esp32-stm32/
├── ESP32/
│   └── spi.ino          # ESP32 SPI master code
├── STM32/
│   ├── Core/
│   │   ├── Inc/         # STM32 header files
│   │   ├── Src/         # STM32 source files
│   └── spi.ioc          # STM32CubeMX configuration file
├── LICENSE              # MIT License
└── README.md            # Project documentation
```

## Usage Instructions

### 1. ESP32 Setup
1. Open the `spi.ino` file in the Arduino IDE.
2. Configure the SPI pins and message to be sent.
3. Upload the code to the ESP32 board.

### 2. STM32 Setup
1. Open the `spi.ioc` file in STM32CubeIDE to view the hardware configuration.
2. Build and upload the STM32 project to the STM32F4 board.
3. Connect the STM32 to a serial terminal to view the received data over UART.

### 3. Run the Project
1. Power both the ESP32 and STM32 boards.
2. Observe the following:
   - The ESP32 sends the message "hello spi" every second.
   - The STM32 receives the message, toggles an LED, and sends the data over UART.

## License

This project is licensed under the [MIT License](LICENSE).

## Author

Developed by **Yassine Gharbi**.

For any questions or contributions, feel free to open an issue or submit a pull request.
