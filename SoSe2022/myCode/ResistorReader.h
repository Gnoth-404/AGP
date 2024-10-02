/*
 * ResistorReader.h
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#ifndef RESISTORREADER_H_
#define RESISTORREADER_H_
#include <map>
#include "ResistorConection.h"

class ResistorReader
{
public:
	ResistorReader();
	void read(std::istream& in, std::map<std::string, ResistorPtr>& found);
};

#endif /* RESISTORREADER_H_ */
