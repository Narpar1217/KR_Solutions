/*
K&R Exerciese 4-2
Author: Adam Beagle

Extend atof to handle scientific notation of the form 
	123.45e-6 
where a floating-point number may be followed  by e or E and
an optionally signed exponent.
*/

#include <math.h>
#include <stdio.h>
#include <stdbool.h>

double atof(char[]);
double atof_scinotexp(char[], int);
bool isdigit(char);
bool isspace(char);
void test_atof(char[]);

int main()
{
	//test data
	test_atof("0.0");
	test_atof("0.0e-5");
	test_atof("1.234");
	test_atof("1.234e0");
	test_atof("1.234e1");
	test_atof("1.234e-1");
	test_atof("1.234e+4");
	test_atof("1.234e-3");
	test_atof("1.234e10");
	test_atof("1.234e-10");
	test_atof("0");
	test_atof("1234");
	test_atof("1234e2");
	
	return 0;
}

/* atof:
	Returns string s as double.
*/
double atof(char s[])
{
	double val, power;
	int i, sign;
	
	//Skip white space
	for (i = 0; isspace(s[i]); i++)
		;
		
	//Account for sign
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
		
	//Account for digits pre-decimal
	for (val  = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	
	if (s[i] == '.')
		i++;
	
	//Account for digits post-decimal, accumulating
	//powers of 10 in power to correctly place decimal
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	
	val = sign * (val / power);
	
	//Account for scientific notation
	//Note atof_scinotexp returns 1 if s not in scientific notation form
	val *= atof_scinotexp(s, i);
	
	
	return val;
}


/* atof_scinotexp:
	Returns 10 raised to exp, for exp in string s of form 1234.56(e|E)(+|-)exp.
	i is index at which to start scanning s for 'e' or 'E'.
	Returns 1 if s not in scientific notation form.
*/
double atof_scinotexp(char s[], int start)
{
	int i, sign;
	double power;
	
	//Scan s until 'e' or 'E' found
	for (i = start; s[i] != 'e' && s[i] != 'E'; i++)
		if (s[i] == '\0')
			return 1;
	
	//Account for sign
	i++;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	
	//Get exponent
	for (power = 0.0; isdigit(s[i]); i++)
		power = (power * 10.0) + (s[i] - '0');
		
		
	return pow(10, sign * power);
}


/* isdigit:
	Returns true if c is a digit (1-9), false otherwise.
*/
bool isdigit(char c)
{
	return (c >= '0' && c <= '9');
}


/* isspace:
	Returns true if c is whitespace, false otherwise.
*/
bool isspace(char c) 
{
	return (c == ' ' || c == '\t' || c == '\n');
}


/* test_atof:
	Pass s to atof and print formatted results.
*/
void test_atof(char s[])
{
	printf("s: %s\nf: %.10f\n\n", s, atof(s));
}
