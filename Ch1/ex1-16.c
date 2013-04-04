/* 
Exercise 1-16
Revise the main routine of the longest-line program so it will correctly print 
the length of arbitrarily long input lines, and as much as possible of the text. 

Usage: Redirect file to stdin. Example: ./this_program < file.ext

Author: Adam Beagle
*/

#include <stdio.h>

#define MAXLINE 100 	/* Maximum input line length.*/

void copy(char to[], char from[]);
int _getline(char s[], int lim); // NOTE: Underscore is necessary! Without it, name conflicts with stdio.h function.


int main()
{
	int len;				// Current line length
	int max;				// Maximum length seen so far
	char line[MAXLINE];		// Current input line
	char longest[MAXLINE];	// Longest line saved here

	max = 0;
	while ((len = _getline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0) //If at least one line was found
		printf("\nLongest line:\n%s\n\nLength: %d\n\n", longest, max);
	
	
	return 0;
}

/* _getline: Reads as much as possible of a line into s. 
Returns length of entire line, even if it did not fit in s.
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

/* copy: Copies 'from' into 'to.' Assumes to is of sufficient length. */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;

}
