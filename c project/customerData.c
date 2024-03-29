#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;                   // pointer to file
    char input[100], line[1000];// user input and line buffer
    int pos = 0;                // position of text in file

    printf("Enter the text to search: ");
    fgets(input, sizeof(input), stdin);    // read user input
    input[strcspn(input, "\n")] = '\0';    // remove newline character

    fp = fopen("customerDetails.txt", "r");           // open file for reading
    if (fp == NULL) {                      // check if file was opened successfully
        printf("Error opening file!");
        return 1;
    }

    fseek(fp, 0, SEEK_SET);                 // move file pointer to beginning of file
    while (fgets(line, sizeof(line), fp) != NULL) {  // read each line of file
        if (strcmp(line, input) == 0) {     // check if line matches user input
            pos = ftell(fp) - strlen(line); // calculate position of matching text
            break;                          // exit loop if match found
        }
    }

    if (pos == 0) {                         // check if text was found in file
        printf("Text not found in file!");
    } else {
        fseek(fp, pos, SEEK_SET);           // move file pointer to position of matching text
        printf("Cursor moved to position %d", pos);
    }
    char c;
    while(1){
    	c=fgetc(fp);
    	printf("%c",c);
    	if (c=='  '){
    		break;
		}
	}

    fclose(fp);                             // close file
    return 0;
}

