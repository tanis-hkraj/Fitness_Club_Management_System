#include <stdio.h>
int main(){
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
