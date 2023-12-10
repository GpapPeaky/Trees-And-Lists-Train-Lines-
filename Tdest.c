#include <stdio.h>
#include "junctions.h"

/*location field test*/

double stability_c = 0.275;

struct location{
    double distance_from_hub;
    junc* position;
    int position_id;
};

typedef struct location location;

struct test{
    location current_position;
};

typedef struct test location_test;

typedef struct balance{
    double profit;
}balance;

int main(void){

    add_new_junction(1,"Knossos");

    location_test tester;

    tester.current_position.distance_from_hub = 100.32;
    tester.current_position.position_id = 1;

    junc* current = hub;

    while(current != NULL){
        if(current->info.id == 1){
            tester.current_position.position = current;
            printf("tester location set at the junction with name %s and id: %d\n",current->info.name,current->info.id);
            break;
        }
        current = current->next;
        printf("move next junction\n");
    }

    printf("%d\n",tester.current_position.position_id);
    printf("%p\n",tester.current_position.position);


    return 0;
}