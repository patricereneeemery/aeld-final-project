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
