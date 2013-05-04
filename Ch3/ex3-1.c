/* 
K&R Exercise 3-1 
Author: Adam Beagle

Our binary search makes two tests inside the loop, when one would suffice (at 
the price of more tests outside.) Write a version with only one test inside the loop and 
measure the difference in run-time.   
*/

#include <stdio.h>
#include <time.h>

/*
On my machine, these test values result in a 
runtime of <2 seconds for each algorithm.
*/
#define TEST_LIMIT 500000   //Number of values in test array
#define TEST_ITERS 10000000 //Number of times the worst-case search 
                            //  is run with each algortithm

int binsearch(int x, int v[], int n);
int binsearch_two_tests(int x, int v[], int n);

/* main:
	Times binsearch and binsearch_two_tests against 
	arbitrary (but fairly long) test array at worst case,
	i.e. an element not in the array.
*/
int main()
{
	int testData[TEST_LIMIT];
	int len, i;
	clock_t start, stop;
	
	for (i = 0; i < TEST_LIMIT; i++)
		testData[i] = i;

	len = TEST_LIMIT;
	
	start = clock();
	for (i = 0; i < TEST_ITERS; i++)
		binsearch(-1, testData, len);
	stop = clock();
	printf("binsearch time: %fs\n", (double)(stop - start) / CLOCKS_PER_SEC);
	
	start = clock();
	for (i = 0; i < TEST_ITERS; i++)
		binsearch_two_tests(-1, testData, len);
	stop = clock();
	printf("two_tests time: %fs\n", (double)(stop - start) / CLOCKS_PER_SEC);

	
	return 0;
}

/* 
binsearch:  
  Finds x in v[0] <= v[1] <= ... <= v[n-1] 
  This version uses only 1 test within the loop.
*/ 
int binsearch(int x, int v[], int n)
{ 
	int low, high, mid; 

	low = 0; 
	high = n - 1; 
	mid = (low + high) / 2; 
	
	//Search until x found or x guaranteed to not be in v
	while (v[mid] != x && low <= high) { 
		mid = (low+high) / 2; 
	   
		if (x < v[mid]) 
			high = mid - 1; 
		else
			low = mid + 1;
	} 
	
    if (v[mid] == x)
		return mid;  	//Found match
	else
		return -1;   	//No match
} 

/* 
binsearch_two_tests:  
  Finds x in v[0] <= v[1] <= ... <= v[n-1] 
  Original K&R version referred to in problem description.
*/ 
int binsearch_two_tests(int x, int v[], int n) 
{ 
   int low, high, mid; 

   low = 0; 
   high = n - 1; 
   
   while (low <= high) { 
	   mid = (low + high) / 2; 
	   
	   if (x < v[mid]) 
		   high = mid - 1; 
	   else if (x  > v[mid]) 
		   low = mid + 1; 
	   else    /* found match */ 
		   return mid; 
   } 
   
   return -1;   /* no match */ 
} 
