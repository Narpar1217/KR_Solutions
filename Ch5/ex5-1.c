/*
K&R Exercise 5-1
Author: Adam Beagle

As written, getint treats a + or - not followed by a digit as a valid 
representation of zero. Fix it to push such a character back on the input. 
 */

#include <stdio.h>
#include <ctype.h> //For isdigit, isspace
#include "getch.h" //getch, ungetch, clearch

int getint(int *pn); 

/* Tests getint */
int main()
{
	int ret, n = 0;
	
	printf("Send EOF to quit\n");
	
	do {
		printf("\n-------------\n");
		printf("Enter int: ");
		ret = getint(&n);
		printf("\nn: %d\nret: %d\n", n, ret);
		
		//If buffer not cleared, bad pushed-back input
		//will cause infinite loop.
		clearch();
		
	} while (ret != EOF);
	

	return 0;
}

/* getint:
	Gets next integer from input into *pn.
	Returns 0 if input not a valid integer,
	otherwise last character examined.
	*pn not altered if input invalid.
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
