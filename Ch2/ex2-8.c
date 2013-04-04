/* Exercise 2-8: Write a function rightrot(x,n) that returns the value of the integer x rotated 
to the right by n positions. */

#include <stdio.h>

unsigned rightrot(unsigned x, int n);
void test_rightrot(unsigned x, int n);

main()
{
	test_rightrot(0, 0);
	test_rightrot(0xF, 64);
	test_rightrot(0x0000FFFF, 16);
	test_rightrot(1, 1);
	test_rightrot(0x000FF000, 16);
	test_rightrot(0xF000000F, 16);
}


/* rightrot: Returns value of x rotated to the right by n positions.*/
unsigned rightrot(unsigned x, int n)
{
	unsigned rightEnd, leftEnd, size;
	
	size = 8*sizeof(x);
	
	if (n >= size)
		n = n % size;
	
	//mask n bits at right end of x
	rightEnd = x & ~(~0 << n);
	
	//shift rightEnd to left n bits of an unsigned to OR with rotated x
	leftEnd = rightEnd << (size - n);
	
	return (x >> n) | leftEnd;
	
}

/* test_rightrot: Print formatted results of sending args to rightrot */
void test_rightrot(unsigned x, int n)
{
	printf("\nrightrot(0x%x, %d)\n", x, n);
	printf("Result: 0x%x\n", rightrot(x, n));
}

