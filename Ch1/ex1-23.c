/*
Exercise 1-23
Write a program to remove all comments from a C program. 
Don't forget to handle quoted strings and character constants properly. 
C comments don't nest. 

Usage: Redirect file to stdin. Example: ./this_program < file.ext

Author: Adam Beagle
*/

#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000

int _getline(char s[], int lim);
bool remove_comments(char s[], bool multiline);


/* Removes all comments from a C program passed in as an input stream. 
   Assumes comments in passed program are syntacically valid.*/
int main()
{
	char s[MAXLINE];
	int len;
	bool multiline;
	
	multiline = false;
	while ((len = _getline(s, MAXLINE)) > 0) {
		multiline = remove_comments(s, multiline);
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

/* remove_comments: Removes any comment in line 's' and prints line.
   If 'multiline' is true, assumes start of line is part of multiline comment.   
   Returns whether string ended inside multiline comment. */
bool remove_comments(char s[], bool multiline)
{
	int i;
	bool singQuoted, doubQuoted;
	
	singQuoted = doubQuoted = false;
	
	for (i = 0; s[i] != '\0'; ++i) {
		// Case: double slash comment (rest of line is comment, so break)
		if (s[i] == '/' && s[i + 1] == '/' && !doubQuoted && !multiline) {
			putchar('\n');
			break;
		}
		
		// Case: start of multiline comment
		else if (s[i] == '/' && s[i + 1] == '*' && !doubQuoted)
			multiline = true;
			
		// Case: end of multiline comment
		else if (s[i] == '/' && i > 0 && s[i - 1] == '*' && !doubQuoted) {
			multiline = false;
			continue;
		}
		
		// Case: double quote.
		else if(s[i] == '\"' && i > 0 && s[i - 1] != '\\')
			doubQuoted = !doubQuoted;
	
		if (!multiline)
			putchar(s[i]);
	}
	
	putchar('\n');
	
	return multiline;
}




