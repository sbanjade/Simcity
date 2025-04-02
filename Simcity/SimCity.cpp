#include <iostream>
#include <fstream>
#include "UrbanSimulation.h"

using namespace std;

int main()
{
    string config_filename;
    bool isdiff;
    cout << "Beginning simulation" << endl; // Display initial message to indicate simulation start
    cout << "Please enter the name of the configuration file: ";  // Prompt user for configuration file name
    cin >> config_filename;

    UrbanSimulation city(config_filename);
    
    cout << "Initial Region State" << endl;
    city.display();

    for (int s = 1; s <= city.time_limit; s++) {
        
        isdiff = city.RunSimulationStep(s);

        if (!isdiff)break;
        cout << endl;
    }
    cout << "Final Region State" << endl; // Display the final state of the region after the simulation ends
    city.display();

    cout << "Pollution" << endl;
    city.displayPollution();
// Display the total population of each zone type in the entire region
    cout << "The total populations for the region are :" << endl;
    cout << "Residential: " << city.getRPopulation(0, 0, city.getWidth() - 1, city.getLength() - 1) << endl;
    cout << "Industrial: " << city.getIPopulation(0, 0, city.getWidth() - 1, city.getLength() - 1) << endl;
    cout << "Commercial: " << city.getCPopulation(0, 0, city.getWidth() - 1, city.getLength() - 1) << endl;
        
    cout << "The total amount of pollution in the region is " 
        << city.getTotalPollution(0, 0, city.getWidth() - 1, city.getLength() - 1) 
        << " units." << endl;
    // Prompt user to enter coordinates for a specific area to get detailed information

    cout << "Please enter the diagonal corners of the area you wish to have more information about. (";
    cout<<"MinX = 0, MinY = 0, MaxX = "<<city.getLength() - 1<<", MaxY = "<<city.getWidth() - 1<<")"<<endl;

    int x1, y1, x2, y2;
    cout << "X1: "; cin >> x1;
    cout << "Y1: "; cin >> y1;
    cout << "X2: "; cin >> x2;
    cout << "Y2: "; cin >> y2;
    // Display the population information for the specified area

    cout << "The total populations for the requested area are: " << endl;
    cout << "Residential: " << city.getRPopulation(x1, y1, x2, y2) << endl;
    cout << "Industrial: " << city.getIPopulation(x1, y1, x2, y2) << endl;
    cout << "Commercial: " << city.getCPopulation(x1, y1, x2, y2) << endl;

    cout << "The total amount of pollution for the requested area is "
        << city.getTotalPollution(x1, y1, x2, y2) << " units." << endl;
    // Indicate the end of the simulation

    cout << "Simulation Complete" << endl;
    return 0;
}

