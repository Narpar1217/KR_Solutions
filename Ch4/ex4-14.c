/*
K&R Exercise 4-14
Author: Adam Beagle

Define a macro swap(t,x,y) that interchanges two arguments of type t. 
(Block structure will help.)  
*/

#include <stdio.h>

#define swap(t, x, y) do{t temp = x; x = y; y = temp;} while(0)

/* Tests swap macro */
int main()
{
	int x = 20;
	int y = 10;
	char c1 = 'i';
	char c2 = 'h';
	
	swap(int, x, y);
	printf("x: %d\ny: %d\n\n", x, y);
	
	swap(char, c1, c2);
	printf("c1: %c\nc2: %c\n\n", c1, c2);
	
	return 0;
}
