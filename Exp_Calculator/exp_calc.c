#include <stdio.h>
#include <math.h>
/*
 *
 * Given an algebraic expression , output the evaluation.
 *
 * Orders of operations(According to the Openstax's opensource textbook COLLEGE ALGEBRA):
 * 	Operations in mathematical expressions must be evaluated in a systematic order,
 * 	which can be simplified using the acronym PEMDAS.
 * 		P(parentheses)
 * 		E(xponents)
 * 		M(ultiplication) and D(divition)
 * 		A(ddition) and S(ubctraction)
 * 
 */
int gslen(char *a){ /* Get the length of a character string */
	int len = 0;

	int i;
	for(i = 0;a[i] != '\0'; ++i);

	return i;
}
int ckexp_regul(char *a,int l){ /* Check whether the algebrac expression regular or not */
/* 
 * 	The algebrac expression actually is a series of single characetr sequences.
 * 	Hence they must be in the range of [ '('40d ] - [ '9'57d ] plus [ '^'94d ]
 * 	but except [ ','44d ]
 *
*/
	int i;
	for(i = 0; a[i] >= '(' && a[i] <= '9' && a[i] != ',' || a[i] == '^' && a[i] != '\0' ; ++i);
	if(i == l )
		return 1;
	else 
		printf("Not an regular algebraic expression.\n");
		return 0;
}

}

main(int argc, char* argv[]){

/* Program argument checking stage */

	if(argc != 2 ){
		printf("Usage : calc [algebrac_expresson] \n ");
		return -1;
	}
	char* c_exp = argv[1];

	int exp_length = gslen(c_exp);

	
	if(!(exp_length < 200 && ckexp_regul(c_exp,exp_length)))
		return -1;

/* Program argument analyse stage */

	int i;
	for(i = 0; c_exp[i] != '\0'; ++i){
		
			
	}	
	
}
	
	

