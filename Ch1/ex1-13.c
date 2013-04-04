/* 
Exercise 1-13
Print histogram of lengths of words in input. 

Author: Adam Beagle
*/

#include <stdio.h>
#include <stdbool.h>

#define MAXLEN 		20
#define HISTCHAR 	'|'
#define MAXROW		40
#define SCALESTEP	5

void print_histogram(int data[], int length, int scale, int histChar);
int scale_ints(int data[], int length, int max, int scaleStep, int highest);

int main()
{
	int c, i, wordLen, highestFreq, scale;
	int lenArray[MAXLEN + 1];

	highestFreq = 0;
	
	//Initialize all in lenArray to 0
	for (i = 0; i <= MAXLEN; ++i)
		lenArray[i] = 0;

	printf("Type input, then press Enter to send to program.\nPress CTRL+D (EOF) to end and print results.\n\n");
		
	wordLen = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (wordLen <= MAXLEN && wordLen > 0) {
				++lenArray[wordLen];
				
				if (lenArray[wordLen] > highestFreq)
					highestFreq = lenArray[wordLen];
			}
			
			wordLen = 0;
		}
		else
			++wordLen;
	}
	
	scale = scale_ints(lenArray, MAXLEN + 1, MAXROW, SCALESTEP, highestFreq);
	print_histogram(lenArray, MAXLEN + 1, scale, HISTCHAR);
	
	return 0;
}

/* print_histogram: Writes a histogram of frequencies contained in data.
	data is length of data array.
	scale is the amount each character on the histogram represents.
	histChar is the character to use to print the histogram.
	Assumes data is already scaled. */
void print_histogram(int data[], int length, int scale, int histChar)
{
	int i, j;
	
	printf("\nSCALE: | = %d\n\n", scale);
	
	for (i = 0; i < length; ++i) {
		if (data[i] != 0) {
			printf("%02d: ", i);

			for (j = 0; j < data[i]; ++j)
				printf("%c", histChar);
				
			printf("\n");
		}
	}
	
	return;
}


/* scale_ints: Scales an array of positive integers so that none is greater than passed maximum value.
	Returns value by which data was scaled. 
	Data with values greater than 0 but less than step size are given value of -1.*/
int scale_ints(int data[], int length, int max, int scaleStep, int highest)
{
	int i;
	int scale = 1;
	bool flag;
	
	//Find scale by dividing highest by scaleStep until it is less than max
	while (highest > max) {
		scale = (scale == 1) ? scale * scaleStep : scale + scaleStep;
		highest /= scaleStep;
	}
	
	for (i = 0; i < length; ++i) {
		flag = data[i] > 0;
		data[i] /= scale;
		
		if (flag && data[i] == 0)
			data[i] = -1;
	}
	
	return scale;
}
