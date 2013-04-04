/* Exercise 2-5: Write the function any(s1,s2), which returns the first location in a string s1 
where any character from the string s2 occurs, or -1 if  s1 contains no characters from  s2. 
(The standard library function strpbrk does the same job but returns a pointer to the location.) 
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

int any(char s1[], char s2[]);
void test_any(char s1[], char s2[]);

main()
{
	char test[] = "Hi Bart, I am weaving on a loom.";
	
	//test cases
	test_any(test, "");
	test_any(test, "H");
	test_any(test, ".");
	test_any(test, "h");
	test_any(test, "Brt");
	test_any(test, "xyz");
	test_any(test, "xy z");
}

/* any: Returns index of first occurence of any character from s2 in s1,
     or -1 if no characters occur. */
int any(char s1[], char s2[])
{
	int i, j, ret;
	
	ret = -1;
	
	for (i = 0; i < strlen(s2); ++i) {
		for (j = 0; j < strlen(s1); ++j) {
			if (s1[j] == s2[i]  && (j < ret || ret < 0))
				ret = j;
		}
	}
	
	return ret;
}

/* Pass s1 and s2 to any and print formatted results.*/
void test_any(char s1[], char s2[])
{
	printf("\ns1:\t%s\ns2:\t%s\nResult:\t%d\n", s1, s2, any(s1, s2));
}
