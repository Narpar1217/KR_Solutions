/*
K&R Exercise 4-12
Author: Adam Beagle

Adapt the ideas of printd to write a recursive version of itoa; 
that is, convert an integer into a string by calling a recursive routine.
 */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void itoa(int, char[], bool);
void test_itoa(int, char[]);

int main()
{
	char s[12]; //length is longest signed int, '-', and '\0'
	
	//test data
	test_itoa(0, s);
	test_itoa(1, s);
	test_itoa(-1, s);
	test_itoa(123, s);
	test_itoa(-123, s);
	test_itoa(INT_MAX, s);
	test_itoa(INT_MIN, s);
	
	return 0;
}


/* itoa:
	Places the string representation of n into s.
	This version uses recursion.
	String s assumed to be long enough.
	User should always pass recursFlag as false.
	Note pointers not used because they have not been introduced at this point in the book.
*/
void itoa(int n, char s[], bool recursFlag)
{
	static int i = 0;

	if (n < 0)
		s[i++] = '-';
	
	if (n / 10) 
		itoa(abs(n / 10), s, true);

	s[i++] = abs(n % 10) + '0';
	
	//If recursion fallen back to final digit
	if (!recursFlag) {
		s[i] = '\0';
		i = 0;
	}
}


void test_itoa(int n, char s[])
{
	itoa(n, s, false);
	printf("n: %d\ns: %s\n\n", n, s);
}
