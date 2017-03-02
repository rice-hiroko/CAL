/*
 * Change.cpp
 */

#include "Change.h"
#include <iostream>

string calcChange(int n)
{
	int* changeDone = new int[n+1];
	int* lastCoin = new int[n+1];
	int coinValues[4] = {0,5,2,1};  //0 is an invalid coin

	for(int i=0; i <= n; i++)
	{
		changeDone[i] = 0;
		lastCoin[i] = 0;
	}

	//exactly like the backpack problem (just a little tuneup)
	for(int i = 1; i <= 3; i++)
	{
		int coinValue=coinValues[i];
		if(coinValue <= n)
		{
			for(int j = coinValue; j <= n; j++)
			{
				//consider also the value already saved
				int remainder=j-coinValue;
				if(changeDone[j] + coinValue <= j &&
						(coinValue + changeDone[remainder]) <= j)
				{
					changeDone[j] = coinValue + changeDone[remainder];
					lastCoin[j] = i;

				}
			}
		}
	}

	//saves to a string to compare more easily
	string result;
	ostringstream oss;
	bool putComma = false;

	for(int i=1; i <= n;i++)
	{
		for(int j=i;j > 0; j-= coinValues[lastCoin[j]])
		{
			if(putComma)
				oss << ",";

			oss << coinValues[lastCoin[j]];
			putComma=true;
		}
		oss << ";";
		putComma = false;

	}

	result = oss.str();

	return result;
}


