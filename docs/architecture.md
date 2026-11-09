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

Major Components
Monitoring Server
Responsibilities:
Accept client connections
Process requests
Return monitoring data
Thread Manager
Responsibilities:
Manage concurrent client connections
Synchronize shared resources
Logging Module
Responsibilities:
Record server activity
Record monitoring data
Systemd Service
Responsibilities:
Automatically start application
Restart service on failures
Hardware Platform
Raspberry Pi 4
Selected because:
Supported by Yocto
Widely available
Suitable embedded development platform
Strong Linux support
Operating System
Raspberry Pi OS (development)
Yocto Linux image (deployment target) 
