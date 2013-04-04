/* 
Exercise 1-15
Modify the temperature conversion table program from
earlier exercises to use a function for conversion. 

Author: Adam Beagle
*/

#include <stdio.h>

float fahr_to_cels(float temp);

int main()
{
	float fahr;
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
		printf("%3.0f\t%6.1f\n", fahr, fahr_to_cels(fahr));
		fahr += step;
	}

	return 0;
}

/* fahr_to_cels: Returns temp converted from Fahrenheit to Celsius.*/
float fahr_to_cels(float temp)
{
	return (5.0/9.0) * (temp - 32.0);
}
