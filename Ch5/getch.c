/* getch.c
	Contains K&R utility functions getch and ungetch, 
	and their static variables.
*/

#include <stdio.h>

#define BUFSIZE 100	//max size of buffer for getch and ungetch

static char buf[BUFSIZE]; //buffer for ungetch
static int bufp = 0;

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
