#include "main.h"

/**
 * @author Gpap Peaky
 * 
 * @version 8/12/2023
 * 
 * @brief Main Junction Function
 * 
 * @test Functions
*/

/**
 * Prints The Control Panel Info
*/
void info_menu(void);

int main(void){

    srand(12069); /* Change Seed */

    char input[10]; /* Buffer 10 characters */
    char junc_name[1000]; /* Buffer 1000 characters */
    char hub_name[1000]; /* Buffer 1000 characters */
    char line_name[1000]; /* Buffer 1000 characters */
    int loco_id,junc_id,junc_s_id,junc_e_id,line_id;
    loco_t type;

    /*____________________________________________________________________________________________________________*/

    printf("A new hub is to be built, what name would you like it to have?\n");
    scanf("%[^\n]",hub_name);

    init_hub(hub_name);
    init_workshop();

    while(1){

        printf("\n");

        printf("What Would You Like To Do:\n");
        info_menu();
        scanf("%s",input);

        switch(*input){
            case 'L':
                print_lines();
                new_scope();
                break;
            case 'J':
                print_junctions();
                new_scope();
                break;
            case 'T':
                print_locomotives();
                new_scope();
                break;
            case 'A':
                printf("Locomotive Id: ");
                scanf("%d",&loco_id);

                printf("Locomotive type: ");
                scanf("%u",&type);

                assign_locomotive(loco_id,type);
                new_scope();
                break;
            case 'N':
                printf("Junction Id: ");
                scanf("%d",&junc_id);
                getchar(); // Consume the newline character

                printf("Junction Name: ");
                fgets(junc_name, sizeof(junc_name), stdin);
                junc_name[strcspn(junc_name, "\n")] = '\0'; // Remove the trailing newline if present

                add_new_junction(junc_id,junc_name);
                new_scope();
                break;
            case 'P':
                printf("Junction Start Id: ");
                scanf("%d",&junc_s_id);

                printf("Junction End Id: ");
                scanf("%d",&junc_e_id);

                getchar(); // Consume the newline character

                printf("Line Name: ");
                fgets(line_name, sizeof(line_name), stdin);
                line_name[strcspn(line_name, "\n")] = '\0'; // Remove the trailing newline if present

                printf("Line Id: ");
                scanf("%d",&line_id);

                add_new_line(junc_s_id,junc_e_id,line_name,line_id);
                new_scope();
                break;
            case 'Q':
                __DEBUG();
                exit(SUCCESS);
            case 'I':
                info_menu();
                new_scope();
                break;
            default:
                printf("Wrong Input, Choose Again...\n");
                continue;
        }   
    }

    return SUCCESS;
}

/*____________________________________________________________________________________________________________*/

void info_menu(void){
    printf("    Commands:\n");
    printf("L - Print Lines\n");
    printf("J - Print Junctions\n");
    printf("T - Print Locomotives\n");
    printf("A - Assign A New Locomotive\n");
    printf("N - Create A New Junction\n");
    printf("P - Create A New Line Between 2 Junctions\n");
    printf("Q - Quit\n");
    printf("I - Info Menu\n");
}
