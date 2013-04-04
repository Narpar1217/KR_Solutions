/* Exercise 1-9: Copy input to output, replacing multiple spaces with one space. */

#include <stdio.h>
#include <stdbool.h>

main()
{
	int c;
	bool space;

	space = false;
	
	printf("Type input, then press Enter to send to program.\nPress CTRL+D (EOF) to end and print results.\n\n");
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' && space == false) {
			space = true;
			putchar(c);
		}
		else if (c != ' ') {
			space = false;
			putchar(c);
		}
	}
}
