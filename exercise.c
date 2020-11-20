#include <stdio.h>
#include <math.h>


#define PI 3.1415926

float coin_volume(float r,float h ){


	/* Formula for Cubic coin : Pi * r^2 * h */
	float temp  = pow(r,2);
	float result = PI*h*temp;
	return result;
	
}

int trans_to_ascii(char c){
	
	int i_trans;
	i_trans = c;
	return i_trans;
}

char reverse_num(char *a){
	/* implementing */	
	int lim;
	for(lim=0;a[lim]!='\0';++lim);
	
	char tmp[lim];
	int i;
	for(i =0;(tmp[lim-1-i] = a[i] ) && i < lim ; ++i);
	
	for(i =0;i <lim ; ++i)
		putchar(tmp[i]);

}
void main(int argc,char* argv[]){

	char *a = argv[1];
	
	reverse_num(a);

	
}
