#include "lines.h"
#include "default/default.h"
#include "junctions.h"

line* line_list = NULL;

//fixme: line creation exceptions

int add_new_line(int id_start, int id_end, char* line_name,int id){

    line* new_line = (line*) malloc(sizeof(line));

    new_line->id = id;
    new_line->start = id_start;
    new_line->end = id_end;
    new_line->name = strdup(line_name);

    junc* current = hub;

    while(current != workshop){
        if(current->info.id == id_start){
            printf("    <%s>\n",line_name);
            printf("Line From Junction With ID %d Created\n",id_start);
            break;
        }
        current = current->next;
    }

    if(current == NULL){
        printf("No Starting Junction With ID %d Exists\n",id_start);
        return FAILURE;
    }
    
    junc* current2 = hub;

    while(current2 != workshop){
        if(current2->info.id == id_end){
            printf("Line From Junction With ID %d Terminated At Junction With ID %d\n",id_start,id_end);
            break;
        }
        current2 = current2->next;
    }

    if(current2 == NULL){
        printf("No Ending Junction With ID %d Exists\n",id_end);
        return FAILURE;
    }

    if(line_list == NULL){
        line_list = new_line;
        new_line->next = NULL;
    }else{
        line* current_line = line_list;

        while(current_line->next != NULL){
            current_line = current_line->next;
        }

        current_line->next = new_line;
        new_line->next = NULL;
    }

    return SUCCESS;
}

void travel(int line_id, int locomotive_id){
    return;
}

void print_lines(){

    printf("Existing Lines:\n\n");
    
    line* lines = line_list;

    while(lines != NULL){
        printf("<%s>\n",lines->name);
        lines = lines->next;
    }

    return;
}
