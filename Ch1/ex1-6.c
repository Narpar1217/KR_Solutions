/* 
Exercsise 1-6
Verify that the expression getchar() != EOF is 0 or 1.  

Author: Adam Beagle
*/

#include <stdio.h>

int main()
{
	int c;
	
	printf("Enter any character but EOF: ");
	c = getchar();
	printf("Result of getchar() != EOF is %d\n\n", c != EOF);
	
	getchar(); //Account for return press
	
	printf("Enter EOF (CTRL+D): ");
	c = getchar();
	printf("\nResult of getchar() != EOF is %d\n\n", c != EOF);
	
	return 0;
}
