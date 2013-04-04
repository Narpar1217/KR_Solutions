/* Exercise 2-9: In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit 
in x. Explain why. Use this observation to write a faster version of bitcount. */

#include <stdio.h>

int bitcount_old(unsigned x);
int bitcount(int x);
void test_bitcount(int x);

main()
{
	test_bitcount(0);
	test_bitcount(1);
	test_bitcount(~0);
	test_bitcount(040);
	test_bitcount(3);
	test_bitcount(041);
	test_bitcount(10);
	test_bitcount(013);
	test_bitcount(07);
	test_bitcount(255);
	
}


/* bitcount:  Count 1 bits in x (improved version)*/
int bitcount(int x)
{
	int count;
	
	for (count = 0; x != 0; x &= (x - 1))
		++count;
	
	return count;
}

/* bitcount_old:  Count 1 bits in x (old version) */ 
int bitcount_old(unsigned x) 
{ 
	int b; 

	for (b = 0; x != 0; x >>= 1) 
		if (x & 01) 
			b++; 
	
	return b; 
}

/* test_bitcount: Print the result of calling bitcount with value x */
void test_bitcount(int x)
{
	printf("bitcount %d\t| %d\n", x, bitcount(x));
}

