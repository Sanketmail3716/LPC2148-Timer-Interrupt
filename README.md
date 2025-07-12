# LPC2148 Timer Interrupt LED Blink

This project demonstrates the use of **Timer0 interrupt** in the **LPC2148 ARM7 microcontroller** to toggle two LEDs connected to GPIO pins **P0.17** and **P0.18**. It uses match register interrupts to control LED blinking without blocking the main program execution.

---

## 🛠️ Features

- Timer0 Match Register (MR0) configured for periodic interrupt
- LED toggle using GPIO pins in the ISR
- Uses VIC (Vectored Interrupt Controller)
- PLL configured for system clock

---

## 💡 Hardware Requirements

- LPC2148 Development Board
- Two LEDs connected to P0.17 and P0.18
- Keil uVision / Flash Magic or suitable IDE + programmer

---

## 📁 Project Structure

Timer_interrupt/
├── main.c // Main source code
├── PLL.h // Header for PLL configuration
├── README.md // Project documentation


---

## 🔧 How It Works

1. PLL is initialized to set the CPU clock.
2. Timer0 is configured with prescaler and match register.
3. When Timer0 matches MR0, an interrupt is triggered.
4. ISR (`TIMER1`) toggles the state of the LEDs using `IO0SET` and `IO0CLR`.

---

## 🧠 Key Registers Used

- `T0MR0` – Match Register 0
- `T0MCR` – Match Control Register
- `T0IR`  – Interrupt Register
- `T0TCR` – Timer Control Register
- `VICVectAddr0`, `VICVectCntl0`, `VICIntEnable` – for interrupt setup

---

## 🧪 Example Output

LEDs on P0.17 and P0.18 toggle ON/OFF at a fixed interval defined by Timer0.

---

## 📜 License

This project is open-source and free to use for educational purposes.

---

## 👨‍💻 Author

**Sanket Mali**  
[GitHub Profile](https://github.com/Sanketmail3716)

