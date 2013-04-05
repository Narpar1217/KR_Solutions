/*
Exercise 1-18
Write a program to remove trailing blanks and tabs from each line of input, 
and to delete entirely blank lines. 

Author: Adam Beagle
*/

#include <stdio.h>

#define MAXLINE 1000 	/* maximum input line length */

int _getline(char s[], int lim);	// NOTE: underscore is necessary! Otherwise, name conflicts with stdio.h function.
int strip(char from[], char to[]);


int main()
{
	int len;					// current line length
	char line[MAXLINE];			// input line
	char editedLine[MAXLINE]; 	// input line after being cleaned up

	while ((len = _getline(line, MAXLINE)) > 0) {
		len = strip(line, editedLine);
		if (len > 1)			
			printf("%s\n", editedLine);
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


/* strip: Removes trailing whitespace from 'from', 
and places edited string in 'to.' 
Returns length of 'to.'
Assumes 'to' is of sufficient size.
Note that 'to' will not have a newline at its end.*/
int strip(char from[], char to[])
{
	int i, toI;
	int firstNonWS, lastNonWS;	// indices of first and last characters that are not whitespace
	

	firstNonWS = lastNonWS = -1;
	for(i = 0; from[i] != '\n' && from[i] != '\0'; i++) { 	// scan 'from' for firstNonWS and lastNonWS
		
		if (from[i] != ' ' && from[i] != '\t') {
			lastNonWS = i;

			if (firstNonWS < 0)
				firstNonWS = i;
		}
	} 

	if (firstNonWS < 0)
		firstNonWS = 0;

	toI = 0;
	for (i = firstNonWS; i <= lastNonWS; ++i)
		to[toI++] = from[i];

	to[toI] = '\0';

	return toI;
}
