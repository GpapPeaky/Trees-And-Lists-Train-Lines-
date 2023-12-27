/**
 * @author Gpap Peaky
 * 
 * @version 27.12.2023
 * 
 * @brief Simple C - library for Locomotives (Lists/Stacks)
 * 
 * This Library Serves As A Locomotive Struct Pointer Library
*/

#include "_macros.h"

#ifndef LOCOMOTIVES
#define LOCOMOTIVES

#include "junctions.h"

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
    junc* current_junction;
};

typedef struct locomotive_info loco_info;

struct locomotive{
    loco_info l_info;
    int id;
    loco_t type;
    struct locomotive* left;
    struct locomotive* right;
};

typedef struct locomotive loco;

/**
 * For Enum Printing
 * 
 * @enum DIESEL, ELECTRIC, STEAM_ENGINE 
*/
extern const char* locomotive_type_print[];

extern loco* root; /* Locomotives' Tree Root */

/**
 * Creates a new locomotive
 * 
 * @param id Train's id
 * @param type Enumerator for the train's type
 * @param root_ptr Pointer to the root of the locomotives' tree
*/
void assign_locomotive(int id,loco_t type, loco** root_ptr);

/**
 * In-order traversal of the locomotives tree
 * 
 * @param root The root of the locomotives' tree
*/
void in_order(loco* root);

/**
 * @param node Node to visit
*/
void visit(loco* node);

/**
 * Prints the locomotives list
 * 
 * @post Correct prints
*/
void print_locomotives(void);

#endif /* LOCOMOTIVES */
