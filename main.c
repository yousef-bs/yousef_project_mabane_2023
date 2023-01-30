#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

member_list *head_member = NULL;
LL_prodoct *head_product = NULL;
Linked_lists_of_products_entering_and_exiting *head_transfer_process_product = NULL;

struct members_data member;
struct new_products product;
struct Entry_and_exit_of_the_product_from_the_warehouse transfer_process;


int recognition = 0;
char The_current_member_name[100];
int debuging = 1;


void debug(char msg[], int sleep_time){
    if (debuging)
     {
        printf("\n\n === %s ==== \n\n", msg);
        sleep(sleep_time);
     }
}

void main()
{
    int action_member;
    
    Take_member_data_from_the_file();
    while (1)
    {
        if (recognition)
        {
            main_menu();
        }else{
            LoginPage();
        }
    }

}
