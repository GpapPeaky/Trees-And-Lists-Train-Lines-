/**
 * @author Gpap Peaky
 * 
 * @version 9.12.2023
 * 
 * @brief Simple C - library for Locomotives (Lists/Stacks)
 * 
 * This Library Serves As A Locomotive Struct Pointer Library
*/

enum locomotive_t{
    DIESEL = 1,
    ELECTRIC = 2,
    STEAM_ENGINE = 3,
};

typedef enum locomotive_t loco_t;

struct locomotive_info{
    int passengers;
    int passenger_cap;
    int cost;
};

typedef struct locomotive_info loco_info;

struct locomotive{
    loco_info l_info;
    int id;
    loco_t type;
};

typedef struct locomotive loco;

#include "_macros.h"

#ifndef LOCOMOTIVES
#define LOCOMOTIVES

/**
 * For Enum Printing
 * 
 * @enum DIESEL, ELECTRIC, STEAM_ENGINE 
*/
extern const char* locomotive_type_print[];

/**
 * Creates a new locomotive
 * 
 * @param id Train's id
 * @param type Enumerator for the train's type
*/
void assign_locomotive(int id,loco_t type);

/**
 * Prints the locomotives list
 * 
 * @post Correct prints
*/
void print_locomotives(void);

#endif /* LOCOMOTIVES */
