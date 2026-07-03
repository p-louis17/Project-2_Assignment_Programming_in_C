#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[30];
    int type;
    union {
        float temperature;
        int pressure;
        float voltage;
    }reading;
}Device;

void temperature_monitor(Device* device){
    float tempReading = device->reading.temperature;
    printf("Temperature value: %.2f\n", tempReading);

    if(tempReading > 80){
        printf("Danger, shut down everything\n\n");
        printf("\n");
    }else if(tempReading >= 50 && tempReading <= 80){
        printf("Warning, slow things down.\n\n");
        printf("\n");
    }else{
        printf("Everything is normal\n\n");
        printf("\n");
    }


}

void pressure_monitor(Device* device){
    int tempPressure = device->reading.pressure;
    printf("Pressure value: %d\n", tempPressure);

    if(tempPressure > 80){
        printf("Danger, shut down everything\n\n");
        printf("\n");
    }else if(tempPressure >= 50 && tempPressure <= 80){
        printf("Warning, slow things down.\n\n");
        printf("\n");
    }else{
        printf("Everything is normal\n\n");
        printf("\n");
    }


}

void battery_monitor(Device* device){
    float tempVoltage = device->reading.voltage;
    printf("Voltage value: %.2f\n", tempVoltage);

    if(tempVoltage > 80){
        printf("Danger, shut down everything\n\n");
        printf("\n");
    }else if(tempVoltage >= 50 && tempVoltage <= 80){
        printf("Warning, slow things down.\n\n");
        printf("\n");
    }else{
        printf("Everything is normal\n\n");
        printf("\n");
    }


}


void process_device(Device* device, void (*callback)(Device*)){
    callback(device);
}

void free_memory(Device* device){
    free(device);
}



int main(){
    int numDevices = 10;

    Device *device = malloc(numDevices*sizeof(Device));

    for(int i = 0; i<numDevices; i++){
        if(i%3 == 0){
            strcpy(device[i].name, "Temperature Sensor");
            device[i].type = 0;
            float num = (float)(rand() % 100);
            device[i].reading.temperature = num;
        }else if(i%3 == 1){
            strcpy(device[i].name, "Pressure Sensor");
            device[i].type = 1;
            int num = rand() % 100;
            device[i].reading.pressure = num;
        }else if(i%3 == 2){
            strcpy(device[i].name, "Battery");
            device[i].type = 2;
            float num = (float)(rand() % 100);
            device[i].reading.voltage = num;
        }
    }

    for(int i = 0; i<numDevices; i++){
        if(device[i].type == 0){
            process_device(&device[i], temperature_monitor);
        }else if(device[i].type == 1){
            process_device(&device[i], pressure_monitor);
        }else{
            process_device(&device[i], battery_monitor);
        }
    }

    free_memory(device);
    return 0;
}
