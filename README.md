# PIC16F877A ADC to 8-bit LCD Display

This project demonstrates how to read an analog signal using the ADC module of the PIC16F877A microcontroller and display the digital value on an 8-bit LCD in real-time.

## 📷 Project Overview

- **Microcontroller**: PIC16F877A  
- **Language**: Embedded C (MPLAB X IDE with XC8 Compiler)  
- **Peripherals Used**:
  - 8-bit LCD (16x2)
  - Potentiometer (Analog input on RA1)
  - ADC Module of PIC  
- **Clock Frequency**: 20 MHz

---

## 🛠️ Features

- Reads analog voltage from a potentiometer connected to RA1.
- Converts analog input to digital using the ADC module.
- Displays the 10-bit ADC value on an LCD in 4-digit format.
- Real-time updates.

---

## 🔧 Hardware Connections

| **LCD Pin** | **PIC Pin** | **Function**           |
|-------------|-------------|------------------------|
| RS          | RC0         | Register Select        |
| EN          | RC1         | Enable                 |
| D0-D7       | RD0-RD7     | Data Pins (8-bit mode) |

| **Other**   | **PIC Pin** | **Function**           |
|-------------|-------------|------------------------|
| Potentiometer | RA1       | Analog input (ADC)     |

---

## 🔋 Power Supply

- Use a +5V regulated power supply for the PIC and LCD.
- Ensure the potentiometer is properly connected between VCC and GND, with the wiper to RA1.

---

## 💻 Software Used

- **MPLAB X IDE**: For writing and compiling Embedded C code.
- **Proteus (optional)**: For simulation of circuit.
- **XC8 Compiler**: For compiling the C code.

---

## 🧾 How It Works

1. The ADC is configured to read analog input from RA1.
2. After each conversion, the 10-bit digital value is calculated from ADRESH and ADRESL.
3. This value is split into 4 digits and displayed on the LCD using `LCD_Char()` function.

---

## 📂 File Structure

📁 PIC16F877A_ADC_LCD_Display
┣ 📄 8 BIT LCD.c → Main C source code
┣ 📄 README.md → Project documentation
┗ 📁 Proteus_Simulation → Optional: Proteus .DSN file (if created)


---

## 🚀 Getting Started

1. Clone the repository or copy the source code.
2. Open the project in MPLAB X IDE.
3. Build and flash the code to your PIC16F877A.
4. Connect the hardware as per the schematic.
5. Observe the ADC value changing on the LCD as you rotate the potentiometer.

---

## 🧠 Learnings

- How to initialize and use ADC in PIC16F877A.
- LCD interfacing in 8-bit mode.
- Real-time value monitoring using embedded C.





## 📃 License

This project is open-source and free to use for educational purposes.



