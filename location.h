/**
 * @author Gpap Peaky
 * 
 * @version 14.12.2023
 * 
 * @brief Simple C - library for Location Calculations (Lists/Stacks)
 * 
 * This Library Serves As A Train Junction Line Simulation
*/

#include "_macros.h"

#ifndef LOCATION
#define LOCATION

#include "junctions.h"

struct location{
    double distance_from_hub;
    junc* position;
    int position_id;
};

typedef struct location local;

/**
 * @param current_pos The distance of the junction from the hub
 * @returns A double representing the money generated (will be subtracted from the cost filed of the locomotive on the specific junc)
 * @related Hub - Junctions (junctions.c)
*/
double calculate_profit(junc* current_pos);

#endif
