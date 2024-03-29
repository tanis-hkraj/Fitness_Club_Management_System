#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ID_LENGTH 10

int main() {
    char filename[] = "customerDetails.txt";
    char id[MAX_ID_LENGTH];
    char line[MAX_LINE_LENGTH];
    FILE *fp;

    // Get the customer ID from the user
    printf("Enter the customer ID: ");
    scanf("%s", id);

    // Open the text file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Search for the record with the matching customer ID
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        if (strstr(line, id) != NULL) {
            printf("%s", line);
            fclose(fp);
            return 0;
        }
    }

    // If no matching record was found, print an error message
    printf("Customer not found\n");

    // Close the file and exit the program
    fclose(fp);
    return 0;
}

