/*
K&R Exercise 5-4
Author: Adam Beagle

Write the function strend(s,t), which returns 1 if the string t occurs at the 
end of the string s, and zero otherwise. 
 */

#include <stdio.h>

#define LEN 10

void strcopy(char *, char *);
int strend(char *, char *);
int strlen(char *);
void test_strend(char *, char *);

/* Runs tests on strend */
int main()
{
	char s[LEN] = "Good";
	char t[LEN] = "od";
	
	test_strend(s, t);
	
	strcopy("Hi Bart", s);
	strcopy("t", t);
	test_strend(s, t);
	
	strcopy("", s);
	strcopy("S is empty", t);
	test_strend(s, t);
	
	strcopy("T is empty", s);
	strcopy("", t);
	test_strend(s, t);
	
	strcopy("Limes", s);
	strcopy("ime", t);
	test_strend(s, t);
	
	strcopy("Limes", s);
	strcopy("imes", t);
	test_strend(s, t);
	
	strcopy("Test", s);
	strcopy("T longer", t);
	test_strend(s, t);
	
	strcopy("", s);
	strcopy("", t);
	test_strend(s, t);
	
	strcopy("Test", s);
	strcopy("Test", t);
	test_strend(s, t);
	

	return 0;
}


/* strcopy:
	Copies string src into dest.
	Assumes dest is large enough.
*/
void strcopy(char *src, char *dest)
{
	while (*src)
		*(dest++) = *(src++);
		
	*dest = '\0';
}


/* strend:
	Returns 1 if string t occurs at end of s, otherwise 0.
*/
int strend(char *s, char *t)
{
	int lenT = strlen(t) - 1;
	int lenS = strlen(s) - 1;
	
	if (lenT > lenS) 
		return 0; //Failure; S cannot contain t.
		
	s += (lenS - lenT);
	while (lenT--)
		if (*(s++) != *(t++))
			return 0; //Failure
	
	return 1; //Success
}


/* strlen:
	Returns length of string s.
	Length includes the null terminator.
*/
int strlen(char *s)
{
	int len = 1;
	
	while (*(s++))
		len++;
		
	return len;
}


void test_strend(char *s, char *t)
{
	printf("s: %s\nt: %s\nr: %d\n\n", s, t, strend(s, t));
}
