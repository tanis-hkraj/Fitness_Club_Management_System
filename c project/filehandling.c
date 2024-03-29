#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
	FILE *ptr=NULL;
    ptr=fopen("customerDetails.txt","a");
	char name[100];
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
	fprintf(ptr,"Pakage: %s\n",pakage);
	
	fprintf(ptr,"\n");
	
	
	printf("Congratulations, Welcome to Our Fitness Family\nYour CustomerID is: %s%s%s\n",nid,pid,gid);
	
	fclose(ptr);
	return 0;
}

