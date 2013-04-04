/* 
Exercise 1-12
Prints input, one word per line. 

Author: Adam Beagle
*/

#include <stdio.h>

int main()
{
	int c;
	
	printf("Type input, then press Enter to send to program.\nPress CTRL+D (EOF) to end.\n\n");
	
	while((c = getchar()) != EOF) {
		
		if (c == ' ' || c == '\n' || c == '\t') {
			putchar('\n');
		}
		else {
			putchar(c);
		}
	}
	
	return 0;
}
