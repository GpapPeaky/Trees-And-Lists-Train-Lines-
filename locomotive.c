#include "locomotive.h"

const char* locomotive_type_print[] = {"DIESEL","ELECTRIC","STEAM_ENGINE"};

void assign_locomotive(int id, loco_t locomotive_type){
    
    loco* train = (loco*) malloc(sizeof(loco));

    train->l_info.passenger_cap = 100;
    train->l_info.passengers = 0;
    train->l_info.cost = 1;
    train->id = id;
    train->type = locomotive_type;
    train->l_info.current_junction = hub; /* starts at the hub, updates with each travel */

    printf("    %s LOCOMOTIVE\n",locomotive_type_print[train->type - 1]);
    printf("ID:\t%d\n",train->id);
    printf("Cap:\t%d\n",train->l_info.passenger_cap);
    printf("Cost:\t%d\n",train->l_info.cost);

    return;
}

void print_locomotives(){
    return;
}