#include "junctions.h"

junc* hub = NULL;
junc* workshop = NULL;

void init_hub(char* name){

    hub = (junc*)malloc(sizeof(junc));

    hub->info.name = name;
    hub->info.id = 0; //default value

    printf(" - The Train Hub: '%s' Has Been Created\n",name);

    return;
}

void init_workshop(void){
    workshop = (junc*)malloc(sizeof(junc));

    hub->info.name = "Local Locomotives' Workshop";
    hub->info.id = -1; //default value

    printf(" - The Train Workshop Has Been Created\n");

    return;
}

void add_new_junction(int id,char* name){
    
    junc* new_junction = (junc*)malloc(sizeof(junc));

    new_junction->info.id = id;
    new_junction->info.name = malloc(strlen(name) + 1); // +1 for the null terminator
    strcpy(new_junction->info.name, name);

    /* DISTANCE FROM HUB */

    new_junction->info.distance_from_hub = (double) (rand() % DISTANCE_UPPER_BOUND / ((double)(rand() % DISTANCE_UPPER_BOUND) / 1000));

    /*IDEA: READ NAMES FROM NAMES.TXT FILE*/

    new_junction->next = NULL;

    /*LINKING*/

    if(hub == NULL){
        new_junction->next = NULL;
        hub = new_junction;
        workshop = new_junction;
    }else{
        new_junction->next = hub;
        hub = new_junction;
    }

    printf(" - %s,\t\tID: <%d> Created,\t\tDistance from hub: %.2f\n",name,id,new_junction->info.distance_from_hub);

    return;
}

void print_junctions(void){

    junc* current = hub;

    for(;current->info.id != -1; current = current->next){
        printf("%s,\t\tID: <%d>,\t\tDistance from hub: %.2f\n", current->info.name, current->info.id, current->info.distance_from_hub);
    }

    return;
}
