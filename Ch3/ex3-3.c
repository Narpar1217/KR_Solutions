/* 
K&R Exercise 3-3
Author: Adam Beagle

Write a function expand(s1,s2) that expands shorthand notations like a-z in 
the string s1 into the equivalent complete list abc...xyz in s2. 
Allow for letters of either case and digits, and be prepared to 
handle cases like a-b-c and a-z0-9 and -a-z. 
Arrange that a leading or trailing - is taken literally.  
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define UPCASE_ST 	65
#define UPCASE_END	90
#define LOCASE_ST	97
#define LOCASE_END	122
#define DIGIT_ST	48
#define DIGIT_END	57
#define MAXLINE 	1000

bool check_valid_range(char s[], int i);
bool expand(char s1[], char s2[], int maxLen);
int expand_one_set(char s[], int startIndex, char begin, char end, bool multi);

/* Tests expand and prints results. */
int main()
{
	char s1[] = "M-O-Test -a-z- data A-f please 2-2F-J ignore G-E yup 0-7";
	char s2[MAXLINE];
	
	expand(s1, s2, MAXLINE);
	printf("\nORIGINAL:\n%s\n\nEXPANDED:\n%s\n", s1, s2);
	
	return 0;
}


/* check_valid_range: 
    Checks if 3 characters of s starting at index i are a valid range of type 'x-y' or '#-#'
    Checks are case sensitive, i.e. a-F is not a valid range. */
bool check_valid_range(char s[], int i)
{
	bool con1, con2, con3;


	con1 = ((s[i] >= LOCASE_ST) && (s[i + 2] >= s[i]) && (s[i + 2] <= LOCASE_END));
	con2 = (s[i] >= UPCASE_ST && (s[i + 2] >= s[i]) && (s[i + 2] <= UPCASE_END));
	con3 = (s[i] >= DIGIT_ST && (s[i + 2] >= s[i]) && (s[i + 2] <= DIGIT_END));
	
	return s[i + 1] == '-' && (con1 | con2 | con3);
}


/* expand_one_set: 
    Writes the expanded set 'begin-end' to s, starting at startIndex. 
	  Ex: With begin = 'a' and end = 'd', 'abcd' would be written to s.
    Note that this function is unaware of whether the range is valid,
    so passing non-alphanumeric beginning or end will result in unexpected behavior.*/
int expand_one_set(char s[], int startIndex, char begin, char end, bool multi)
{
	int c, i;
	
	i = startIndex;
	if (multi) ++begin;
	
	for (c = begin; c <= end; ++c, ++i)
		s[i] = c;
		
	return i;
}


/* expand: 
    Writes s1 with expanded character ranges to s2. 
	Returns false if s2 did not have sufficient space, and true otherwise.
	Acceped range types are A-Z, a-z, and 0-9. A-B-C, 2-5-7-9, etc. are also accepted. 
	Leading/trailing dashes are printed literally. 
	Spaces inside a range will result in the range not being printed correctly. */
bool expand(char s1[], char s2[], int maxLen)
{
	int i, j;
	bool partOfRange, success;
	
	partOfRange = false;
	success = true;
	j = 0;
	
	for (i = 0; i < strlen(s1); ++i) {
	
		if (i < strlen(s1) - 2) {
			// case: character range
			if (check_valid_range(s1, i)) {
				j = expand_one_set(s2, j, s1[i], s1[i + 2], partOfRange);
				partOfRange = true;
				i += 1; 		// remember: i incremented by 1 again at end of loop
				continue;
			}
			//case: not part of a-b-c
			else if (partOfRange && !check_valid_range(s1, i)) {
				partOfRange = false;
				continue;
			}
		}
		
		// case: literal character
		//Without this test, a line ending with a range will have its last character printed twice
		if (!partOfRange) {
		
			//Add character to s2, or break and return if out of space
			if (j < maxLen - 1)
				s2[j++] = s1[i];
			else {
				success = false;
				break;
			}
		}
	}
	
	s2[j] = '\0';
	
	return success;
}






