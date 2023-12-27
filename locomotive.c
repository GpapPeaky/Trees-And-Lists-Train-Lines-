#include "locomotive.h"

loco* root = NULL;

const char* locomotive_type_print[] = {"DIESEL","ELECTRIC","STEAM_ENGINE"};

void in_order(loco* root){
    if(root == NULL) return;

    in_order(root->left);
    visit(root);
    in_order(root->right);
}

void visit(loco* node){
    printf("<%d> <%s>\n",node->id,locomotive_type_print[node->type - 1]);
}

void assign_locomotive(int id, loco_t locomotive_type, loco** root_ptr){
    
    loco* train = (loco*) malloc(sizeof(loco));

    train->l_info.passenger_cap = 100;
    train->l_info.passengers = 0;
    train->l_info.cost = 1;
    train->id = id;
    train->type = locomotive_type;
    train->l_info.current_junction = hub; /* starts at the hub, updates with each travel */
    train->left = NULL;
    train->right = NULL;

    loco* find_position = *root_ptr;
    loco* prev_position = NULL;

    if(root == NULL){
        *root_ptr = train; /* First Insertion */
    }else{
        while(find_position != NULL){
            prev_position = find_position;

            if(find_position->id > id){
                find_position = find_position->left;
            }else{
                find_position = find_position->right;
            }
        }

        if (prev_position->id > id){
            prev_position->left = train;
        }else{
            prev_position->right = train;
        }
    }

    printf("    %s LOCOMOTIVE\n",locomotive_type_print[train->type - 1]);
    printf("ID:\t%d\n",train->id);
    printf("Cap:\t%d\n",train->l_info.passenger_cap);
    printf("Cost:\t%d\n",train->l_info.cost);

    return;
}

void print_locomotives(){
    in_order(root);
    return;
}

	// if(new_releases == NULL){ /* If empty leave it here */
	// 	new_releases = new_movie; /* Assign node to root */
	// }else{

	// 	current = new_releases; /* Assign to the previosuly created root */

	// 	while(current != NULL){
	// 		prev = current;
	// 		if(current->movieID > movieID){
	// 			current = current->lc;
	// 		}else{
	// 			current = current->rc;
	// 		}
	// 	}

	// 	if(prev->movieID > new_movie->movieID){
	// 		prev->lc = new_movie;
	// 	}else{
	// 		prev->rc = new_movie;
	// 	}
	// }