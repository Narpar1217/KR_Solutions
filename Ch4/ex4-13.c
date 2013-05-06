/*
K&R Exercise 4-13
Author: Adam Beagle

Write a recursive version of the function reverse(s), which reverses the 
string s in place. 
*/

#include <stdio.h>
#include <string.h>

void str_reverse_ip(char[]);
void test_reverse(char[]);

int main()
{
	test_reverse("");
	test_reverse("c");
	test_reverse("hi");
	test_reverse("cat");
	test_reverse("test");
	test_reverse("Warla");
	
	return 0;
}

/* str_reverse_ip:
	Reverses string s in place.
	This version uses recursion.
	Note pointers not used because they have not been introduced at this point in the book.
*/
void str_reverse_ip(char s[])
{
	static int i = 0;
	static int j = -1;
	char temp;
	
	if (j < 0)
		j = strlen(s) - 1; //ignore terminator
	
	if (j - i > 0) {
		temp = s[i];
		s[i++] = s[j];
		s[j--] = temp;
	
		str_reverse_ip(s);
	}
	else {
		i = 0;
		j = -1;
	}
	
}

void test_reverse(char s[])
{
	printf("s:   %s\n", s);
	str_reverse_ip(s);
	printf("rev: %s\n\n", s);
}
