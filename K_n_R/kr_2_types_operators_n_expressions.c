
// escape the octal number by the form of " \0xx "
#define VTAB	'\013'
#define BELL	'\007'
// escape the hexadecimal number by the form of " \xhh "
#define VTABh	'\xb'
#define BELLh	'\x7'
/*
The complete set of escape sequences is :
	\a	:	alert(bell) character
	\b	:	backspace
	\f	:	formfeed
	\n	:	newline	
	\r	:	carriage return
	\t	:	horizontal tab
	\v	:	vertical tab
	\\	:	backslash
	\?	:	question mark
	\'	:	single quote
	\"	:	double quote

	\0xx	:	octal number
	\x00	:	hexadecimal number
*/

// The implementation of standard library function strlen(s) ( simple version) :

	int strlen(char	s[])
	{
		int i = 0;

		while (s[i] != '\0') // The internal representation of a string is a null character '\0' at the end.
			++i;

		return i;
	}

// The difference between 'x' and "x"
//	'x' is to produce the numeric number of the letter x in the machine's characeter set .
//	"x" is an arrary of characters that contains one character x and a null character '\0' at the end.

// enumeration constant : 
// 		Enumeration constant is a list of constant integer values :
		// 	With no specific value in Enumeration , It will continue it's progression in intger. 
		// 	e.g:
				enum week
					{
						Mon,
						Tue,
						Wed,
						Thu,
						Fri
					};
		//	The value of such enumeration will be 0 , 1 , 2 , 3 , 4 , 5.





//Here is the another example of Enumeration with specified constant :

		enum escapes 
			{ 		
				Bell = '\a' , 
				BACKSPACE = '\b' ,
				TAB = '\t' , 
				NEWLINE = '\n' , 
				VTAB = '\v' , 
				RETURN = '\r' 
			};
		

		
//The modulus operator % , will produce the remainder of the expression :
//	x % y  
//
	//Binary     operators : + - * / % 
	//Relational operators : > < >= <= == !=
	//Logical    operators : && || 

//Exercise 2-2 : Write a loop equivalent to the for loop below without using && or || 
//
//	for (i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//		s[i] = c;
//
		
		int lim;
		int s[lim];
		int i = 0;
		int c = 0;

		bool condition()
		{
			if(i < lim-1)
			{
				c=getchar()
				if(c != '\n')
				{
					if(c != EOF)
						return true;
				}	
			}

		}

		while (condition()){
				s[i] = c;
				++i;
			}


// Type Conversion (stopped) :
// 	
// 		
 
 		int cha_conv_int(char c[])
		{
			for(int i=0; c[i]>='0' && c[i]<= '9' || c[i] >= 'A' && c[i] <= 'z'; ++i)
			{
				if(c[i]>='0' && c[i] <='9')
					c[i] = c[i] - '0'
				else if(c[i]>='A' && c[i]<='Z')
					c[i] = c[i] - 'A'
				else if(c[i]>='a' && c[i]<='z')
					c[i] = c[i] - 'a'
				else 
					return -1;
			}
		}
		

		int lower_case_conv(char c)
		{
			if(c>='A' && C<='Z')
				return c + 'a' - 'A';
			else
				return c;
		}
// Increment and Decrement Operators :
// 	
//
//

