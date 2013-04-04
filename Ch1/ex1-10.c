/* 
Exercise 1-10
Copy input to output, replacing tabs, backspaces, 
and backslashes with string escape sequence.

Author: Adam Beagle
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
	int c;
	
	printf("Type input, then press Enter to send to program.\nPress CTRL+D (EOF) to end.\n\n");
	
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');
		}
		else if (c == '\b') {
			putchar('\\');
			putchar('b');
		}
		else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		}
		else
			putchar(c);
	}
	
	return 0;
}
