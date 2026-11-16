# Project Proposal

## Project Name

### Raspberry Pi Monitoring and Control Service

---

## Objective

Develop a network-accessible monitoring and control service running on a Raspberry Pi 4 using a custom Yocto-generated Linux image.

The project will demonstrate integration of networking, multithreading, GPIO hardware interfaces, embedded Linux deployment, and automated service management within a single embedded Linux platform.

---

## Background

Embedded Linux devices commonly monitor hardware status and communicate information across a network while interacting with locally attached hardware.

The goal of this project is to implement a lightweight monitoring and control framework demonstrating core embedded Linux concepts using a Raspberry Pi 4.

---

## Project Goals

The project will:

- Build a custom Yocto Linux image
- Deploy software to Raspberry Pi 4 hardware
- Provide TCP-based network communication
- Implement GPIO output control
- Implement GPIO input monitoring
- Collect and report system statistics
- Integrate with systemd
- Reuse concepts developed during AELD coursework

---

## Hardware

### Primary Hardware

- Raspberry Pi 4 Model B

### Peripheral Hardware

- Breadboard
- LEDs
- Push Button
- Resistors
- Jumper Wires

All hardware will be supplied by the project author.

---

## Software Components

### aesd-monitor

Primary application providing:

- TCP server implementation
- Command processing
- GPIO monitoring
- GPIO control
- System status reporting

### Monitoring Subsystem

Collects:

- CPU utilization
- Memory utilization
- System uptime

### GPIO Subsystem

Provides:

- LED output control
- Push-button status monitoring

### systemd Integration

Provides:

- Automatic startup
- Restart capability
- Service management

### Yocto Integration

Provides:

- Application packaging
- Image creation
- Embedded deployment

---

## Connection to Previous Coursework

### Assignment 5

- TCP socket programming
- Client/server communication

### Assignment 6

- Threading
- Synchronization

### Assignment 7

- System service integration

### Assignment 8

- Embedded Linux build systems
- Cross compilation

### Assignment 9

- Device driver concepts
- Kernel and userspace interfaces

---

## Expected Deliverable

A bootable Raspberry Pi image capable of:

- Running the monitoring service
- Reporting system status
- Monitoring GPIO inputs
- Controlling GPIO outputs
- Accepting remote TCP client connections
- Starting automatically during boot

---

## Success Criteria

The project will be considered complete when:

- The Raspberry Pi boots a custom Yocto image
- The monitoring service starts automatically through systemd
- A network client can connect to the service
- GPIO hardware can be monitored and controlled
- System status information can be retrieved remotely
- The project can be demonstrated on physical hardware

---

## Planned Repository Organization

```text
aeld-final-project/
|
├── docs
├── applications
│   └── aesd-monitor
├── yocto
├── systemd
├── scripts
├── tests
└── README.md
```

All project artifacts, source code, documentation, and deployment files will be maintained within a single repository.
