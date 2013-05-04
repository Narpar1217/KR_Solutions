/*
K&R Exerciese 4-1
Author: Adam Beagle

Write the function strrindex(s, t), which returns the position 
of the rightmost occurrence of t in s, or -1 if there is none.
*/

#include <stdio.h>

int strrindex(char[], char[]);
void test_strrindex(char[], char[]);

int main()
{
	test_strrindex("Hi Bart I am weaving on a loom", "a");
	test_strrindex("Hi Bart I am weaving on a loom", "Hi");
	test_strrindex("Test data test data data", "data");
	test_strrindex("ccccc", "c");
	test_strrindex("ccccc", "C");
	test_strrindex("Flenin", "not");
	test_strrindex("First sentence. Second sentence.", ".");
	test_strrindex("eenie meenie something moe", "eenie");

	return 0;
}

/* strrindex:  
	Returns index of rightmost t in s, or -1 if t does not occur in s.
*/ 
int strrindex(char s[], char t[]) 
{ 
	int i, j, k, ret; 
	
	ret = -1;
	
	for (i = 0; s[i] != '\0'; i++)  { 
		for (j=i, k=0;  t[k] != '\0' && s[j] == t[k]; j++,  k++) 
			;
			
		if (k > 0 && t[k] ==  '\0') 
			ret = i; 
	}

	return ret; 
}

/* teststrrindex:
	Passes args to strrindex and prints formatted results.
*/
void test_strrindex(char s[], char t[])
{
	printf("s: %s\nt: %s\ni: %d\n\n", s, t, strrindex(s, t));
	
	return;
}
