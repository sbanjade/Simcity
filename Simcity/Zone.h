#include <vector>
#include <iterator>
using namespace std;

#pragma once
// Each zone instance has a location, population, adjacency to a power line, and adjacent zones.

template <class Z>
class Area
{
public:
    // Constructor initializes zone coordinates, power line adjacency, and population to zero.

	Area(int y, int x, bool adjtoPL)
	{
		this->adjtoPowerLine = adjtoPL;
		this->population = 0;
		this->x = x;
		this->y = y;
	}
    // Adds an adjacent zone to the current zone's adjacency list.

	void addAdjs(Z* adjs)
	{
		this->adjacents.push_back(adjs);
	}

	int getX(){return this->x;}
	int getY(){return this->y;}
	int getPopulation(){return this->population;}

	int getAdjPopulation() {
		int p = 0;
		typename vector<Z*>::iterator it;
		for (it = adjacents.begin(); it != adjacents.end(); it++) {
			p = p + (*it)->getPopulation();
		}
		return p;
	}

protected:
	int x, y;
	vector<Z*> adjacents;
	int population;
	bool adjtoPowerLine;
    // Checks if a certain number of adjacent zones have at least a specified population

	bool isadjwithPopulation(int nAreas, int p)
	{
		int count = 0;
		typename vector<Z*>::iterator it;
		for (it = adjacents.begin(); it != adjacents.end(); it++)
		{
			if ((*it)->getPopulation() >= p)
				count += 1;
		}

		if (count >= nAreas)return true;
		else return false;
	}
};
