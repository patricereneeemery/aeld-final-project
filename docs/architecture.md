# System Architecture

## Overview

The system consists of a Raspberry Pi 4 hosting a monitoring service which accepts client connections over TCP/IP.

## High-Level Architecture

```text
+--------------------+
|     Client PC      |
+---------+----------+
          |
          | TCP/IP
          |
+---------v----------+
| Raspberry Pi 4     |
|                    |
| Monitoring Server  |
| Thread Manager     |
| Logging Module     |
| Systemd Service    |
+---------+----------+
          |
          |
+---------v----------+
| Sensor Input       |
| (or simulation)    |
+--------------------+


# Major Components

## Monitoring Server

### Responsibilities

- Accept client connections
- Process client requests
- Return monitoring data to connected clients

The Monitoring Server serves as the primary interface between the Raspberry Pi and remote clients. It listens for incoming TCP connections and provides access to environmental monitoring data.

---

## Thread Manager

### Responsibilities

- Manage concurrent client connections
- Create and monitor worker threads
- Synchronize access to shared resources
- Prevent data corruption during concurrent operations

The Thread Manager enables multiple clients to interact with the monitoring service simultaneously while maintaining system stability and data integrity.

---

## Logging Module

### Responsibilities

- Record server activity
- Record monitoring data
- Log client connections and requests
- Support debugging and operational monitoring

The Logging Module provides persistent records of system operation and assists with troubleshooting and validation of system behavior.

---

## Systemd Service

### Responsibilities

- Automatically start the application during system boot
- Monitor service health
- Restart the application after failures
- Support embedded deployment requirements

The Systemd Service enables the application to operate as a managed Linux service and ensures reliable startup and operation.

---

# Hardware Platform

## Raspberry Pi 4

The Raspberry Pi 4 was selected as the hardware platform for this project because it:

- Is supported by the Yocto Project
- Is widely available and well documented
- Provides a suitable embedded Linux development environment
- Has strong community and software support
- Offers sufficient processing and networking capabilities for the project requirements

---

# Operating System Strategy

## Development Environment

**Raspberry Pi OS**

The development and initial testing environment will utilize Raspberry Pi OS to simplify hardware configuration, software development, and debugging activities.

## Deployment Environment

**Yocto Linux Image**

The final project deliverable will target a custom Yocto-based Linux image, demonstrating embedded Linux build system integration and deployment practices covered in the course.
