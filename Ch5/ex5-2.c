/*
K&R Exercise 5-2
Author: Adam Beagle

Write getfloat, the floating-point analog of getint. What 
type does getfloat return as its function value?
 */

#include <stdio.h>
#include <ctype.h>  //isdigit, isspace
#include <math.h>   //pow
#include <stdlib.h> //abs
#include "getch.h"  //getch, ungetch, clearch

int getfloat(float *);
int getint(int *);


/* Tests getfloat. */
int main()
{
	float n = 0.0;
	int ret;
	
	printf("Send EOF to quit\n");
	
	do {
		printf("\n-------------\n");
		printf("Enter float: ");
		ret = getfloat(&n);
		printf("\nn: %f\nret: %d\n", n, ret);
		
		//If buffer not cleared, pushed-back input
		//will cause infinite loop.
		clearch();
		
	} while (ret != EOF);
	
	
	return 0;
}


/* getfloat:
	Gets float from input and places it into *pn.
	Returns 0 if input not a valid float, otherwise last character examined.

	The following are legal input:
		x.x, (+|-)x.x, as is any input legal in getint.
	
	*pn is only altered if input valid.
*/
int getfloat(float *pn)
{
	int c, dec, sign, i;
	float f;

	//Skip white space
	while (isspace(c = getch()))
		;
		
	sign = (c == '-') ? -1 : 1;
	ungetch(c);
	
	//Get integer portion from getint
	if (!(c = getint(&i)))
		return 0;
		
	f = abs(i); //Ignore sign from getint
		
	//Check for decimal portion
	if (c == '.') {
		c = getch(); //Get decimal pushed back in getint
		
		//Verify next character is digit; otherwise invalid
		if (!isdigit(c = getch())) {
			ungetch(c);
			return 0;
		}
		ungetch(c);
		
		//Accumulate decimal portion
		for (dec = 0; isdigit(c = getch()); dec++)
			f = 10.0 * f + (c - '0');
		
		f /= pow(10.0, dec);
	}
	
	*pn = f * sign; //*pn only altered once input verified to be valid
	
	if (c != EOF)
		ungetch(c);
	
	return c;
}


/* getint:
	Gets next integer from input into *pn.
	Returns 0 if input not a valid integer,
	otherwise last character encountered 
	(i.e. character that broke parsing of integer; 
	for example \n, EOF, any non-digit character). 

*/
int getint(int *pn)
{
	int c, sign;
	
	//Skip white space
	while (isspace(c = getch()))
		;
		
	//Return 0 if c not valid first character
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	
	//Account for sign character
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		char posNeg = c;
		
		c = getch();
		
		if (!isdigit(c)) {
			ungetch(c);
			ungetch(posNeg);
			
			return 0; //Invalid input: + or - not followed by digit
		}
	}
	
	//Accumulate integer input into *pn
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
		
	*pn *= sign;
	
	if (c != EOF)
		ungetch(c);
		
	return c;
}
