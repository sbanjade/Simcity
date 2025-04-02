#include "Area.h"
#pragma once
// CArea class: Represents a commercial zone within the city, derived from the Area template
class CArea : public Area<CArea>
{
public:
// Constructor: Initializes a CArea object with its coordinates, adjacency to a power line, and a common resource manager
	CArea(int y, int x, bool adjtoPL, Common* c)
		:Area(y, x, adjtoPL) {
		this->common = c;
		isImplementable = false;
		good = NULL;
		worker = NULL;
	}
// STEP method: Determines whether the zone is ready for implementation based on population and adjacency conditions
	void STEP()
	{
		isImplementable = false;
		vector<Good*> g = common->getSoldableGoods();
		vector<Worker*> w = common->getAvailWorkers();
		if (population == 0 && adjtoPowerLine && w.size() >= 1 && g.size() >= 1) {
			isImplementable = true;
			good = g.at(0);
			worker = w.at(0);
		}
		else if (population == 0 && isadjwithPopulation(1, 1) && w.size() >= 1 && g.size() >= 1) {
			isImplementable = true;
			good = g.at(0);
			worker = w.at(0);
		}
		else if (population == 1 && isadjwithPopulation(2, 1) && w.size() >= 1 && g.size() >= 1) {
			isImplementable = true;
			good = g.at(0);
			worker = w.at(0);
		}
	}

	void Implement() {   // Implement method: Executes implementation if the zone meets the required conditions
		if (isImplementable) {
			STEP();
			if (isImplementable) {
				isImplementable = false;
				++population;
				worker->assign();
				good->sell();
			}
		}
	}

private:
	bool isImplementable;
	Common* common;
	Good* good;
	Worker* worker;
};
