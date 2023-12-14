/**
 * @author Gpap Peaky
 * 
 * @version 14.12.2023
 * 
 * @brief Simple C - library for Junctions (Lists/Stacks)
 * 
 * This Library Serves As A Train Junction Line Simulation
*/

#include "_macros.h"

typedef struct junction junc; /* Correct Field */

#ifndef JUNCTIONS
#define JUNCTIONS

struct junc_info{
    int id;
    char* name;
};

typedef struct junc_info info;

struct junction{
    info info;
    struct junction* next;
};

extern junc* hub;
extern junc* workshop;

/**
 * Initialises The Hub
 * 
 * @pre No hub has been initialised
 * @post A hub has been created
 * @param name Give a name to the hub
*/
void init_hub(char* name);

/**
 * Initialises The Workshop 
 * 
 * @pre No workshop has been initialised
 * @post A workshop has been created
*/
void init_workshop(void);

/**
 * Adds A New Junction
 * 
 * @pre No junction with the same id has been initialised
 * @post A junction has been created
 * @param name Give a name to the junction
 * @param id Junction id
*/
void add_new_junction(int id,char* name);

/**
 * Prints All Junctions
 * 
 * @post Correct prints
*/
void print_junctions(void);

#endif /*JUNCTIONS*/
