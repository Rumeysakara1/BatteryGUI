# Battery GUI Application

This project is a Qt-based graphical user interface for a Battery and BatteryPack system.

## Features
- Create batteries by entering voltage and capacity
- Create battery packs with SERIES or PARALLEL connections
- Display total voltage, capacity, and current charge
- Simulate battery usage and recharging
- Visual representation of batteries:
  - SERIES: batteries stacked vertically
  - PARALLEL: batteries stacked horizontally

## How to Compile
1. Open the project using Qt Creator
2. Select Release configuration
3. Run qmake
4. Build the project

## How to Run
- Run `BatteryGUI.exe` from the build folder
- Or run directly from Qt Creator

## Notes
- Battery usage and recharge are simulated in 1-hour steps
- The GUI updates both numerical values and visual battery levels
