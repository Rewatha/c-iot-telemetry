# 📡 C-Based IoT Telemetry Agent

A high-performance system utility developed in **C (ISO C11)** that simulates an IoT edge device. It captures real-time sensor metrics and synchronizes them with a cloud-based **PostgreSQL** database via RESTful APIs.

![Status](https://img.shields.io/badge/Status-Active-success)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-blue)

## 🏗️ System Architecture
`[IoT Device (C Code)]`  -->  `[JSON Serialization]`  -->  `[HTTPS/cURL]`  -->  `[Supabase Cloud DB]`

## 🚀 Key Technical Achievements
* **Low-Level Networking:** Implemented a custom network layer using `libcurl` system calls to execute secure HTTP POST requests from a C environment.
* **Manual Memory Management:** Designed efficient `struct` data models to handle sensor payloads with minimal memory overhead.
* **Cloud Integration:** Configured a **Supabase (PostgreSQL)** backend to ingest, validate, and store time-series telemetry data.
* **Cross-Platform Compatibility:** Written in standard C, compatible with GCC and MinGW compilers.

## 🛠️ Technology Stack
* **Core:** C (Programming Language)
* **Backend:** Supabase (PostgreSQL)
* **Protocol:** REST API (JSON payloads)
* **Tools:** VS Code, Git, cURL

## 💻 How to Run
1.  Clone the repository:
    ```bash
    git clone [https://github.com/Rewatha/c-telemetry-system.git](https://github.com/Rewatha/c-telemetry-system.git)
    ```
2.  Compile the agent:
    ```bash
    gcc main.c -o telemetry
    ```
3.  Run the executable:
    ```bash
    ./telemetry
    ```

## 📸 Usage Example
```text
Enter Device Name: Server-01
Reading hardware sensors...
 -> DETECTED: CPU: 45% | TEMP: 58.2 C
[SYNC] Sending packet to cloud... DONE.
