/* 
Exercise 1-3
Print Fahrenheit-Celsius table with a heading above it. 

Author: Adam Beagle
*/

#include <stdio.h>

int main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;		//Lower limit of temperature scale
	upper = 300;	//Upper limit
	step = 20;		//Step size


	//Print heading
	printf("\n  CONVERSION TABLE\n");
	printf("Fahrenheit to Celsius\n");
	printf("---------------------\n\n");
	
	//Print column headers
	printf("%2s\t%4s\n", "F", "C");
	printf("%s\t%6s\n", "___", "_____");

	//Calculate each celsius value and print each table row.
	fahr = lower;
	while(fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr += step;
	}

	return 0;
}
