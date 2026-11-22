# Sprint Plan

## Project Goal

Develop an Embedded System Monitoring and Health Management Service running on a Raspberry Pi 4 and deployed using the Yocto Project.

The application will provide Linux system monitoring capabilities through a TCP/IP client-server architecture while exposing collected data through logging, alerting, REST API services, and a web-based dashboard.

The project will demonstrate embedded Linux development concepts including:

- Linux Systems Programming
- TCP/IP Networking
- Multithreading
- Process Monitoring
- systemd Integration
- Yocto Deployment
- Service Management
- Software Architecture

---

## Sprint 1 - Foundation and Environment Setup

### Goal

Establish the project infrastructure, development environment, documentation, and initial networking framework.

### Tasks

1. Configure Raspberry Pi development environment
2. Establish remote development workflow
3. Organize repository structure
4. Configure GitHub Actions workflow
5. Create initial TCP server prototype
6. Create project documentation
7. Define project architecture
8. Validate development and testing environment

### Deliverables

- Operational Raspberry Pi development environment
- Repository structure
- GitHub Actions workflow
- Initial TCP server implementation
- Project documentation
- Architecture definition

### Completion Criteria

- Raspberry Pi accessible via SSH
- Development tools installed and operational
- Repository configuration completed
- GitHub Actions workflow passes
- Initial TCP server accepts client connections
- Documentation approved
- Sprint 1 issues closed

---

## Sprint 2 - Core Monitoring Platform Development

### Goal

Implement the monitoring engine, networking services, logging, alerting, and complete the project architecture pivot.

### Tasks

#### Issue 14 - Project Pivot

1. Update architecture documentation
2. Update sprint plans
3. Update project requirements
4. Update implementation strategy

#### Issue 6 - Core Monitoring Service

1. Implement CPU utilization monitoring
2. Implement memory utilization monitoring
3. Implement hostname monitoring

#### Issue 7 - TCP Monitoring Server

1. Implement socket communication
2. Implement request processing
3. Implement client handling
4. Implement command processing

#### Issue 8 - Extended Metrics

1. Implement disk utilization monitoring
2. Implement load average monitoring
3. Implement uptime monitoring

#### Issue 10 - Logging and Alerting

1. Implement historical logging
2. Implement event logging
3. Implement threshold evaluation
4. Implement alert generation

### Deliverables

- Functional monitoring engine
- TCP monitoring server
- System metrics collection framework
- Historical logging subsystem
- Alert framework
- Updated project documentation

### Completion Criteria

- Clients can connect successfully
- Monitoring requests are processed correctly
- Monitoring metrics are collected accurately
- Monitoring information is returned to clients
- Logging subsystem records activity
- Alerts generate correctly
- Sprint 2 issues closed

---

## Sprint 3 - Integration and Deployment

### Goal

Integrate application services, complete deployment, and prepare final project deliverables.

### Tasks

#### Issue 9 - REST API

1. Implement API endpoints
2. Implement JSON responses
3. Validate API functionality

#### Issue 11 - Web Dashboard

1. Develop dashboard interface
2. Display monitoring data
3. Integrate dashboard with API

#### Issue 12 - Yocto Integration

1. Create Yocto integration
2. Configure package deployment
3. Configure systemd service
4. Configure automatic startup

#### Issue 13 - Final Validation

1. Perform integration testing
2. Verify deployment functionality
3. Complete project documentation
4. Prepare demonstration materials
5. Record final video demonstration

### Deliverables

- REST API
- Web dashboard
- Yocto package integration
- systemd service configuration
- Completed documentation
- Final testing results
- Demonstration-ready system

### Completion Criteria

- REST API functions correctly
- Dashboard displays monitoring information
- Application included in Yocto image
- Service starts automatically at boot
- Testing successfully completed
- Documentation finalized
- Final project ready for submission

---

## Sprint Summary

| Sprint | Focus | Primary Deliverable |
|----------|----------|----------|
| Sprint 1 | Environment and Infrastructure | Development Platform and Prototype Server |
| Sprint 2 | Monitoring Platform Development | Functional Monitoring Service |
| Sprint 3 | Integration and Deployment | Yocto-Based Embedded Linux Solution |

---

## Risk Management

### Hardware Risks

#### Risk

Raspberry Pi hardware failures or instability may delay development and testing activities.

#### Mitigation

- Maintain remote access backups
- Use Linux workstation for development where appropriate
- Test individual software components independently
- Maintain frequent source control commits

---

### Schedule Risks

#### Risk

Yocto integration and deployment may require more effort than originally planned.

#### Mitigation

- Begin Yocto preparation prior to Sprint 3
- Validate deployment incrementally
- Focus on core functionality before advanced features

---

### Integration Risks

#### Risk

Combining monitoring, networking, logging, alerting, dashboard, and deployment functionality may introduce unexpected interactions.

#### Mitigation

- Perform incremental testing
- Utilize GitHub Actions validation
- Validate subsystems independently before integration
- Conduct regular integration testing throughout development

---

### Project Scope Risks

#### Risk

Originally planned GPIO and breadboard functionality introduced hardware complexity and increased project risk.

#### Mitigation

- Shift focus toward embedded Linux software development
- Emphasize monitoring, networking, and deployment functionality
- Retain Raspberry Pi platform while removing hardware dependency

---

## Future Product Backlog

The following items are considered potential post-course enhancements and are not required for successful project completion.

### Monitoring Enhancements

- CPU temperature monitoring
- Network utilization monitoring
- Process monitoring
- Service health monitoring
- Storage trend analysis

### Dashboard Enhancements

- Historical charts
- Real-time metric updates
- User authentication
- Mobile-responsive interface

### Alerting Enhancements

- Email notifications
- SMS notifications
- Configurable alert profiles
- Alert acknowledgement workflow

### Deployment Enhancements

- Docker container deployment
- Buildroot support
- Multi-device monitoring
- Remote configuration management

### Hardware Enhancements

- GPIO status indicators
- LED health indicators
- Push-button service controls
- Sensor integration
- Environmental monitoring peripherals

---

## Success Criteria

The project will be considered successful when:

1. The monitoring service operates correctly on Raspberry Pi 4.
2. TCP clients can communicate with the monitoring server.
3. System metrics can be collected and returned successfully.
4. The application operates as a systemd-managed service.
5. The application is integrated into a Yocto-generated Linux image.
6. REST API services function correctly.
7. Dashboard functionality is demonstrated successfully.
8. Historical logging operates correctly.
9. Alert generation operates correctly.
10. All project documentation and deliverables are completed.
11. The final demonstration is successfully completed.
