/* 
Exercise 2-4
Write an alternative version of squeeze(s1,s2) that deletes each 
character in s1 that matches any character in the string s2.  

Author: Adam Beagle
*/

#include <stdio.h>
#include <string.h>

void squeeze_alt(char s[], char s2[]);
void squeeze(char s[], int c);
void test_squeeze(char s[], char s2[]);

int main()
{
	printf("\nBegin real test:\n---------------\n");
	test_squeeze("", "ab c");
	test_squeeze("Hi Bart I'm weaving on a loom.", "");
	test_squeeze("Hi Bart.", "hia");
	test_squeeze("-Hi I am Weave.-", "-");
	test_squeeze("Hi Bart I'm weaving on a loom.", "Hi BartImwevngol.'");
	
	//Weird compiler issue: 
	//  If passing the (exact) same s multiple times, the string is not passed as expected. 
	//  Instead, the squeezed version from the previous call will be passed.
	printf("\nBegin weird case test:\n(Passing same original data each time)\n---------------\n");
	test_squeeze("test sentence please ignore", "");
	test_squeeze("test sentence please ignore", "ts");
	test_squeeze("test sentence please ignore", "i n");
	test_squeeze("test sentence please ignore", "test");
	
	return 0;
}


/* squeeze_alt:  Delete all occurences of characters in s2 from s. 
	Note function is case-sensitive.*/ 
void squeeze_alt(char s[], char s2[]) 
{ 
	int i;
	
	for (i = 0; i < strlen(s2); ++i)
		squeeze(s, s2[i]);
}

/* squeeze:  Delete all c from s */ 
void squeeze(char s[], int c) 
{ 
	int i, j; 

	for (i = j = 0; s[i] != '\0'; i++) 
		if (s[i] != c) 
			s[j++] = s[i]; 
			
	s[j] = '\0'; 
}

/* test_squeeze: Sends passed values to squeeze and prints result */
void test_squeeze(char s[], char s2[])
{
	printf("\nOriginal:\t%s\nDelete:\t\t%s\n", s, s2);
	
	squeeze_alt(s, s2);
	
	printf("Result:\t\t%s\n", s);
}

