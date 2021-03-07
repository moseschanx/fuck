#include <stdio.h>
#include <math.h>
	

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
