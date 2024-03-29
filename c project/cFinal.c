#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_LINE_LENGTH 1024
#define MAX_ID_LENGTH 10
#define MAX_SIZE 1000
int addrecord();
int deleteRecord();
int searchRecord();
int displayRecord();
int slotime();
int main()
{
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------");
	printf("                                                  **********WELCOME TO LPU FITNESS CLUB**********                                                   ");
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------");
	char a;
	printf("Enter the number of the Action You Want to Perform:\n1. Display All Records\n2.Delete Record of Customer\n3.Search Record of Customer\n4.Add Record of Customer\n5.Display Slot Timings with Batch Number\nEnter You Response As 1,2,3,4 or 5: ");
	scanf("%c",&a);
	if (a=='1'){
		printf("The Records Are Displayed Below\n\n");
		displayRecord();
	}
	else if (a=='2'){
		printf("Delete Records Option Selected...\n\n");
		deleteRecord();
	}else if(a=='3'){
		printf("Search Record Option Selected\n\n");
		searchRecord();
	}
	else if(a=='4'){
		printf("Add A New Customer to File\n\n");
		addrecord();
	}
	else if (a=='5'){
		slotime();
	}
	else{
		printf("Invalid Input");
	}
		
	return 0;
}
int addrecord(){
	FILE *ptr=NULL;
    ptr=fopen("customerDetails.txt","a");
    char h[5];
    gets(h);
	char name[50];
	printf("Enter Your Name: ");
	gets(name);	
	
	char address[100];
	printf("Enter City, State: ");
	gets(address);
	
    char Gender[7];
	printf("Enter Your Gender: ");
	gets(Gender);
	printf("Enter the pakage you are interested in:\n1. 10 Days Pakage\n2. 20 Days Pakage\n3. Monthly Pakage\n4. Anual Pakage.\nEnter your response as whole: ");
	char pakage[20];
    gets(pakage);
	int age;
	printf("Enter Your Age in Years: ");
	scanf("%d",&age);
	float height;
	printf("Enter Your Height in Meters: ");
	scanf("%f",&height);
	float weight;
	printf("Enter Your Weight in Kgs: ");
	scanf("%f",&weight);
	int day, month, year;
    printf("Enter date of Joining in dd/mm/yyyy format: ");
    scanf("%d/%d/%d", &day, &month, &year);
    
	long long phone;
	printf("Enter Your Phone Number: ");
	scanf("%lld",&phone);

	
	char nid[2];
	strncpy(nid,name+0,2);
	nid[2]='\0';
	char gid[2];
	strncpy(gid,Gender+0,2);
	gid[2]='\0';
	char p[10];
	snprintf(p,10,"%lld",phone);
	char pid[2];
	strncpy(pid,p+8,2);
	pid[2]='\0';
	float bmi=weight/(height*height);
    fprintf(ptr,"CustomerID: %s%s%s\t",nid,pid,gid);
	fprintf(ptr,"Name of Customer: %s\t",name);
	fprintf(ptr,"Date of Joining: %02d/%02d/%04d\t", day, month, year);
	fprintf(ptr,"Phone Number: %lld\t",phone);
	fprintf(ptr,"Address: %s\t",address);
	fprintf(ptr,"Gender: %s\t",Gender);
	fprintf(ptr,"Age: %d\t",age);
	fprintf(ptr,"Height: %.2f m\t",height);
	fprintf(ptr,"Weight: %.2f kgs\t",weight);
	fprintf(ptr,"BMI: %.2f\t",bmi);
	fprintf(ptr,"Pakage: %s\t",pakage);
	
	
	
	
	printf("Congratulations, Welcome to Our Fitness Family\nYour CustomerID is: %s%s%s\n",nid,pid,gid);
	int t;
	printf("Please Select one of the below mentioned time slots:\n1. 6:00am - 7:00am\n2. 7:00am - 8:00am\n3. 8:00am - 9:00am\n4. 9:00am - 10:00am\n5. 10:00am - 11:00am\n6. 5:00pm - 6:00pm\n7. 6:00pm - 7:00pm\n8. 7:00pm - 8:00pm\n9. 8:00pm - 9:00pm\n10. 9:00pm - 10:00pm:\n Enter your Response: ");
	scanf("%d",&t);
	fprintf(ptr,"Slot Batch Number: %d\n",t);
	fprintf(ptr,"\n");
	fclose(ptr);
	return 0;
}

int deleteRecord(){
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

int searchRecord(){
	
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

int displayRecord(){
		FILE *ptr2;
	ptr2=fopen("customerDetails.txt","r");
	char c;
	printf("Customer Details:\n\n");
	while(1){
		c=fgetc(ptr2);
		printf("%c",c);
		if(c==EOF){
			break;
		}
	}
	fclose(ptr2);
	return 0;
}
int slotime(){
	printf("Slot Timings with Their Slot Batch Number Are given Below:\n1. 6:00am - 7:00am\n2. 7:00am - 8:00am\n3. 8:00am - 9:00am\n4. 9:00am - 10:00am\n5. 10:00am - 11:00am\n6. 5:00pm - 6:00pm\n7. 6:00pm - 7:00pm\n8. 7:00pm - 8:00pm\n9. 8:00pm - 9:00pm\n10. 9:00pm - 10:00pm");
	return 0;
}
