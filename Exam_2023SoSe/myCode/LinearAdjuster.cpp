#include "LinearAdjuster.h"

LinearAdjuster::LinearAdjuster(float factor, float offset):factor{factor}, offset{offset}
{
}
/**
 * Calculates the result as "value * factor + offset". (2 points)
 */
float LinearAdjuster::adjust(float value) const {
    return value*factor +offset;
}
