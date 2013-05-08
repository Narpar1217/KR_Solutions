/*
K&R Exercise 5-3
Author: Adam Beagle

Write a pointer version of the function  strcat that we showed in  Chapter 2: 
strcat(s,t) copies the string t to the end of s. 
 */

#include <stdio.h>

#define LEN 25

void strcat(char *, char *);
void strcopy(char *, char *);
void test_strcat(char *, char *);

/* Runs tests on strcat */
int main()
{
	char s[2*LEN] = "";
	char t[LEN] = "S is empty";

	test_strcat(s, t);
	
	strcopy("T is empty", s);
	strcopy("", t);
	test_strcat(s, t);
	
	strcopy("Hi Bart!", s);
	strcopy(" I am weaving on a loom.", t);
	test_strcat(s, t);
	
	strcopy("", s);
	strcopy("S is empty again", t);
	test_strcat(s, t);
	
	strcopy("You'll have to speak up, I", s);
	strcopy("'m wearing a towel.", t);
	test_strcat(s, t);
	
	strcopy("H", s);
	strcopy("I", t);
	test_strcat(s, t);

	
	return 0;
}


/* strcat:
	Concatenates t to the end of s.
	Assumes s is large enough.
*/
void strcat(char *s, char *t)
{
	//Set s to point to terminator of s.
	if (*s)
		while (*(++s))
			;
		
	//Concatenate t to s
	while (*t)
		*(s++) = *(t++);
		
	*s = '\0';
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


void test_strcat(char *s, char *t)
{
	printf("s: %s\nt: %s\n", s, t);
	strcat(s, t);
	printf("r: %s\n\n", s);
}
