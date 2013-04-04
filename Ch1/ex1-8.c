/* 
Exercise 1-8
Count blanks, tabs, and newlines in input. 

Author: Adam Beagle
*/

#include <stdio.h>

int main()
{
	int c, blanks, tabs, newlines;

	blanks = tabs = newlines = 0;
	
	
	printf("Type input, then press Enter to send to program.\nPress CTRL+D (EOF) to end and print results.\n\n");
	
	while ((c = getchar()) != EOF)
		if (c == ' ')
			blanks++;
		else if (c == '\t')
			tabs++;
		else if (c == '\n')
			newlines++;

	printf("\nBlanks:\t\t%d\nTabs:\t\t%d\nNewlines:\t%d\n", blanks, tabs, newlines);
	
	return 0;
}
