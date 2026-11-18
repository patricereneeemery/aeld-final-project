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
- Create build framework
- Create TCP server module
- Create system monitoring module
- Create GPIO module
- Establish application architecture

## Assigned Issues

| Issue | Description | Status |
|---------|---------|---------|
| #3 | TCP Server Prototype | Planned |

## Dependencies and Blockers

### Issue #3

Depends On:

- Issue #1 Repository Setup and Documentation
- Issue #2 Raspberry Pi Platform Bring-Up

Blocks:

- Future TCP Command Processing
- Future System Monitoring Integration
- Future GPIO Hardware Integration

## Definition of Done

### Issue #3

Sprint 1 will be considered complete when:

- applications/aesd-monitor directory exists
- Makefile exists
- Source tree exists
- TCP server module exists
- Monitoring module exists
- GPIO module exists
- Application builds successfully using make
- Executable runs successfully
- Source code committed to repository
- Documentation updated to reflect implementation status

---

# Sprint 2

## Planned Objectives

- Implement TCP client connections
- Implement INFO command
- Implement STATUS command
- Implement command processing framework

## Planned Deliverables

- TCP listener
- Command parser
- Network testing

---

# Sprint 3

## Planned Objectives

- Implement GPIO subsystem
- Integrate LED output
- Integrate push button input
- Integrate system monitoring
- Package application for deployment

## Planned Deliverables

- GPIO support
- Hardware testing
- Yocto integration
- systemd integration

---

# Current Status

Current Phase:

**Planning Complete**

Next Phase:

**Sprint 1 - TCP Server Prototype**

Project Status:

**On Schedule**
