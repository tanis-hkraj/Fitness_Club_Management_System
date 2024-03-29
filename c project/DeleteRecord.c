#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    FILE *fp, *temp;
    char customer_id[10], buffer[MAX_SIZE];
    int found = 0;

    // open the original file
    fp = fopen("customerDetails.txt", "r");

    // create a temporary file
    temp = fopen("temp.txt", "w");

    // get the customer id from the user
    printf("Enter the customer id to delete: ");
    scanf("%s", customer_id);

    // read records from the original file and write them to the temporary file
    while (fgets(buffer, MAX_SIZE, fp) != NULL) {
        // check if the record contains the desired customer id
        if (strstr(buffer, customer_id) != NULL) {
            found = 1;
            continue; // skip the record
        }
        fputs(buffer, temp); // write the record to the temporary file
    }

    // close the files
    fclose(fp);
    fclose(temp);

    // delete the original file
    remove("customerDetails.txt");

    // rename the temporary file
    rename("temp.txt", "customerDetails.txt");

    if (found == 1) {
        printf("Record deleted successfully.");
    } else {
        printf("Record not found.");
    }

    return 0;
}


