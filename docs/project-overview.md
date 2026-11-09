AELD Final Project: Raspberry Pi Environmental Monitoring Service
Overview
The goal of this project is to develop a lightweight embedded Linux application running on a Raspberry Pi 4 which collects environmental sensor data and makes that information available across a network through a TCP socket interface.
The project demonstrates many concepts covered throughout the Advanced Embedded Linux Development course, including:
•	Linux system programming
•	Socket programming
•	POSIX threading
•	Service management with systemd
•	Embedded Linux image creation using Yocto
•	Cross-development workflows
•	Raspberry Pi hardware integration
The project will result in a deployable embedded Linux image capable of automatically starting the monitoring service during system startup.

---

Project Motivation
Embedded devices frequently collect data from sensors and provide that data over a network. This project provides a simplified implementation of such a system while demonstrating the core technologies used in embedded Linux products.

---
# Related Documents

- project-proposal.md
- architecture.md
- sprint-plan.md
- schedule.md


System Architecture
+----------------------+
|      Client PC       |
+----------+-----------+
           |
           | TCP Socket
           |
+----------v-----------+
|    Raspberry Pi 4    |
|                      |
| Monitoring Service   |
| Logging Service      |
| TCP Server           |
+----------+-----------+
           |
           |
+----------v-----------+
| Temperature Sensor   |
| (or simulated data)  |
+----------------------+
Target Build System
Yocto Project

---

Hardware Platform
•	Raspberry Pi 4 Model B
Resources:
•	https://www.raspberrypi.com/products/raspberry-pi-4-model-b/
•	https://docs.yoctoproject.org/

---

Open Source Projects Used
At this time no additional open source projects are planned beyond:
•	Yocto Project
•	Linux kernel
•	Systemd

---

Previous Assignment Content Utilized
The project reuses concepts developed throughout previous course assignments including:
•	Socket programming
•	Multithreaded programming
•	File and logging operations
•	Systemd service creation
•	GitHub Actions automation
•	Build and deployment workflows

---

Course Content Utilized
The project will utilize:
•	POSIX APIs
•	TCP/IP networking
•	Linux file I/O
•	Pthreads
•	Daemon/service management
•	Embedded Linux development
•	Yocto image generation
•	Software testing and automation

---

Additional Content Not Covered Directly In Course
The project may include:
•	Raspberry Pi hardware configuration
•	Environmental sensor integration
•	Remote monitoring concepts

---

Project-Specific Course Work
This project is being completed solely for the AELD course.

---

Repository Organization
Repository Layout:
aeld-final-project/
|
├── .github/workflows
├── docs
├── server
├── client
├── systemd
├── scripts
├── tests
└── README.md

The repository will contain:
•	Yocto-related customization
•	Monitoring server source code
•	Client source code
•	Test scripts
•	Systemd service files
•	Project documentation

---

Team Members
Patrice Renee Emery
Roles:
•	Architecture
•	Development
•	Testing
•	Documentation
•	Deployment

---

Schedule
See the Schedule page for sprint planning and project tracking.

# Documentation

The following documents provide additional project details:

- project-proposal.md
- architecture.md
- sprint-plan.md
- schedule.md

---

# Team Members

## Patrice Renee Emery

### Roles

- Architecture
- Development
- Testing
- Documentation
- Deployment

---

# Current Status

The project is currently in Sprint 1.

Refer to the following documents for implementation details and project tracking:

- sprint-plan.md
- schedule.md
