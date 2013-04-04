/* 
Exercise 1-5
Modify the Fahrenheit-Celsius table to print in reverse order (upper limit to lower). 

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
	printf("%2s\t%4s\n", "C", "F");
	printf("%s\t%6s\n", "___", "_____");

	//Calculate each celsius value and print each table row.
	fahr = upper;
	while(fahr >= lower) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr -= step;
	}
	
	return 0;
}
