/* Convert string literal consant to corrsponding integer */

#include <stdio.h>

int atoi(char *s){

	int i, n;

	n = 0;
	for(i = 0;s[i]>= '0' && s[i]<= '9' && s[i] != '\0';++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

void main(int argc,char* argv[]){
	
	char *v	= argv[1];
	
	int lim;
	for(lim=0;v[lim] != '\0';++lim);
	
	int tmp = atoi(v);

	printf("%d",tmp);

}
	
