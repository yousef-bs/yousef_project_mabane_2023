#include<stdio.h>
#include<string.h>
#include "structs.h"

extern Linked_lists_of_products_entering_and_exiting *head_transfer_process_product;
extern char The_current_member_name[100];
extern LL_prodoct *head_product;
extern struct new_products product;

void number_of_products(int choice ,int ID_product  , int num)
{
  LL_prodoct *current = head_product;
  while(current != NULL)
  {
    if(current->product.Product_ID == ID_product)
     {
            break;
     }

     current = current->next;

  }

  if(choice == 1)
  {
         current->product.count = current->product.count + num;
  }

  else
  {
        current->product.count = current->product.count - num;
  }

}


void transfer_process()
{
    struct Entry_and_exit_of_the_product_from_the_warehouse transfer_process;
    int choice , y = 0;
        fflush(stdin);
        printf("*~~>Welcome to the Registering The Entry Of Products page\n");
        printf("Product ID : ");
        scanf("%d" , &transfer_process.Product_ID);
        fflush(stdin);
        do
        {
        printf("Transaction Type :\n\t");
        printf("*********************\n\t");
        printf("1.Enter products.\n\t");
        printf("*********************\n\t");
        printf("2.Exit products.\n\t");
        printf("*********************\n\t");
        printf("*~~>please enter the number of your choice : ");
        scanf("%d" , &choice);
        switch (choice)
        {
        case 1:
            strcpy(transfer_process.transfer_processType, "Enter");
            y = 0;
            break;
        case 2:
            strcpy(transfer_process.transfer_processType, "Exit");
            y = 0;
            break;
        default:
            printf("wrong choice!!! :-(");
            y = 1;
            break;
        }
        }while (y);
        fflush(stdin);
        printf("Number Of Products In This Transaction : ");
        scanf("%d" , &transfer_process.count_tra);
        number_of_products(choice , transfer_process.Product_ID , transfer_process.count_tra);
        fflush(stdin);
        printf("transfer_process Date : ");
        scanf("%s" , transfer_process.transfer_processDate);
        fflush(stdin);

        strcpy(transfer_process.member_name, The_current_member_name);

        Send_transfer_product_from_the_file_to_the_linked_lists(head_transfer_process_product, transfer_process);
}
