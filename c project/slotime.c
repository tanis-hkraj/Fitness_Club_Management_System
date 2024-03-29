#include <stdio.h>

int main() {
    // Define the time slots
    const char* slots[] = {
        "6:00am - 7:00am",
        "7:00am - 8:00am",
        "8:00am - 9:00am",
        "9:00am - 10:00am",
        "10:00am - 11:00am",
        "11:00am - 12:00pm",
        "12:00pm - 1:00pm",
        "1:00pm - 2:00pm",
        "2:00pm - 3:00pm",
        "3:00pm - 4:00pm",
        "4:00pm - 5:00pm",
        "5:00pm - 6:00pm",
        "6:00pm - 7:00pm",
        "7:00pm - 8:00pm",
        "8:00pm - 9:00pm",
        "9:00pm - 10:00pm",
    };
    
    // Open the file for writing
    FILE* fp = fopen("slot_timings.txt", "w");
    
    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    // Write the time slots to the file
    for (int i = 0; i < sizeof(slots) / sizeof(slots[0]); i++) {
        fprintf(fp, "Slot %d: %s\n", i+1, slots[i]);
    }
    
    // Close the file
    fclose(fp);
    
    return 0;
}

