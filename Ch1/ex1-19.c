/*
Exercise 1-19
Write a function reverse(s) that reverses the character string s. 
Use it to write a program that reverses its input a line at a time. 

Usage: Redirect file to stdin. Example: ./this_program < file.ext

Author: Adam Beagle
*/

#include <stdio.h>

#define MAXLINE 1000	//Maximum line length

void reverse(char s[], int len);
int _getline(char s[], int lim);


int main()
{
	char line[MAXLINE];
	int len;
	
	while ((len = _getline(line, MAXLINE)) > 0) {
		reverse(line, len);
		printf("%s\n", line);
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

/* reverse: Reverses string 's' in place. */
void reverse(char s[], int len)
{
	int i;
	char temp;
	
	if (s[len - 1] == '\n')
		len -= 1;

	for (i = 0; i < (len/2); i++) {
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
	
	return;
}
