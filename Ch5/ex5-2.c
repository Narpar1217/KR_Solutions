/*
K&R Exercise 5-2
Author: Adam Beagle

Write getfloat, the floating-point analog of getint. What 
type does getfloat return as its function value?
 */

#include <stdio.h>
#include <ctype.h> //isdigit, isspace
#include <math.h> //pow

int getch(void);     //See getch.c
int getfloat(float *pn);
int getint(int *pn); 
void ungetch(int);   //See getch.c

/* Runs getfloat once */
int main()
{
	float n = 0.0;
	
	printf("Enter float: ");
	printf("\nret: %d\nn: %f\n\n", getfloat(&n), n);

	return 0;
}

/* getfloat:
	Gets next float from input and places it into *pn.
	Returns 0 if input not a valid float,
	otherwise last character encountered 
	(i.e. character that broke parsing of float; 
	for example \n, EOF, any non-digit character). 
	The following are all legal input:
	x.x, (+|-)x.x, (+|-).x, .x, as is any input legal in getint.
*/
int getfloat(float *pn)
{
	int c, dec, i = 0, sign;
	
	//Skip white space
	while (isspace(c = getch()))
		;
	
	//Check if negative.
	//Note this must be done here and not in getint,
	//as case "-0.x" would fail.
	if (c == '-') 
		sign = -1; 
	else {
		sign = 1;
		ungetch(c);
	}
	
	//Place integer portion into i
	c = getint(&i);
	
	//Case: no integer found; could be decimal or sign then decimal.
	if (c == 0) {
		c = getch();
		
		if (c == '+'|| c == '-') {
			char posNeg = c;
			
			if ((c = getch()) != '.') {
				ungetch(c);
				ungetch(posNeg);
				return 0;
			}
		}
		else if (c != '.') {
			ungetch(c);
			return 0;
		}
	}
	else if (c == '.')
		//decimal will have been pushed back to buffer; get it.
		c = getch();

	//Case: integer found, decimal portion remaining
	if (c == '.') {
	
		//Verify next character is digit; otherwise invalid
		if (!isdigit(c = getch())) {
			ungetch(c);
			return 0;
		}
		else {
			ungetch(c);
			*pn = i; //Note *pn not modified until verified as valid
		}
	
		//If *pn negative, flip to positive to prepare for gathering decimal portion
		if (*pn < 0.0) {
			sign = -1;
			*pn = -*pn;
		}
		
		//Accumulate  post-decimal digits
		for (dec = 0; isdigit(c = getch()); dec++)
			*pn = 10.0 * *pn + (c - '0');
		
		*pn /= pow(10.0, dec);
	}
	else
		*pn = i; //Note *pn not modified until verified as valid
	
	*pn *= sign;
	
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
		
	//Return 0 if c not valid
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
