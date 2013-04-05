/* 
Exercise 1-17 
Write a program to print all input lines that are longer than 80 characters. 

Usage: Redirect file to stdin. Example: ./this_program < file.ext

Author: Adam Beagle
*/

#include <stdio.h>

#define MAXLINE 1000 	/* maximum input line length */
#define MINPRINTLEN 80  /* minimum length required to print line */

int _getline(char s[], int lim);	// NOTE: underscore is necessary! Otherwise name conflicts with stdio function.


int main()
{
	int len;			// current line length
	char line[MAXLINE];	// line

	while ((len = _getline(line, MAXLINE)) > 0) {
		if (len > MINPRINTLEN) {
			printf("%s\n", line);
			
		}
	}
	
	return 0;
}

/* _getline: Reads as much as possible of a line into s. 
Returns length of entire line, even if it did not fit in s.
Lim is size of s.
0 is only returned if EOF is reached. 
A blank line (i.e. just '\n') will be reported as length 1. 
Note that aside from the aforementioned case, newline characters do not count toward length. */
int _getline(char s[], int lim)
{
	int c, i;

	//Read in a line, increment i for every character read.
	for (i=0; (c=getchar()) != EOF && c!='\n'; ++i) {
	
		//Only place character into s if there is still space.
		if (i < lim - 1)
			s[i] = c;
	}

	//Insert null character at end of line, or end of array if full.
	if (i < lim)
		s[i] = '\0';
	else
		s[lim - 1] = '\0';
		
	//Only return 0 if EOF was reached.
	if (i == 0 && c != EOF)
		++i;
	
	return i;
}
