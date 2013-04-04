/* Exercise 1-13: Print histogram of lengths of words in input. */

#include <stdio.h>
#include <stdbool.h>

#define MAXLEN 		20
#define HISTCHAR 	'|'
#define MAXROW		40
#define SCALESTEP	5

main()
{
	int c, i, j, wordLen, highestFreq, scale;
	int lenArray[MAXLEN + 1];
	bool flag;
	
	scale = 1;
	highestFreq = 0;
	flag = false;

	//Initialize all in lenArray to 0
	for (i = 0; i <= MAXLEN; ++i)
		lenArray[i] = 0;

	printf("Type input, then press Enter to send to program.\nPress CTRL+D (EOF) to end and print results.\n\n");
		
	wordLen = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			++lenArray[wordLen];
			wordLen = 0;
			
			if (lenArray[wordLen] > highestFreq)
				highestFreq = lenArray[wordLen];
		}
		else
			++wordLen;
	}
	
	//Scale lengths so none exceed MAXROW
	while (highestFreq > MAXROW) {
		scale = (scale == 1) ? scale * SCALESTEP : scale + SCALESTEP;
		highestFreq /= SCALESTEP;
	}
	
	for (i = 0; i < MAXLEN; ++i) {
		flag = lenArray[i] > 0;
		lenArray[i] /= scale;
		
		//Differentiate elements with frequency less than scale, 
		//  so they're still represented in histogram.
		if (flag && lenArray[i] == 0)
			lenArray[i] = -1;
	}

	//Print histogram
	printf("\nSCALE: | = %d\n\n", scale);
	
	for (i = 1; i < MAXLEN; ++i) {
		if (lenArray[i] != 0) {
			if (i < 10)
				printf(" ");
				
			printf("%d: ", i);

			for (j = 0; j < lenArray[i]; ++j)
				printf("%c", HISTCHAR);
				
			printf("\n");
		}
	}
}
