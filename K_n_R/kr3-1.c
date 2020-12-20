#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n); /* Original K&R function */
int binsearch2(int x,int v[], int n); /* New implemented function */

#define MAX_ELEMENT 20000
int binsearch(int x, int v[], int n){
	int low,high,mid;
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;

	while(low < high){
		if( x < v[mid] )
			high = high - 1;
		else if( x > v[mid])
			low  = low +1;
		else return mid;
	}
}


main(){

	int testdata[MAX_ELEMENT];
	int index;	/* index of found element in test data */

	int n = 66;	/* Element to search for */

	int i;		/* For loop index */

	clock_t time_taken;

/* Initialize test data */

	for( i = 0; i < MAX_ELEMENT; ++i)
		testdata[i] = i;

/* Output approximation of time taken for 100,000 iterations of binsearch() */
	
	for( i=0, time_taken = clock(); i < 100000; ++i) {
		index = binsearch(n,testdata,MAX_ELEMENT);
	}
	
	time_taken = clock() - time_taken;

	if( index < 0 )
		printf("Index not found \n");
	else
		printf("Index found at positon : %d\n",index);

	printf("binsearch() took %lu clocks (%lu seconds) \n",
			(unsigned long) time_taken,
			(unsigned long) time_taken / CLOCKS_PER_SEC);
}


	
	

