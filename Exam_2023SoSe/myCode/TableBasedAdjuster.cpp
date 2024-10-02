#include "TableBasedAdjuster.h"
#include <iostream>
TableBasedAdjuster& TableBasedAdjuster::addBreakpoint(float x, float y) {

    this->breakpoints.emplace(x,y);
    return *this;
}



/**
 * If map breakpoints is empty, returns the value
 * unmodified.
 *
 * Else calculates an adjusted value (a)
 * from the given un-adjusted value (u) passed as
 * argument and the breakpoints with their associated
 * values in the map (bp) as follows (remember that
 * keys in a map are sorted):
 *
 * * Let k_min be the key in bp with the smallest value
 *   and k_max be the key with the largest value. Let the
 *   value associated with any key k_n be v_n.
 *
 * * If u <= k_min then a = v_min - (k_min - u)
 *
 * * If u >= k_max then a = v_max + (u - k_max)
 *
 * * For any two adjacent keys k_n and k_(n+1):
 *   If k_n < u <= k_(n+1) then
 *     a = (u - k_n) / (k_(n+1) - k_n) * (v_(n+1) - v_n) + v_n
 *
 * An example for a function with points (-1, -0,5)
 * and (2, 1) is shown in the exam paper.
 *
 * (15 points)
 */


float TableBasedAdjuster::adjust(float value) const {

    if (this->breakpoints.empty())
    {
        return 0;
    }

    if (value <=this->breakpoints.begin()->first)
    {
        float v_min = this->breakpoints.begin()->second;
        float k_min = this->breakpoints.begin()->first;
        return v_min- (k_min- value);
    }


    if(value >= this->breakpoints.rbegin()->first)
    {
        // Iterator is pointer
        float v_max = this->breakpoints.rbegin()->second;
        float k_max = this->breakpoints.rbegin()->first;
        return v_max + (value - k_max);
    }


    float k_n, v_n, k_n1, v_n1;
    for(auto& breakpoint:this->breakpoints)
    {
        if (value > breakpoint.first)
        {
            k_n = breakpoint.first;
            v_n = breakpoint.second;
        }
        else if (value <= breakpoint.first)
        {
            k_n1 = breakpoint.first;
            v_n1 = breakpoint.second;
            break;
        }
    }
    float result =0;
    result =  (value - k_n) / (k_n1 - k_n) * (v_n1 - v_n) + v_n;

    return result;
    }



