// Standard (system) header files
#include <iostream>
#include <cstdlib>

using namespace std;
#include "SimpleUI.h"
#include "StudentDb.h"



// Main program
int main ()
{
    // TODO: Add your program code here
	cout << "Assignment3_StudentDB started." << endl << endl;
	// declare student DB here
	StudentDb myDB;
	SimpleUI myUI(myDB);

	myUI.run();


	return 0;
}
