#include "Area.h"

#pragma once
// Residential Area (RArea) class: Represents a residential zone within the city simulation where population growth is tracked

class RArea : public Area<RArea>
{
public:
// Constructor: Initializes an RArea object with position and adjacency to power line status
	RArea(int y, int x, bool adjtoPL)
		:Area(y, x, adjtoPL) {
		newPopulation = 0;
	}

	vector<Worker*> getWorkersAvailable()
	{
		vector<Worker*> w;
		vector<Worker*>::iterator it;

		for (it = workers.begin(); it != workers.end(); it++)
		{
			if ((*it)->isAvailable())
				w.push_back(*(it));
		}

		return w;
	}
	
	// STEP method: Evaluates the conditions for population increase based on adjacency to other populated zones or power lines
	void STEP()
	
	{
		if (population == 0 && adjtoPowerLine) {
			newPopulation = population + 1;
			t_workers.push_back(new Worker());
		}
		else if (population == 0 && isadjwithPopulation(1, 1)) {
			newPopulation = population + 1;
			t_workers.push_back(new Worker());
		}
		else if (population == 1 && isadjwithPopulation(2, 1)) {
			newPopulation = population + 1;
			t_workers.push_back(new Worker());
		}
		else if (population == 2 && isadjwithPopulation(4, 2)) {
			newPopulation = population + 1;
			t_workers.push_back(new Worker());
		}
		else if (population == 3 && isadjwithPopulation(6, 3)) {
			newPopulation = population + 1;
			t_workers.push_back(new Worker());
		}
		else if (population == 4 && isadjwithPopulation(8, 4)) {
			newPopulation = population + 1;
			t_workers.push_back(new Worker());
		}
	}
// implement method: Updates the zone's population based on the new population calculated in the STEP method
	void implement() { 
		population = newPopulation; 
		workers.insert(workers.end(), t_workers.begin(), t_workers.end());
		t_workers.clear();
	}

private:
	int newPopulation;
	vector<Worker*> workers, t_workers;
};