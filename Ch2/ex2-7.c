/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at 
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged. */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
void test_invert(unsigned x, int p, int n);

main()
{
	test_invert(0, 5, 6);
	test_invert(077, 5, 6);
	test_invert(052, 5, 6);
	test_invert(052, 2, 3);
	test_invert(~0, 31, 32);
}

/* invert: returns x with the n bits that begin at position p inverted.  
Position is 0-based and right aligned. */
unsigned invert(unsigned x, int p, int n)
{
	//Without this, when trying to shift out all bits of x, no shift will occur (shifts masked to 5 bits; 32 | 31 = 0)
	if (n / 8 == sizeof(unsigned))
		return x ^ ~0;
	
	return x ^ (~(~0 << n) << (p + 1 - n));
}

/* test_invert: send passed values to invert and print formatted results */
void test_invert(unsigned x, int p, int n)
{
	printf("\ntestinvert(%u, %d, %d)\n", x, p, n);
	printf("Result: %u\n", invert(x, p, n));
}

