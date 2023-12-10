/**
 * @author Gpap Peaky
 * 
 * @version 9.12.2023
 * 
 * @brief Simple C - library for Location Calculations (Lists/Stacks)
 * 
 * This Library Serves As A Train Junction Line Simulation
*/

double stability_c = 0.275;

struct location{
    double distance_from_hub;
    junc* position;
    int position_id;
};

typedef struct location location;

#include "_macros.h"
#include "junctions.h"

#ifndef LOCATION
#define LOCATION

/**
 * @param current_pos The distance of the junction from the hub
 * @returns a double
 * @related Hub - Junctions (junctions.c)
*/
double calculate_distance(junc* current_pos);

#endif