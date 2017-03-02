/*
 * Partioning.cpp
 */

#include "Partitioning.h"
#include <iostream>


int s_recursive(int n,int k)
{
	if(k == 1 || k == n)
		return 1;
	else //let's suppose k and n are within expected values (1 < k < n)
		return s_recursive(n-1,k-1) + k*s_recursive(n-1,k);
}

int s_dynamic(int n,int k)
{
	int * values = new int[k+1];

	if(n == 0 && k == 0)
		return 1;

	//sets all values equal to 0, except the first one
	for(int i = 0; i <= k; i++)
		values[i] = i == 0 ? 1 : 0;

	int oldNminus1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			//first column has only 0s, the second has only 1s
			if(j == 0 || j == 1)
			{
				values[j] = j;
				oldNminus1 = 1;
			}
			else if(i == j)
				values[j] = 1;
			else if(i < j)
				values[j] = 0; //not really necessary
			else
			{
				//uses the values from the previous iteration, such as in the nCk problem
				int temp = values[j];
				values[j] = oldNminus1 + values[j]*j;
				oldNminus1 = temp;
			}
		}
	}

	return values[k];
}


int b_recursive(int n)
{
	int sum = 0;

	for(int k = 1; k <= n; k++)
		sum += s_recursive(n,k);

	return sum;
}

int b_dynamic(int n)
{
	int * values = new int[n+1];

	if(n == 0)
		return 1;

	//sets all values equal to 0, except the first one
	for(int i = 0; i <= n; i++)
		values[i] = i == 0 ? 1 : 0;

	int oldNminus1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			//first column has only 0s, the second has only 1s
			if(j == 0 || j == 1)
			{
				values[j] = j;
				oldNminus1 = 1;
			}
			else if(i == j)
				values[j] = 1;
			else if(i < j)
				values[j] = 0;  //not really necessary
			else
			{
				//uses the values from the previous iteration, such as in the nCk problem
				int temp = values[j];
				values[j] = oldNminus1 + values[j]*j;
				oldNminus1 = temp;
			}
		}
	}

	//suming the whole line gives the B value
	int sum = 0;

	for(int i = 0; i <= n; i++)
		sum+=values[i];

	return sum;
}


