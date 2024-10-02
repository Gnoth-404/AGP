// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
// #include "CFraction.h"
#include "ResistorPart.h"
#include "SerialResistorConnection.h"
#include "ParallelResistorConnection.h"
#include "ResistorReader.h"
#include <fstream>
// Main program
int main ()
{
    // TODO: Add your program code here
	cout << "SoSe2022 started." << endl << endl;
	ResistorPart r1("R1",42, 0.5);

	auto r3 = ResistorPtr( new ResistorPart("R3",1000, 0.1));
	auto r4 = ResistorPtr( new ResistorPart("R4",4700, 0.1));


	auto r6 = ResistorPtr( new ResistorPart("R6",1000, 0.1));

	auto r7 = ResistorPtr( new ResistorPart("R7",4700, 0.1));


	SerialResistorConnection r2("R2");

	ParallelResistorConnection r5("R5");
	r2 +=r3;
	r2 += r4;

	std::cout <<r2.toString() << std::endl;
	r5 += r6;
	r5 += r7;
	std::cout <<r5.toString() << std::endl;
	ofstream out("text.txt");
	r2.write(out);
	out.close();

	ifstream in("text.txt");
	ResistorReader reader;
	std::map<std::string, ResistorPtr> found;
	reader.read(in, found);
	cout << found.size() << endl;
	return 0;
}
