// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
// #include "CFraction.h"
#include "MeasurementDb.h"
#include "Temperature.h"
#include "Humidity.h"
#include <fstream>

// Main program
int main ()
{
    // TODO: Add your program code here
	cout << "Temperature started." << endl << endl;
	cout << "Nguyen Tien Anh ha 1127956." << endl << endl;
    auto temp1 = std::make_shared<Temperature>(8*60, -3.0);
    auto humid1 = std::make_shared<Humidity>(9*60+30, 80.0);
    auto temp2 = std::make_shared<Temperature>(10*60+5, 20.0);
    auto temp3 = std::make_shared<Temperature>(90, 22.0);
    // use timestamp here

    MeasurementDb db;
    /*
     * It would be bad idea to use measurement1 as sample values because we create raw pointer here to use polymorphism and those are not deallocating automatically that could
     * lead to error segementation
     */
    db.addMeasurement("Kitchen",temp1);
    db.addMeasurement("Kitchen",humid1);
    db.addMeasurement("Bath",temp3);
    db.print();

//	std::ifstream input("test.txt");
//	db.load(input);
//	db.print();
	std::string location;
	std::shared_ptr<Measurement> pTemp;
	cout << db.maximumTemperature(location, pTemp) << std::endl;
	cout << pTemp<< "correct"<< temp3 << endl;
    return 0;
}
