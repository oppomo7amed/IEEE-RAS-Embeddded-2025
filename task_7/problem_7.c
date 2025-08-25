#include <stdio.h>
#include <string.h>

// Step 1: Define union to store different sensor values
typedef union {
    int   temperature;   // For temperature sensors
    float pressure;      // For pressure sensors
    char  status;        // For status/displacement sensors
} SensorValue;

// Step 2: Define struct to store sensor metadata and data
typedef struct {
    int sensorID;            // Unique ID
    char sensorType[20];     // e.g., "Temperature", "Pressure", "Displacement"
    SensorValue data;        // Union of possible values
} SensorData;

// Step 3: Function to print sensor info
void printSensorData(SensorData s) {
    printf("Sensor ID: %d\n", s.sensorID);
    printf("Sensor Type: %s\n", s.sensorType);

    if (strcmp(s.sensorType, "Temperature") == 0) {
        printf("Value: %d °C\n", s.data.temperature);
    } 
    else if (strcmp(s.sensorType, "Pressure") == 0) {
        printf("Value: %.2f Pa\n", s.data.pressure);
    } 
    else if (strcmp(s.sensorType, "Displacement") == 0) {
        printf("Value: %c\n", s.data.status);
    } 
    else {
        printf("Unknown sensor type!\n");
    }
    printf("\n");
}

// Main function to demonstrate
int main() {
    // Example sensors
    SensorData s1, s2, s3;

    // Temperature sensor
    s1.sensorID = 101;
    strcpy(s1.sensorType, "Temperature");
    s1.data.temperature = 25;

    // Pressure sensor
    s2.sensorID = 202;
    strcpy(s2.sensorType, "Pressure");
    s2.data.pressure = 101325.50;

    // Displacement/status sensor
    s3.sensorID = 303;
    strcpy(s3.sensorType, "Displacement");
    s3.data.status = 'A';   // e.g., 'A' for Active, 'I' for Inactive

    // Print them
    printSensorData(s1);
    printSensorData(s2);
    printSensorData(s3);

    return 0;
}
