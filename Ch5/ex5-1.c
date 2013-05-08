/*
K&R Exercise 5-1
Author: Adam Beagle

As written, getint treats a + or - not followed by a digit as a valid 
representation of zero. Fix it to push such a character back on the input. 
 */

#include <stdio.h>
#include <ctype.h> //For isdigit, isspace

int getch(void);     //See getch.c
int getint(int *pn); 
void ungetch(int);   //See getch.c

/* Runs getint once */
int main()
{
	int n = 0;
	
	printf("ret: %d\nn: %d\n\n", getint(&n), n);

	return 0;
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
