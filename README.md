# AELD Final Project

## Raspberry Pi Monitoring and Control Service

This repository contains the individual submission for the Advanced Embedded Linux Development (AELD) Final Project.

## Project Overview

Project documentation and planning information are available in the GitHub Wiki:

https://github.com/patricereneeemery/aeld-final-project/wiki/Project-Overview
## Source Code Organization

### Build System Repository

Build system and application development repository:

https://github.com/patricereneeemery/aeld-final-project

This repository contains:

- Yocto integration
- Application source code
- Documentation
- Sprint planning
- Service definitions
- Testing artifacts

### Additional Repositories

No additional repositories are currently planned.

All project source code, build system configuration, documentation, and deployment artifacts will be maintained in a single repository.

## Documentation

Project documentation is maintained in the `docs` directory.

- `docs/project-overview.md`
- `docs/project-proposal.md`
- `docs/architecture.md`
- `docs/sprint-plan.md`
- `docs/schedule.md`

## Repository Structure

```text
aeld-final-project/
|
├── .github/workflows
├── docs
├── applications
│   └── aesd-monitor
├── yocto
├── systemd
├── scripts
├── tests
└── README.md
```
## Project Roadmap

```mermaid
timeline
    title AELD Final Project

    Sprint 1 : Documentation
             : Raspberry Pi Bring-Up

    Sprint 2 : TCP Server
             : Command Parsing

    Sprint 3 : GPIO Integration
             : Hardware Testing

    Sprint 4 : Yocto Packaging
             : Final Demonstration


## Hardware Platform

- Raspberry Pi 4 Model B
- LED
- Push Button
- Breadboard
- Resistors
- Jumper Wires

## Current Status

Sprint 1 - Planning and Platform Bring-Up

## Student

Patrice Renee Emery

## Build

TBD

## Run

TBD
