# Alpha Bot - Autonomous Line-Following Robot

An intelligent autonomous robot capable of line following, auto-parking, and wireless ZigBee control with advanced PID controller implementation.

## 🤖 Features

- **Line Following**: Precise black line tracking using PID controller
- **Auto Parking**: Intelligent parking maneuvers with node detection
- **Wireless Control**: ZigBee-based remote control with joystick interface
- **Multi-Modal Operation**: Seamless switching between autonomous and manual modes
- **Finite State Machine**: Robust state management using HEPTAGON framework

## 🏗️ System Architecture

The project implements a hybrid control system combining:
- **PID Controller**: For smooth line following with optimized Kp and Ki parameters
- **Finite State Machines**: Separate state machines for line following, parking, and obstacle avoidance
- **ZigBee Communication**: Wireless bidirectional communication between robot and controller
- **Sensor Integration**: IR sensors for line detection and proximity sensors for parking

## 📁 Project Structure

```
├── heptagon/
│   ├── line_follower.ept      # HEPTAGON finite state machine implementation
│   └── simulate.sh            # Simulation script for testing state machines
├── integrate.sh               # Integration and build script
└── supervisor/
    ├── alphabot_drivers.cpp   # Core robot driver implementations
    ├── alphabot_drivers.h     # Driver function declarations
    ├── joystick.ino          # ZigBee joystick controller code
    ├── line_follower.cpp     # Main line following logic
    ├── line_follower.h       # Line follower function declarations
    ├── line_follower_types.cpp # Data type implementations
    ├── line_follower_types.h  # Custom data type definitions
    └── supervisor.ino        # Main robot supervisor program
```

## 🚀 Getting Started

### Prerequisites
- Arduino IDE or compatible embedded development environment
- HEPTAGON compiler for finite state machine compilation
- ZigBee modules (transmitter and receiver)
- AlphaBot hardware platform with sensors

### Installation & Setup

1. **Clone the repository**
   ```bash
   git clone <repository-url>
   cd alpha-bot
   ```

2. **Compile HEPTAGON State Machines**
   ```bash
   cd heptagon
   ./simulate.sh
   ```

3. **Integrate and Build**
   ```bash
   ./integrate.sh
   ```

4. **Upload to Hardware**
   - Upload `supervisor/supervisor.ino` to the main robot
   - Upload `supervisor/joystick.ino` to the ZigBee controller

### Configuration

**PID Parameters (adjustable in code):**
- `Kp`: Proportional gain (tuned through collaborative testing)
- `Ki`: Integral gain (optimized for minimal overshoot)
- Sensor thresholds calibrated for specific lighting conditions

## 🎮 Operation Modes

### 1. Line Following Mode
- Autonomous navigation along black lines
- Real-time PID correction for smooth tracking
- Automatic node detection and decision making

### 2. Auto Parking Mode
- Triggered upon reaching designated parking zones
- Precise maneuvering using sensor feedback
- Automatic alignment and positioning

### 3. ZigBee Remote Control
- Manual override capability via wireless joystick
- Real-time command transmission
- Emergency stop functionality

## 🔧 Hardware Components

- **Main Controller**: Arduino-compatible microcontroller
- **Sensors**: IR line detection sensors, ultrasonic proximity sensors
- **Motors**: DC motors with encoder feedback
- **Communication**: ZigBee wireless modules
- **Power**: Rechargeable battery system
- **Chassis**: AlphaBot mechanical platform

## 👥 Team Contributions

This project was developed through collaborative effort with equal contribution from all team members in:
- System design and architecture planning
- PID controller implementation and tuning
- State machine logic development
- Hardware integration and testing
- Wireless communication setup

## 🛠️ Technical Implementation

**Control Algorithm**: PID controller with iteratively tuned parameters
**State Management**: HEPTAGON-based finite state machines
**Communication Protocol**: ZigBee wireless standard
**Programming Languages**: C/C++ for embedded systems, HEPTAGON for state machines

## 📊 Performance

- **Line Following Accuracy**: High precision tracking with minimal deviation
- **Response Time**: Real-time PID corrections at optimized update rates
- **Wireless Range**: Effective ZigBee communication within specified range
- **Battery Life**: Extended operation through efficient power management

## 🔮 Future Enhancements

- Dynamic obstacle avoidance algorithms
- Machine learning-based path optimization
- Enhanced sensor fusion for improved accuracy
- Mobile app integration for advanced control

## 📄 License

This project is developed for educational and research purposes.

## 🤝 Acknowledgments

Special thanks to all team members for their collaborative effort in design, implementation, and extensive testing phases that made this project successful.