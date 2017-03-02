/*
 * labirinth.cpp
 *
 */

#include "Labirinth.h"

#include <iostream>
using namespace std;



Labirinth::Labirinth(int values[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			labirinth[i][j]=values[i][j];
}


void Labirinth::initializeVisited(int x, int y)
{
	for (int i = 0; i < 10; i++)
		for (int a = 0; a < 10; a++)
			visited[i][a] = false;
	visited[y][x] = true;
}


int Labirinth::getLabirinthValue(int x, int y)
{
	return labirinth[y][x];
}

int  Labirinth::processLabirinthPosition(int pos)
{
	switch(pos)
	{
	case 0:
		return WALL;
		break;
	case 1:
		return OK;
		break;
	case 2:
		return REACHED_GOAL;
	}

	return OK;
}

int  Labirinth::goRight( int x, int y)
{
	if (x >= 10 || x < 0 || y >= 10 || y < 0)
		return OUT_OF_BOUNDS;

	return processLabirinthPosition(getLabirinthValue(x + 1, y));
}

int  Labirinth::goLeft( int x, int y)
{
	if (x >= 10 || x < 0 || y >= 10 || y < 0)
		return OUT_OF_BOUNDS;

	return processLabirinthPosition(getLabirinthValue(x - 1, y));
}

int  Labirinth::goUp(int x, int y)
{
	if (x >= 10 || x < 0 || y >= 10 || y < 0)
		return OUT_OF_BOUNDS;

	return processLabirinthPosition(getLabirinthValue(x, y - 1));
}

int  Labirinth::goDown( int x, int y)
{
	if (x >= 10 || x < 0 || y >= 10 || y < 0)
		return OUT_OF_BOUNDS;

	return processLabirinthPosition(getLabirinthValue(x, y + 1));
}

void  Labirinth::printLabirinth()
{
	for (int i = 0; i < 10; i++)
	{
		for (int a = 0; a < 10; a++)
			cout << labirinth[i][a] << " ";

		cout << endl;
	}
}


bool Labirinth::findGoal(int x, int y)
{
	initializeVisited(x,y);
	foundTheSolution=false;
	return findGoal2(x,y);
}


bool  Labirinth::findGoal2(int x, int y)
{
	if (foundTheSolution)
		return true;

	///// TODO: Remove this, is part of the solution
	cout << "I'm visiting the position " << x << ", " << y;
	if (!visited[y][x + 1])
	{
		int res = goRight(x, y);

		if (res == REACHED_GOAL)
		{
			cout << ": Reached the goal!" << endl;
			foundTheSolution = true;
			return true;
		}
		else if (res == OK)
		{
			cout << ": Position is free!" << endl;
			visited[y][x + 1] = true;
			findGoal2(x + 1, y);
		}
	}

	if (foundTheSolution)
		return true;

	if (!visited[y][x - 1])
	{
		int res = goLeft(x, y);
		if (res == REACHED_GOAL)
		{
			cout << ": Reached the goal!" << endl;
			foundTheSolution = true;
			return true;
		}
		else if (res == OK)
		{
			cout << ": Position is free!" << endl;
			visited[y][x - 1] = true;
			findGoal2(x - 1, y);
		}
	}

	if (foundTheSolution)
		return true;

	if (!visited[y + 1][x])
	{
		int res = goDown(x, y);
		if (res == REACHED_GOAL)
		{
			cout << ": Reached the goal!" << endl;
			foundTheSolution = true;
			return true;
		}
		else if (res == OK)
		{
			cout << ": Position is free!" << endl;
			visited[y + 1][x] = true;
			findGoal2(x, y + 1);
		}
	}

	if (foundTheSolution)
		return true;

	if (!visited[y - 1][x])
	{
		int res = goUp(x, y);
		if (res == REACHED_GOAL)
		{
			cout << ": Reached the goal!" << endl;
			foundTheSolution = true;
			return true;
		}
		else if (res == OK)
		{
			cout << ": Position is free!" << endl;
			visited[y - 1][x] = true;
			findGoal2(x, y - 1);
		}
	}
	return false;
}


