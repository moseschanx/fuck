#include <stdio.h>

int main(){

	char *filename = "bus_route.txt";

	FILE *fp = fopen(filename,"r");
	

	if(fp == NULL){
		printf("Could not open file %s",filename);
		return 1;
	}
	

	char c = fgetc(fp);
	
		




	if(fclose(fp) == 0) 
		puts("File closed successfully");
	else 
		puts("Unknown error!");
	

}
	
