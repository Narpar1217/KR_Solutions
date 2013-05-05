/*
K&R Exercise 4-5
Author: Adam Beagle

Add access to library functions like  sin,  exp, and  pow.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>	//for atof

#define MAXOP 100	//max size of operand or operator
#define NUMBER '0'	//signal that a number was found

void clear(void);
void duplicate_top(void);
int getop(char[]);
void print_top(void);
double pop(void);
void push(double);
void swap(void);


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
				
			//Power function
			case '^':
				op2 = pop();
				push(pow(pop(), op2));
				break;
				
			//Sine function
			case '~':
				push(sin(pop()));
				break;
				
			//Clears stack
			case 'c':
				clear();
				break;
			
			//Duplicates top element
			case 'd':
				duplicate_top();
				break;
			
			//Exponential function
			case 'e':
				push(exp(pop()));
				break;
				
			//Print top element of stack without popping
			case 'p':
				print_top();
				break;
				
			//Swap top two elements of stack
			case 's':
				swap();
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
// GETOP
/*#################################################################*/
int getch(void);
int isdigit(char c);
void ungetch(int);

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
// PUSH, POP, COMMANDS
/*#################################################################*/
#define MAXVAL 100	//maximum depth of val stack

int sp = 0; //next free stack position
double val[MAXVAL]; //value stack

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


/* clear:
	Clears the stack.
*/
void clear(void)
{
	//Nothing more needed; 
	//Data remains in stack but can only be overwritten, not accessed.
	sp = 0;
}


/* duplicate_top:
	Duplicates top element of stack.
*/
void duplicate_top(void)
{
	double top;
	
	if (sp > 0) {
		top = pop();
		push(top);
		push(top);
	}
	else
		printf("Error in duplicate_top: Stack empty\n");
}


/* print_top:
	Prints top element of stack without popping it.
*/
void print_top(void)
{
	if (sp > 0)
		printf("Top of stack: %g\n", val[sp - 1]);
	else
		printf("Stack empty.\n");
}


/* swap:
	Swaps top 2 elements of stack.
*/
void swap(void)
{
	double op1; 
	double op2; 
	
	if (sp > 1) {
		op1 = pop();
		op2 = pop();
		push(op1);
		push(op2);
	}
	else
		printf("Error in swap: Stack contains fewer than 2 elements.\n");
}

/*#################################################################*/
// GETCH & UNGETCH
/*#################################################################*/
#define BUFSIZE 100	//max size of buffer for getch and ungetch

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
