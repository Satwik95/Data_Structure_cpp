/*
Add two numbers without using arithmetic operators
1)storing sum without considering carry at all in x first
by statement x=x^y (add carries to me please!)
2)carry has been stored by c=x&y beforehand for each position of bit
3)y=c<<1 shifts carries by 1 (coz we know carry get added to next bit on the left as usual)
*/
#include<stdio.h>

int Add(int x, int y)
{
	// Iterate till there is no carry 
	while (y != 0)
	{
		// carry now contains common set bits of x and y
		int carry = x & y; 

		// Sum of bits of x and y where at least one of the bits is not set
		x = x ^ y; 

		// Carry is shifted by one so that adding it to x gives the required sum
		y = carry << 1;
	}
	return x;
}

int main()
{
	printf("%d", Add(23, 42));
	return 0;
}
