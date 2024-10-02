// Standard (system) header files
#include <iostream>
#include <cstdlib>

#include "Thermostats.h"

using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
int main ()
{
    // TODO: Add your program code here
	cout << "Ex3_HeatController started." << endl << endl;
	Thermostats myThermostat;
	myThermostat.run();
	return 0;
}
