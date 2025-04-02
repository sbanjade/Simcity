#include "Area.h"
using namespace std;

#pragma once
// Industrial Area (IArea) class: Represents an industrial zone within the city simulation, where workers and goods are managed
class IArea : public Area<IArea>
{
public:
	IArea(int y, int x, bool adjtoPL, Common* c)
		:Area(y, x, adjtoPL) {
		this->common = c;
		isImplementable = false;
		w1 = NULL;
		w2 = NULL;
	}
// STEP method: Determines if the zone meets conditions to be populated by workers based on adjacency and available workers
	void STEP()
	{
		isImplementable = false;
		vector<Worker*> w = common->getAvailWorkers();
		if (population == 0 && adjtoPowerLine && w.size() >= 2) { // Check different conditions based on population level, adjacency, and worker availability

			w1 = w.at(0);
			w2 = w.at(1);
			isImplementable = true;
		}
		else if (population == 0 && isadjwithPopulation(1, 1) && w.size() >= 2) {
			w1 = w.at(0);
			w2 = w.at(1);
			isImplementable = true;
		}
		else if (population == 1 && isadjwithPopulation(2, 1) && w.size() >= 2) {
			w1 = w.at(0);
			w2 = w.at(1);
			isImplementable = true;
		}
		else if (population == 2 && isadjwithPopulation(4, 2) && w.size() >= 2) {
			w1 = w.at(0);
			w2 = w.at(1);
			isImplementable = true;
		}
	}
// getGoodsSoldable method: Returns a list of goods in the zone that are available for sale
	vector<Good*> getGoodsSoldable() {
		vector<Good*> g;
		vector<Good*>::iterator it;

		for (it = goods.begin(); it != goods.end(); it++)
		{
			if ((*it)->isSoldable())
				g.push_back(*(it));
		}

		return g;
	}
// Implement method: Finalizes population growth and production within the zone if conditions are met
	void Implement() {
		if (isImplementable) {
			STEP();
			if (isImplementable) {
				isImplementable = false;
				++population;
				w1->assign();
				w2->assign();
				goods.push_back(new Good());
			}
		}
	}

private:
	bool isImplementable;
	Common* common;
	vector<Good*> goods;
	Worker *w1, *w2;
};

