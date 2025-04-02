#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <cmath>
#include <queue>


#include "Good.h"
#include "Worker.h"
#include "Common.h"
#include "CommercialArea.h"
#include "IndustialArea.h"
#include "ResidentialArea.h"
using namespace std;

#pragma once
// UrbanSimulation class: Manages the structure, zones, and operations of the simulated city
class UrbanSimulation : protected Common
{
public:

    UrbanSimulation(string filename);
    ~UrbanSimulation();
// Simulation parameters
    int refresh_rate, time_limit;
    char* regionName;

    int getWidth() {return this->width;}
    int getLength() { return this->length; }
    void display();
    void displayPollution();
    // Retrieve available workers and goods in the city
    vector<Worker*> getAvailWorkers();
    vector<Good*> getSoldableGoods();

    int getRPopulation(int, int, int, int);
    int getCPopulation(int, int, int, int);
    int getIPopulation(int, int, int, int);
    
    int getTotalPollution(int, int, int, int);

    bool RunSimulationStep(int);

private:
// Area containers for each type
    vector<CArea*> czones;
    vector<RArea*> rzones;
    vector<IArea*> izones;

    int length, width;
    const static int MAX_DIM = 50;
    char layout[MAX_DIM][MAX_DIM];
    int pollution[MAX_DIM][MAX_DIM];
// Template functions to implement priority-based logic for zones
    template<class Z>void PriorityImplementation(vector<Z*>);
    template<class Z>void PriorityImplementation2(vector<Z*>);
    template<class Z>void PriorityImplementation3(vector<Z*>);
    template<class Z>void PriorityImplementation4(vector<Z*>);
// Helper functions for setting up and managing city attributes
    void InitializeAreas();
    void PrepareLayout();
    void InitPollution();
    void CreateAdjacency();
    void Pollute();
    void PolluteNode(int, int, int);
    bool adjtoPowerLine(int, int);
    bool haschanged(char[MAX_DIM][MAX_DIM]);// Determines if the layout has changed, used to detect changes after each step

};

