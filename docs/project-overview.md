# Project Overview

## Project Title

Embedded System Monitoring and Health Management Service

---

## Project Description

The Embedded System Monitoring and Health Management Service is a lightweight embedded Linux application designed for deployment on a Raspberry Pi 4 using the Yocto Project.

The application continuously monitors platform health and operating system metrics including CPU utilization, memory utilization, disk utilization, load average, system uptime, and hostname information.

Collected metrics are made available through a REST API, historical logging subsystem, alert framework, and web-based dashboard.

The project demonstrates embedded Linux software development techniques including Linux systems programming, networking, service integration, process monitoring, multithreading, and Yocto deployment.

The software primarily utilizes ANSI C and POSIX APIs for Linux system interaction while incorporating C++17 and selected STL containers where they improve maintainability, concurrency, and software architecture.

---

## Problem Statement

Many embedded Linux devices operate unattended and provide limited visibility into system health and operating conditions.

Developers and administrators require mechanisms to monitor CPU utilization, memory consumption, storage usage, and overall platform status to support troubleshooting, maintenance, and operational awareness.

This project addresses those needs through the development of a lightweight embedded monitoring platform capable of providing real-time and historical visibility into system performance.

---

## Project Objectives

- Develop a reusable embedded monitoring service
- Monitor core Linux operating system metrics
- Provide a lightweight REST API
- Provide a browser-based dashboard
- Implement historical metric logging
- Implement threshold-based alerting
- Deploy through the Yocto Project
- Demonstrate Linux systems programming concepts
- Utilize modern C/C++ development practices

---

## Expected Deliverables

- Monitoring Service
- Metrics Collection Framework
- REST API
- Web Dashboard
- Historical Logging Module
- Alert Framework
- Yocto Integration
- systemd Service
- Testing Documentation
- Final Demonstration

---

## Success Criteria

The project will be considered successful when:

- System metrics are collected accurately
- REST API endpoints function correctly
- Dashboard displays live system information
- Logging subsystem records historical data
- Alert framework generates warnings
- Application deploys through Yocto
- Service starts automatically at boot
- Final demonstration requirements are satisfied
