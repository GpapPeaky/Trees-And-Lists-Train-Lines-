/**
 * @author Gpap Peaky
 * 
 * @version 9.12.2023
 * 
 * @brief Simple C - library for Lines (Lists/Stacks)
 * 
 * The Library Include Declarations Of All Line Related Methods
*/

struct locomotive_line{
    int id;
    int start;
    int end;
    char* name;
    struct locomotive_line* next;
};

typedef struct locomotive_line line;

#include "_macros.h"

#ifndef LINES
#define LINES

extern line* line_list;

/**
 * Adds a new line onto the list
 * 
 * @param id_end Ending junction id
 * @param id_start Starting junction id
 * @param line_name Name of the line
 * @param line_id Id of the line
 * @post The line has been created
 * @pre The junctions are valid
 * @returns SUCCESS
 * @returns FAILURE
 * @related line_list
*/
int add_new_line(int id_start, int id_end, char* line_name,int line_id);

/**
 * A locomotive gets to travel somewhere
 * 
 * @param line_id The line in which the locomotive travels
 * @param locomotive_id The locomotive select to travel
 * @pre Both a line and a locomotive with their respective ids should exist
 * @pre The locomotive should be at the line start location
 * @post The locomotive's location is currently at the end of the line
 * @related line_list
 * @relatedalso location struct
*/
void travel(int line_id,int locomotive_id);
/* [IDEA] : add locomotive struct */

/**
 * Prints the already created lines
 * 
 * @post Correct prints
*/
void print_lines();

#endif //LINES
