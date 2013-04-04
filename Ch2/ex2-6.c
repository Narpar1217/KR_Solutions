/* Exercise 2-6: Write a function setbits(x,p,n,y) that returns x with the n bits that begin at 
position p set to the rightmost n bits of y, leaving the other bits unchanged. */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
void test_setbits(unsigned x, int p, int n, unsigned y, unsigned expected);

main()
{
	test_setbits(070, 2, 3, 007, 077);
	test_setbits(007, 5, 3, 007, 077);
	test_setbits(077, 5, 1, 0, 037);
	test_setbits(077, 3, 2, 0, 063);
	test_setbits(0, 31, 32, ~0, ~0);
	test_setbits(0, 31, 32, 0, 0);
}

/* setbits: Returns x with the n bits that begin at position p set to the rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned mask;
	int i;
	
	//Create mask of n bits of 0 starting at position p
	mask = ((n / 8) == sizeof(unsigned)) ? 0 : ~0 << n; 	//Can't lshift all bits; See ex2-7.c
	for (i = 0; i < p + 1 - n; ++i)
		mask = (mask << 1) | 1;
	
	//Clear n bits of x starting at p
	x = x & mask;
	
	//Mask first n bits of y, then rightshift into position p
	mask = ((n / 8) == sizeof(unsigned)) ? ~0 : ~(~0 << n); //Can't lshift all bits; See ex2-7.c
	y = (y & mask) << (p + 1 - n);
	
	return x | y;
}


/* test_setbits: Print formatted results of passing args to setbits, in order. 
      expected is the expected result of calling setbits on the arguments. */
void test_setbits(unsigned x, int p, int n, unsigned y, unsigned expected)
{
	printf("\nSetbits(%u, %d, %d, %u)\n--------------------\n", x, p, n, y);
	printf("Expected: %u\n", expected);
	printf("Result:   %u\n", setbits(x, p, n, y));
}
