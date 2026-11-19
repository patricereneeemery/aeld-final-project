# Schedule

## Project Overview

The project is divided into a planning phase followed by three implementation sprints corresponding to the course schedule.

---

# Planning Phase

## Objectives

- Create project repository
- Create project documentation
- Create project overview
- Create project schedule
- Bring up Raspberry Pi 4
- Verify network connectivity
- Verify SSH access
- Define project architecture

## Completed Issues

| Issue | Description | Status |
|---------|---------|---------|
| #1 | Repository Setup and Documentation | Complete |
| #2 | Raspberry Pi Platform Bring-Up | Complete |

## Definition of Done Verification

### Issue #1

Definition of Done verified.

Completed:

- Repository created
- README created
- Project Overview page created
- Schedule page created
- Repository structure defined
- Project documentation committed

### Issue #2

Definition of Done verified.

Completed:

- Raspberry Pi OS installed
- Raspberry Pi booted successfully
- Wi-Fi configured successfully
- Network connectivity verified
- SSH access verified
- Development environment validated

---

# Sprint 1

## Objectives

- Create aesd-monitor application structure
- Implement TCP command processing
- Implement system monitoring framework
- Establish application architecture
- Prepare for GPIO integration

## Completed Issues

| Issue | Description | Status |
|---------|---------|---------|
| #3 | TCP Server Prototype | Complete |

## Active Issues

| Issue | Description | Status |
|---------|---------|---------|
| #4 | TCP Command Processing | Open |
| #5 | System Monitoring Integration | Open |

---

## Issue Dependencies and Blockers

### Issue #4

Depends On:

- Issue #3 TCP Server Prototype

Blocks:

- Issue #5 System Monitoring Integration

### Issue #5

Depends On:

- Issue #3 TCP Server Prototype
- Issue #4 TCP Command Processing

Blocks:

- Future GPIO Hardware Integration
- Future Yocto Integration

---

## Definition of Done Verification

### Issue #3

Definition of Done verified.

Completed:

- applications/aesd-monitor directory created
- Makefile created
- Source tree created
- TCP server module created
- Monitoring module created
- GPIO module created
- Application builds successfully
- Executable runs successfully
- Source code committed to repository

Testing:

- Verified successful build using make
- Verified executable launches successfully

---

# Sprint 2

## Planned Objectives

- Implement GPIO subsystem
- Integrate LED output
- Integrate push button input
- Add hardware monitoring functionality

## Planned Deliverables

- GPIO hardware support
- LED control
- Push button monitoring
- Hardware testing

---

# Sprint 3

## Planned Objectives

- Create Yocto integration
- Package application
- Create systemd service
- Deploy to Raspberry Pi
- Complete final validation and testing

## Planned Deliverables

- Yocto image integration
- systemd integration
- Deployment testing
- Final demonstration

---

# Current Status

Current Phase:

**Sprint 2**

Current Focus:

**GPIO Hardware Integration (#6)**

Project Status:

**On Schedule**
