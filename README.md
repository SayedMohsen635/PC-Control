# 🖥️ PC Control Project – Design Plan

## 🚀 Overview
**PC Control** is a modular C++ server application that listens for client commands and performs system actions (such as launching applications).  
It demonstrates core C++ design concepts like modular programming, command parsing, socket communication, and logging — suitable as a prototype for showcasing my C++ learning.


## 🔄 System Flow
<p align="center">
  <img src="/SystemFlow.png" alt="System-Flow Diagram" style="max-width:100%; height:auto;">
</p>
```


## 💬 Communication Protocol

### 📨 **Request Format**
`COMMAND|PARAMETER`  
Example:  
```
LAUNCH|Chrome
EXIT
```

### 📤 **Response Format**
```
OK|Application Launched: Chrome
ERROR|Unknown command
OK|Good Bye
```


## 🧩 Module Responsibilities

| Module | Purpose |
|:--|:--|
| **Server** | Manages TCP socket connection, accepts client requests, and coordinates command processing |
| **Command** | Defines a `Command` class to represent parsed requests (command name and parameter) |
| **CommandParser** | Parses raw client input strings into `Command` objects for structured handling |
| **ActionHandler** | Determines which action to execute based on the command type (e.g., LAUNCH, EXIT) |
| **LaunchAppAction** | Executes system-level commands to open applications like Chrome or VS Code |
| **ResponseGenerator** | Formats clean, consistent responses (e.g., “OK|...” or “ERROR|...”) |
| **LoggingSystem** | Records executed actions, responses, and errors with timestamps |
| **Main** | Entry point that initializes and runs the server indefinitely |


## ⚙️ Example Flow

1. **Client sends** → `LAUNCH|chrome`  
2. **Server receives** the request and forwards it to `CommandParser`  
3. **CommandParser** converts it into a `Command("LAUNCH", "chrome")` object  
4. **ActionHandler** triggers `LaunchAppAction`  
5. **ResponseGenerator** returns → `OK|Launching Chrome`  
6. **LoggingSystem** records → `[INFO] Launched Chrome`  
7. **Server** sends the response back to the client  


## 📁 Project Structure

```
PC-Control/
│
├── Server/
│   ├── inc/
│   │   └── Server.hpp
│   └── src/
│       └── Server.cpp
│
├── Command/
│   ├── inc/
│   │   ├── Command.hpp
│   │   └── CommandParser.hpp
│   └── src/
│       └── CommandParser.cpp
│
├── ActionHandler/
│   ├── inc/
│   │   ├── Action.hpp
│   │   ├── ActionHandler.hpp
│   │   └── ActionResult.hpp
│   └── src/
│       ├── ActionHandler.cpp
│       └── LaunchAppAction.cpp
│
├── ResponseGenerator/
│   ├── inc/
│   │   └── ResponseGenerator.hpp
│   └── src/
│       └── ResponseGenerator.cpp
│
├── Logging/
│   ├── inc/
│   │   ├── LogEntry.hpp
│   │   └── LoggingSystem.hpp
│   └── src/
│       └── LoggingSystem.cpp
│
└── main.cpp
```


## 🧠 Future Improvements (Optional)
- Add authentication or token validation
- Allow multiple simultaneous clients (multi-threading)
- Add GUI or web client for sending commands
- Expand supported commands (shutdown, restart, etc.)
- Save logs to a file instead of memory


## ✅ Summary
This project represents a **complete end-to-end C++ system** that:
- Uses **modular, maintainable design**
- Demonstrates **socket programming**, **command parsing**, and **process execution**
- Includes **logging** and **clean response handling**

It’s perfect as a **learning showcase** or **prototype demo** for system-level C++ control applications.
