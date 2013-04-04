/*
Exercise 1-4
Alter the program from 1-3 to convert Celsius to Fahrenheit. 

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
	printf("Celsius to Fahrenheit\n");
	printf("---------------------\n\n");
	
	//Print column headers
	printf("%2s\t%4s\n", "C", "F");
	printf("%s\t%6s\n", "___", "_____");

	//Calculate each Fahrenheit value and print each table row.
	celsius = lower;
	while(celsius <= upper) {
		fahr = ((9.0/5.0) * celsius) + 32.0;
		printf("%3.0f\t%6.1f\n", celsius, fahr);
		celsius += step;
	}
	
	return 0;
}
