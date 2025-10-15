# PC Control Project Design Plan

## Overview
A modular C++ server application that listens for client commands and performs system actions (e.g., opening Chrome), with basic security and logging.

## System Flow
<p align="center">
  <img src="/SystemFlow.png" alt="System-Flow Diagram" style="max-width:100%; height:auto;">
</p>


## Communication Protocol
**Request Format:**
`TOKEN|COMMAND|PARAMETER`  
Example: `SECRET123|OPEN_APP|chrome`

**Response Format:**  
`OK|App launched successfully`  
`ERR|Invalid token`

## Module Responsibilities

|         Module        |       Purpose       |
|-----------------------|---------------------|
| **Server**            | Handles networking; receives requests and sends responses |
| **Security**          | Validates tokens or credentials |
| **Command**           | Parses and structures client requests |
| **ActionHandler**     | Decides which action to perform |
| **LaunchApplication** | Executes system-level commands |
| **ResponseGenerator** | Formats the output message |
| **LoggingSystem**     | Records actions and results into a log file |
| **Main**              | Entry point; initializes and coordinates modules |

