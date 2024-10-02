/*
 * Shot.h
 *
 *  Created on: Jan 2, 2024
 *      Author: tiena
 */

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

/**
 * @class Shot
 * @brief Represents a shot taken in a game
 */
class Shot
{
private:
    GridPosition targetPosition; //!< The target position on the grid.

public:
    /**
     * @brief Constructor for the Shot class.
     * @param targetPosition The target position on the grid for the shot.
     */
    Shot(GridPosition targetPosition);

    /**
     * @brief Gets the target position of the shot.
     * @return The target position as a GridPosition.
     */
    GridPosition getTargetPosition() const;

    /**
     * @brief Destructor for the Shot class.
     */
    virtual ~Shot();

    /**
     * @brief Enumeration representing the impact of a shot.
     *
     * - NONE: No impact.
     * - HIT: The shot hit a target.
     * - SUNKEN: The shot led to the sinking of a target.
     */
    enum Impact
    {
        NONE,  ///< No impact.
        HIT,   ///< The shot hit a target.
        SUNKEN ///< The shot led to the sinking of a target.
    };
};

#endif /* SHOT_H_ */
