/*
 * Factorial.cpp
 */

#include "Factorial.h"

int factorialRecurs(int n)
{
	if(n == 1)
		return 1;
	else
		return n*factorialRecurs(n-1);
}

int factorialDinam(int n)
{
	int result = n;

	while(n > 1)
		result *= --n;

	return result;
}

int* factorialDinamArray(int n)
{
	int* values = new int[n+1];

	//n is always larger than 0, so
	values[0] = 1;

	for(int i = 1; i <= n; i++)
		values[i] = values[i-1]*i;

	return values;
}




