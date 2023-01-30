#include <stdio.h>
#include <stdlib.h>
#include "structs.h"


extern member_list *head_member;
extern LL_prodoct *head_product;
extern Linked_lists_of_products_entering_and_exiting *head_transfer_process_product;


void main_menu()
{
    int choice;
    system("cls");
    printf("====>Welcome to Warehouse Management Main menu<====\n\n\t");
    printf("1- New product registration\n\t");
    printf("2- transfer_process\n\t");
    printf("3- Reports\n\t");
    printf("4- Account settings\n\t");
    printf("5- Logout\n\t");
    printf("6- Exit\n");
    printf("==>Please enter the number of your choice : ");
    scanf("%d" , &choice);
    system("cls");
    switch (choice)
    {
      case 1:
        NewProductRegistration();
        break;
     case 2:
        transfer_process();
        break;
      case 3:
        MainMenu();
        break;
      case 4:
        edit_account_information();
        break;
      case 5:
        LogOut();
        break;
      case 6:
        Transferring_member_information_from_the_linked_lists_to_the_file(head_member);
        Transfer_product_data_from_linked_lists_to_the_file(head_product);
        Writing_transfer_product_for_goods_from_the_linked_lists_to_the_file(head_transfer_process_product);
        exit(0);
        printf("\tgood bye ^_^ \n\t");

        break;
      default:
          main_menu();
    }
}
