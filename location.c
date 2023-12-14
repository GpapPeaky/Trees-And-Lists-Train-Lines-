#include "location.h"

double calculate_profit(junc* current){
    return STABILITY_C * current->info.pos->distance_from_hub;
}
