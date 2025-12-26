#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ==========================================
// CONFIGURATION: PASTE YOUR KEYS INSIDE THE QUOTES
// ==========================================
#define SUPABASE_URL "https://mkkjceedksepsesqbxwm.supabase.co/rest/v1/sensor_data"
#define SUPABASE_KEY "sb_publishable_y9bdunukvNH2SrRfogIYCQ_G5XCUC3V"

// ==========================================
// SYSTEM LOGIC
// ==========================================

// Struct to mimic real hardware data
struct SensorReading
{
    char deviceName[50];
    int cpuUsage;
    float temperature;
};

// Function to send data via HTTP (using system curl)
void send_telemetry(struct SensorReading data)
{
    char json_payload[512]; // Increased size just in case
    char terminal_command[2048];

    // 1. Format data into JSON string
    // FIX FOR WINDOWS: We use \\\" to escape quotes so CMD.exe doesn't break them
    sprintf(json_payload,
            "{\\\"device_name\\\": \\\"%s\\\", \\\"cpu_usage\\\": %d, \\\"temperature\\\": %.2f}",
            data.deviceName, data.cpuUsage, data.temperature);

    // 2. Build the curl command
    sprintf(terminal_command,
            "curl -s -X POST \"%s\" "
            "-H \"apikey: %s\" "
            "-H \"Authorization: Bearer %s\" "
            "-H \"Content-Type: application/json\" "
            "-d \"%s\"",
            SUPABASE_URL, SUPABASE_KEY, SUPABASE_KEY, json_payload);

    // 3. Execute
    printf("\n[SYNC] Sending packet to cloud... ");
    int result = system(terminal_command);

    if (result == 0)
    {
        printf("DONE. (Check Supabase)\n");
    }
    else
    {
        printf("FAILED. (Check internet or keys)\n");
    }
}

int main()
{
    struct SensorReading currentSensor;

    // Random seed for simulation
    srand(time(0));

    printf("========================================\n");
    printf("   C-BASED IOT TELEMETRY AGENT v1.0    \n");
    printf("========================================\n");

    // Interactive Loop
    while (1)
    {
        printf("\nEnter Device Name (or 'exit' to quit): ");
        scanf("%s", currentSensor.deviceName);

        // Break loop if user types exit
        if (currentSensor.deviceName[0] == 'e' && currentSensor.deviceName[1] == 'x')
            break;

        // Simulate reading hardware sensors
        printf("Reading hardware sensors...\n");
        currentSensor.cpuUsage = (rand() % 100);
        currentSensor.temperature = 40.0 + ((float)(rand() % 200) / 10.0);

        printf(" -> DETECTED: CPU: %d%% | TEMP: %.1f C\n",
               currentSensor.cpuUsage, currentSensor.temperature);

        // Upload
        send_telemetry(currentSensor);
        printf("----------------------------------------\n");
    }

    return 0;
}