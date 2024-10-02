/*
 * Shot.cpp
 *
 *  Created on: Jan 2, 2024
 *      Author: tiena
 */

#include "Shot.h"



Shot::~Shot()
{
	// TODO Auto-generated destructor stub
}

Shot::Shot(GridPosition targetPosition):targetPosition{targetPosition}
{
}

GridPosition Shot::getTargetPosition() const
{
	return this->targetPosition;
}
