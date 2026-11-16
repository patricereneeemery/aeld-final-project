# Raspberry Pi Monitoring and Control Service

## Overview

The goal of this project is to develop a lightweight embedded Linux application running on a Raspberry Pi 4 which monitors system status while providing remote access through a TCP socket interface.

The project demonstrates many concepts covered throughout the Advanced Embedded Linux Development course, including:

- Linux system programming
- Socket programming
- POSIX threading
- Service management with systemd
- Embedded Linux image creation using Yocto
- Cross-development workflows
- Raspberry Pi GPIO integration

The project will result in a deployable embedded Linux image capable of automatically starting the monitoring service during system startup.

## Project Motivation

Embedded Linux systems frequently collect status information, provide network services, and interact with physical hardware through GPIO interfaces.

The goal of this project is to create a custom Yocto-based Linux system running on a Raspberry Pi 4 that provides:

- Remote monitoring of Linux system resources
- TCP-based access to system information
- GPIO-based hardware control
- GPIO-based hardware monitoring
- Reuse of previously developed AELD components

The project demonstrates the integration of Linux system programming, networking, multithreading, embedded deployment, and hardware interfaces into a single deployable platform.

## Related Documents

- `project-proposal.md`
- `architecture.md`
- `sprint-plan.md`
- `schedule.md`

## System Architecture

```text
                    +----------------+
                    |   Remote Client |
                    | Laptop/Desktop  |
                    +--------+--------+
                             |
                           TCP/IP
                             |
                             v

+------------------------------------------------+
| Raspberry Pi 4                                 |
|------------------------------------------------|
| aesd-monitor Service                           |
|------------------------------------------------|
| TCP Server                                     |
|------------------------------------------------|
| System Monitoring                              |
|   - CPU Usage                                  |
|   - Memory Usage                               |
|   - Uptime                                     |
|------------------------------------------------|
| GPIO Monitoring and Control                    |
|------------------------------------------------|
| systemd Service Integration                    |
|------------------------------------------------|
| Hardware                                       |
|   - LED Output                                 |
|   - Push Button Input                          |
+------------------------------------------------+
```

## Target Build System

### Yocto Project

The Yocto Project will be used to:

- Build the Linux image
- Cross-compile project components
- Package application software
- Deploy a reproducible embedded Linux platform

### References

- https://www.yoctoproject.org/
- https://docs.yoctoproject.org/

## Hardware Platform

### Primary Hardware

- Raspberry Pi 4 Model B

### Additional Hardware

- Breadboard
- LEDs
- Push Button
- Resistors
- Jumper Wires

### Resources

- https://www.raspberrypi.com/products/raspberry-pi-4-model-b/
- https://www.raspberrypi.com/documentation/

### Hardware Source

All hardware used for the project is owned by the project author.

No departmental hardware loans are currently required.

## Open Source Projects Used

### Yocto Project

Used for embedded Linux image generation and deployment.

https://www.yoctoproject.org/

### Linux Kernel

Provides networking, threading, process management, and GPIO interfaces.

https://www.kernel.org/

### systemd

Provides automatic startup and service management.

https://systemd.io/

No additional open source projects are currently planned beyond the standard embedded Linux software stack.

## Previous Assignment Content Utilized

The project reuses concepts and implementation techniques developed throughout previous assignments.

### Assignment 5

Socket Programming

Reuse:

- TCP communication framework
- Client/server architecture

### Assignment 6

Multithreading and Synchronization

Reuse:

- Thread creation
- Thread management
- Concurrent processing

### Assignment 7

Linux Service Management

Reuse:

- Daemon execution
- Automatic startup
- Service integration

### Assignment 8

Embedded Linux Build Systems

Reuse:

- Cross-compilation workflows
- Embedded deployment concepts

### Assignment 9

Character Device Driver Development

Reuse:

- Kernel-space/user-space interface concepts
- Device interaction models
- Driver integration concepts

## Previously Discussed Course Content Utilized

The project will utilize:

### Linux System Programming

- File operations
- Memory management concepts
- Process management

### POSIX Threads

- Concurrent execution
- Shared resource management

### TCP/IP Networking

- Socket programming
- Client/server communications

### Embedded Linux

- Deployment to target hardware
- Service management

### Build Systems

- Yocto image generation
- Application packaging

## New Content

### Previously Discussed in Class but Not Used in Previous Assignments

#### Raspberry Pi GPIO Integration

The project will directly interface with Raspberry Pi GPIO hardware.

#### Yocto Application Packaging

The project will package custom application software into a Yocto-generated Linux image.

### New Material Not Previously Covered

#### Hardware Monitoring and Control

The project will integrate physical hardware inputs and outputs through GPIO interfaces.

#### Embedded System Integration

The project combines networking, hardware interaction, system monitoring, service management, and embedded deployment into a single platform.

## Shared Material

This project is being completed exclusively for the Advanced Embedded Linux Development course.

No content from other courses is being reused.

Previously completed AELD assignments are referenced only as a source of concepts and implementation techniques developed by the project author.

## Source Code Organization

### Student Submission Repository

Project repository:

`https://github.com/patricereneeemery/aeld-final-project\`

This repository will contain:

- Project documentation
- Source code
- Sprint planning artifacts
- Yocto integration
- systemd service files
- Test scripts
- Build artifacts

### Planned Repository Layout

```text
aeld-final-project/
|
├── .github/workflows
├── docs
├── applications
│   └── aesd-monitor
│       ├── Makefile
│       ├── src
│       └── README.md
├── yocto
├── systemd
├── scripts
├── tests
└── README.md
```

### Additional Repositories

No additional repositories are currently planned.

If additional repositories become necessary during implementation they will be documented and linked from this page.

## Individual Project Overview

### Student

Patrice Renee Emery

### Responsibilities

- Architecture
- Development
- Testing
- Documentation
- Deployment
- Sprint Planning

## Schedule Page

See the project schedule and sprint tracking page:

`[[Schedule]]`

The schedule page contains:

- Sprint plans
- Assigned issues
- Definitions of Done (DoD)
- Dependencies
- Current project status

## Current Status

The project is currently in Sprint 1.

Refer to the following documents for implementation details and project tracking:

- `project-proposal.md`
- `architecture.md`
- `sprint-plan.md`
- `schedule.md`
