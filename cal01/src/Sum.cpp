/*
 * Sum.cpp
 */

#include "Sum.h"
#include <iostream>

string calcSum(int* sequence, int size)
{
	int* sum = new int[size];
	int* index = new int[size];

	//the starting index
	for(int i = 0; i < size; i++)
	{
		int val = 0;

		//the size
		for(int j = i; j < size; j++)
		{
			val += sequence[j];
			if(i == 0)
			{
				sum[j] = val;
				index[j] = i;
			}
			else if(val < sum[j-i])
			{
				sum[j-i] = val;
				index[j-i] = i;
			}
		}
	}

	//saves to a string to compare more easily
	string result;
	ostringstream oss;

	for(int i=0; i < size;i++)
		oss << sum[i] << "," << index[i] << ";";

	result = oss.str();

	return result;
}


