/* Exercise 1-14: Print histogram of frequencies of characters in input. */

#include <stdio.h>
#include <stdbool.h>

#define STARTCHAR 	' '
#define ENDCHAR 	'}'
#define ARRSIZE		ENDCHAR - STARTCHAR + 1
#define HISTCHAR 	'|'
#define MAXROW		40
#define SCALESTEP	5

main()
{
	int c, i, j, highestFreq, scale;
	int charCounts[ARRSIZE];
	bool flag;
	
	highestFreq = 0;
	scale = 1;
	flag = false;

	//Initialize all elements of charCounts to 0
	for (i = 0; i < ARRSIZE; ++i)
		charCounts[i] = 0;
		
	printf("Type input, then press Enter to send to program.\nPress CTRL+D (EOF) to end and print results.\n\n");

	//Get input; Count character frequencies
	while ((c = getchar()) != EOF) {
		if (c >= STARTCHAR && c <= ENDCHAR) {
			++charCounts[c - STARTCHAR];
			
			if (charCounts[c - STARTCHAR] > highestFreq)
				highestFreq = charCounts[c - STARTCHAR];
		}
	}
	
	//Scale frequencies so none exceed MAXROW
	while (highestFreq > MAXROW) {
		scale = (scale == 1) ? scale * SCALESTEP : scale + SCALESTEP;
		highestFreq /= SCALESTEP;
	}
	
	for (i = 0; i < ARRSIZE; ++i) {
		flag = charCounts[i] > 0;
		charCounts[i] /= scale;
		
		//Differentiate elements with frequency less than scale, 
		//  so they're still represented in histogram.
		if (flag && charCounts[i] == 0)
			charCounts[i] = -1;
	}

	//Print histogram
	printf("\nSCALE: | = %d\n\n", scale);
	
	for (i = 0; i < ARRSIZE; ++i) {
		if (charCounts[i] != 0) {
			printf("%c: ", i + STARTCHAR);

			for (j = 0; j < charCounts[i]; ++j)
				printf("%c", HISTCHAR);
				
			printf("\n");
		}
	}
}
