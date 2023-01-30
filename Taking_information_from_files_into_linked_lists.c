#include<stdio.h>
#include<stdlib.h>
#include "structs.h"

extern struct members_data member;
extern member_list *head_member;


extern Linked_lists_of_products_entering_and_exiting *head_transfer_process_product;
// extern struct Entry_and_exit_of_the_product_from_the_warehouse transfer_process;


extern struct new_products product;
extern LL_prodoct *head_product;

void Transfer_accounts_from_files_to_linked_lists(member_list *head, struct members_data member)
{
    member_list *current = head;
    if(!current)
    {
        head_member = (member_list *) malloc(sizeof(member_list));
        head_member->member = member;
        head_member->next = NULL;
        return;
    }
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = (member_list *) malloc(sizeof(member_list));
    current->next->member = member;
    current->next->next = NULL;
}
void Take_member_data_from_the_file()
{

   size_t checked_end_of_file;
   FILE *AccountDataFile;
   AccountDataFile = fopen("members_data.txt" , "r");
   checked_end_of_file = fread(&member , sizeof(struct members_data) , 1 , AccountDataFile);
   if (checked_end_of_file)
   {
       head_member = (member_list *) malloc(sizeof(member_list));
       head_member->member = member;
       head_member->next = NULL;
   }
   while (checked_end_of_file)
   {
       checked_end_of_file = fread(&member , sizeof(struct members_data) , 1 , AccountDataFile);
       if(checked_end_of_file)
       {
           Transfer_accounts_from_files_to_linked_lists(head_member , member);
       }
   }
}
void Transferring_member_information_from_the_linked_lists_to_the_file(member_list *head)
{
    
    FILE *file;
    file = fopen("members_data.txt" , "w");
    member_list *current = head;
    while (current != NULL)
    {
        fwrite(&current->member , sizeof(struct members_data) , 1 , file);
        current = current->next;
    }
    fclose(file);
}



/// prodcut get and set file

void Send_the_product_from_a_file_to_the_linked_lists(LL_prodoct *head , struct new_products product)
{
   LL_prodoct *current = head;
   if(!current)
   {
        head_product = (LL_prodoct *) malloc(sizeof(LL_prodoct));
        head_product->product = product;
        head_product->next = NULL;
        return;
   }
   while (current->next != NULL)
   {
       current = current->next;
   }
   current->next = (LL_prodoct *) malloc(sizeof(LL_prodoct));
   current->next->product = product;
   current->next->next = NULL;
}

void Get_product_information_from_the_file()
{
  size_t checked_end_of_file;
  FILE *file;
  file = fopen("new_products.txt" , "r");
  checked_end_of_file = fread(&product , sizeof(struct new_products) , 1 , file);
  if (checked_end_of_file)
  {
       head_product = (LL_prodoct *) malloc(sizeof(LL_prodoct));
       head_product->product = product;
       head_product->next = NULL;
  }
  while (checked_end_of_file)
  {
      checked_end_of_file = fread(&product , sizeof(struct new_products) , 1 , file);
      if(checked_end_of_file)
      {
          Send_the_product_from_a_file_to_the_linked_lists(head_product , product);
      }
  }
  fclose(file);
}
void Transfer_product_data_from_linked_lists_to_the_file(LL_prodoct *head)
{
    FILE *file;
    file = fopen("new_products.txt" , "w");
    LL_prodoct *current = head;
    while (current != NULL)
    {
        sleep(1);
        fwrite(&current->product , sizeof(struct new_products) , 1 , file);
        current = current->next;
    }
    fclose(file);
}


// tarnsaction get data from file functions


void import_transfer_product_data_from_file()
{
 
  size_t checked_end_of_file;
  FILE *file;
  file = fopen("EntryAndExityProducts.txt" , "r");
  struct Entry_and_exit_of_the_product_from_the_warehouse transfer_process;

  checked_end_of_file = fread(&transfer_process , sizeof(struct Entry_and_exit_of_the_product_from_the_warehouse) , 1 , file);
  
  if (checked_end_of_file)
  {
    
       head_transfer_process_product = (Linked_lists_of_products_entering_and_exiting *) malloc(sizeof(Linked_lists_of_products_entering_and_exiting));
       head_transfer_process_product->transfer_process = transfer_process;
       head_transfer_process_product->next = NULL;
  }
 
  while (checked_end_of_file)
  {
    
      checked_end_of_file = fread(&transfer_process , sizeof(struct Entry_and_exit_of_the_product_from_the_warehouse) , 1 , file);
      if(checked_end_of_file)
      {
        
          Send_transfer_product_from_the_file_to_the_linked_lists(head_transfer_process_product , transfer_process);
      }
  }
 
}

void Send_transfer_product_from_the_file_to_the_linked_lists(Linked_lists_of_products_entering_and_exiting *head, struct Entry_and_exit_of_the_product_from_the_warehouse transfer_process)
{
   Linked_lists_of_products_entering_and_exiting *current = head;
   if(!current)
    {
        head_transfer_process_product = (Linked_lists_of_products_entering_and_exiting *) malloc(sizeof(Linked_lists_of_products_entering_and_exiting));
        head_transfer_process_product->transfer_process = transfer_process;
        head_transfer_process_product->next = NULL;
        return;
    }
   while (current->next != NULL)
   {
       current = current->next;
   }
   current->next = (Linked_lists_of_products_entering_and_exiting *) malloc(sizeof(Linked_lists_of_products_entering_and_exiting));
   current->next->transfer_process = transfer_process;
   current->next->next = NULL;
}


void Writing_transfer_product_for_goods_from_the_linked_lists_to_the_file(Linked_lists_of_products_entering_and_exiting *head)
{
    FILE *file;
    file = fopen("EntryAndExityProducts.txt" , "w");
    Linked_lists_of_products_entering_and_exiting *current = head;
    while (current != NULL)
    {
        fwrite(&current->transfer_process, sizeof(struct Entry_and_exit_of_the_product_from_the_warehouse) , 1 , file);
        current = current->next;
    }
    fclose(file);
}

// // function for clean RAM

// void CleanRAM()
// {

//     while(current != NULL)
//     {
//         free(curent);
//         curent = curent->next;
//     }
// }
