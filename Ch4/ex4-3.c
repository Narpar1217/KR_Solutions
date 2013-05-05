/*
K&R Exercise 4-3
Author: Adam Beagle

Given the basic framework, it's straightforward to extend the calculator. Add 
the modulus (%) operator and provisions for negative numbers. 
*/

#include <math.h> //for fmod
#include <stdio.h>
#include <stdlib.h>	//for atof

#define BUFSIZE 100	//max size of buffer for getch and ungetch
#define MAXOP 100	//max size of operand or operator
#define MAXVAL 100	//maximum depth of val stack
#define NUMBER '0'	//signal that a number was found

int getch(void);
int getop(char[]);
int isdigit(char c);
void push(double);
double pop(void);
void ungetch(int);

/* Reverse Polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];
	
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
				
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
				
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
				
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("Error: Zero divisor\n");
				break;
				
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(), op2));
				else
					printf("Error: Zero divisor\n");
				break;
				
			case '\n':
				printf("\t%.8g\n", pop());
				break;
				
			default:
				printf("Error: Unknown command %s\n", s);
				break;
		}
	}

	return 0;
}

/*#################################################################*/
/* getop:
	Returns next operator, or numeric operand code.
*/
int getop(char s[])
{
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c; //not a number
	
	//Character '-' considered negative sign if
	//directly followed by a digit.
	if (c == '-') {
		if (isdigit(c = getch()))
			ungetch(c);
		else
			return '-';
	}
	
	//Collect integer part
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	
	//Collect fraction part
	if (c == '.') 
		while (isdigit(s[++i] = c = getch()))
			;
	
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
		
	return NUMBER;
}

/* isdigit:
	Returns true if c is a digit (1-9), false otherwise.
*/
int isdigit(char c)
{
	return (c >= '0' && c <= '9');
}


/*#################################################################*/
char buf[BUFSIZE]; //buffer for ungetch
int bufp = 0;

/* getch:
	Get a (possibly pushed-back) character
*/
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}


/* ungetch:
	Push character back on input
*/
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: Too many characters\n");
	else
		buf[bufp++] = c;
}


/*#################################################################*/
int sp = 0; //next free stack position
double val[MAXVAL]; //value stack

/* push:
	Pushes f onto value stack
*/
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error: Stack full, cannot push %g\n", f);
}


/* pop:
	Pops and returns top value from stack
*/
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("Error: Stack empty\n");
		return 0.0;
	}
}
