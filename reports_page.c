#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

extern struct new_products product;
extern LL_prodoct *head_product;

extern member_list *head_member;
extern struct members_data member;

extern Linked_lists_of_products_entering_and_exiting *head_transfer_process_product;
 extern struct Entry_and_exit_of_the_product_from_the_warehouse transfer_process;



void The_quantity_of_each_type_in_the_warehouse(LL_prodoct *head_product)
{
    int count = 0;
    LL_prodoct *current = head_product;
    while(current != NULL)
    {
        count++;
        printf("\n%d." , count);
        printf("\n\t------------------------------------------------------\n\t");
        printf("\n\tProduct_ID : %d" , current->product.Product_ID);
        printf("\n\t------------------------------------------------------\n\t");
        printf("\n\tname_product : %s" , current->product.name_product);
        printf("\n\t------------------------------------------------------\n\t");
        printf("\n\tcount : %d" , current->product.count);
        printf("\n\t------------------------------------------------------\n\t");
        printf("\n\tProduct_brand : %s" , current->product.Product_brand);
        printf("\n\t------------------------------------------------------\n\t");
        printf("\n\tProduct_model : %s" , current->product.Product_model);
        printf("\n\t------------------------------------------------------\n\t");
        printf("\n\tProduct_price : %s" , current->product.Product_price);
        printf("\n\t------------------------------------------------------\n\t");
        printf("\n\tProduct_explanations : %s" , current->product.Product_explanations);
        printf("\n\t------------------------------------------------------\n\t");
        current = current->next;


    }
     sleep(6);
}

void List_of_products_of_which_there_are_more_than_the_specified_quantity(LL_prodoct *head_product)
{
     LL_prodoct *current = head_product;
     int number , count = 0;
     printf("Please enter the number to print products whose quantity more than the entered number : ");
     scanf("%d" , &number);

     while (current != NULL)
     {
        if(current->product.count >= number )
         {
            count++;
        printf("\n%d." , count);
        printf("\n\tProduct_ID : %d" , current->product.Product_ID);
        printf("------------------------------------------------------\n\t");
        printf("\n\tname_product : %s" , current->product.name_product);
        printf("------------------------------------------------------\n\t");
        printf("\n\tcount : %d" , current->product.count);
        printf("------------------------------------------------------\n\t");
        printf("\n\tProduct_brand : %s" , current->product.Product_brand);
        printf("------------------------------------------------------\n\t");
        printf("\n\tProduct_model : %s" , current->product.Product_model);
        printf("------------------------------------------------------\n\t");
        printf("\n\tProduct_price : %s" , current->product.Product_price);
        printf("------------------------------------------------------\n\t");
        printf("\n\tProduct_explanations : %s" , current->product.Product_explanations);
        printf("------------------------------------------------------\n\t");

         }

         current = current->next;

     }
     sleep(6);

}

void List_of_products_of_which_there_is_less_than_the_specified_quantity(LL_prodoct *head_product)
{
     LL_prodoct *current = head_product;
     int number , count = 0;
     printf("Please enter the number to print products whose quantity less than the entered number : ");
     scanf("%d" , &number);

     while (current != NULL)
     {
        if(current->product.count <= number )
         {
            count++;
            printf("\n%d." , count);

            printf("\n\tProduct_ID : %d" , current->product.Product_ID);
            printf("------------------------------------------------------\n\t");
            printf("\n\tname_product : %s" , current->product.name_product);
            printf("------------------------------------------------------\n\t");
            printf("\n\tcount : %d" , current->product.count);
            printf("------------------------------------------------------\n\t");
            printf("\n\tProduct_brand : %s" , current->product.Product_brand);
            printf("------------------------------------------------------\n\t");
            printf("\n\tProduct_model : %s" , current->product.Product_model);
            printf("------------------------------------------------------\n\t");
            printf("\n\tProduct_price : %s" , current->product.Product_price);
            printf("------------------------------------------------------\n\t");
            printf("\n\tProduct_explanations : %s" , current->product.Product_explanations);
            printf("------------------------------------------------------\n\t");

         }

         current = current->next;

     }
     sleep(6);

}

void The_value_of_all_products_in_the_warehouse_is_in_riyals(LL_prodoct *head_product)
{
     LL_prodoct *current = head_product;
     int  price , sum = 0 ;
    while (current != NULL)
    {
         price = atoi(current->product.Product_price);
         sum = sum + (price * current->product.count);
         current = current->next;

    }

    printf("The price of all products is in riyals = %d" , sum);
     sleep(5);


}

void The_value_of_a_specific_product_in_riyals(LL_prodoct *head_product)
{
        LL_prodoct *current = head_product;
        int price;
        char product_name[50];
        printf("Enter the product name :");
         scanf("%s" , product_name);
        while ( current != NULL )
           {
             if (strcmp(current->product.name_product , product_name) == 0)
              {
                 price = atoi(current->product.Product_price);
                 printf("The price for (%s) in riyals = %d\n" , current->product.name_product , price);
                 printf("\n\t----------------------------------------------------------------------\n");
                 price = price * current->product.count;
                 printf("The price for all (%s) in riyals = %d\n" , current->product.name_product , price );
              }
             current = current->next;
            }
            sleep(5);

}

void The_number_of_products_entered_on_a_specific_date()
{
    struct Date
    {
        int year;
        int month;
        int day;
    };
    struct Date date[3];
    LL_prodoct *current = head_product;
    char First_Date[100] , Last_Date[100] , Product_Name[100] , Date_Transection[100];
    int count = 0 , sum = 0;
    printf("Please enter a product name  : ");
    scanf("%s" , Product_Name);
    printf("Please enter a First Date (ex: yyyy/mm/dd) : ");
    scanf("%s" , First_Date);
    date[0].year = atoi(strtok(First_Date , "/"));
    date[0].month = atoi(strtok(NULL , "/"));
    date[0].day = atoi(strtok(NULL , "/"));
    printf("Please enter a Last Date (ex: yyyy/mm/dd) : ");
    scanf("%s" , Last_Date);
    date[1].year = atoi(strtok(Last_Date , "/"));
    date[1].month = atoi(strtok(NULL , "/"));
    date[1].day = atoi(strtok(NULL , "/"));
    while (current != NULL)
    {
        if (strcmp(current->product.name_product , Product_Name) == 0)
        {
            Linked_lists_of_products_entering_and_exiting *current_1 = head_transfer_process_product;
            while (current_1 != NULL)
            {
                if ((current_1->transfer_process.Product_ID == current->product.Product_ID) && (strcmp(current_1->transfer_process.transfer_processType , "Enter") == 0))
                {
                    strcpy(Date_Transection , current_1->transfer_process.transfer_processDate);
                    date[2].year = atoi(strtok(Date_Transection , "/"));
                    date[2].month = atoi(strtok(NULL , "/"));
                    date[2].day = atoi(strtok(NULL , "/"));
                    if ((date[0].year <= date[2].year) && (date[1].year >= date[2].year))
                    {
                        if ((date[0].month <= date[2].month) || (date[1].month >= date[2].month))
                        {
                            if ((date[0].day <= date[2].day) || (date[1].day >= date[2].day))
                            {
                                count++;
                                sum += current_1->transfer_process.count_tra;
                            }
                        }
                    }
                }
                current_1 = current_1->next;
            }
        }
        current = current->next;
    }

    printf("\nThe %s was inserted %d times during the time period between %d/%d/%d and %d/%d/%d\n" , Product_Name , count , date[0].year , date[0].month , date[0].day , date[1].year , date[2].month , date[1].day);

    printf("\nThe number of pieces entered during this time period : %d\n" , sum);

    printf("\n\nPlease enter any thing to exit this page.....");

    getch();
}

void The_number_of_products_that_came_out_on_a_specific_date()
{
    struct Date
    {
        int year;
        int month;
        int day;
    };
    struct Date date[3];
    LL_prodoct *current = head_product;
    char First_Date[100] , Last_Date[100] , Product_Name[100] , Date_Transection[100];
    int count = 0 , sum = 0;
    printf("Please enter a product name  : ");
    scanf("%s" , Product_Name);
    printf("Please enter a First Date (ex: yyyy/mm/dd) : ");
    scanf("%s" , First_Date);
    date[0].year = atoi(strtok(First_Date , "/"));
    date[0].month = atoi(strtok(NULL , "/"));
    date[0].day = atoi(strtok(NULL , "/"));
    printf("Please enter a Last Date (ex: yyyy/mm/dd) : ");
    scanf("%s" , Last_Date);
    date[1].year = atoi(strtok(Last_Date , "/"));
    date[1].month = atoi(strtok(NULL , "/"));
    date[1].day = atoi(strtok(NULL , "/"));
    while (current != NULL)
    {
        if (strcmp(current->product.name_product , Product_Name) == 0)
        {
            Linked_lists_of_products_entering_and_exiting *current_1 = head_transfer_process_product;
            while (current_1 != NULL)
            {
                if ((current_1->transfer_process.Product_ID == current->product.Product_ID) && (strcmp(current_1->transfer_process.transfer_processType , "Exit") == 0))
                {
                    strcpy(Date_Transection , current_1->transfer_process.transfer_processDate);
                    date[2].year = atoi(strtok(Date_Transection , "/"));
                    date[2].month = atoi(strtok(NULL , "/"));
                    date[2].day = atoi(strtok(NULL , "/"));
                    if ((date[0].year <= date[2].year) && (date[1].year >= date[2].year))
                    {
                        if ((date[0].month <= date[2].month) || (date[1].month >= date[2].month))
                        {
                            if ((date[0].day <= date[2].day) || (date[1].day >= date[2].day))
                            {
                                count++;
                                sum += current_1->transfer_process.count_tra;
                            }
                        }
                    }
                }
                current_1 = current_1->next;
            }
        }
        current = current->next;
    }

    printf("\nThe %s was removed %d times during the time period between %d/%d/%d and %d/%d/%d\n" , Product_Name , count , date[0].year , date[0].month , date[0].day , date[1].year , date[2].month , date[1].day);

    printf("\nThe number of pieces removed during this time period : %d\n" , sum);

    printf("\n\nPlease enter any thing to exit this page.....");

    getch();
}

void A_report_on_the_products_entered_and_exited_on_a_specific_date()
{

    struct Date
    {
        int year;
        int month;
        int day;
    };

    struct Date date[3];
    LL_prodoct *current = head_product;
    char First_Date[100] , Last_Date[100] , Product_Name[100] , Date_Transection[100];
    int count = 0;
    printf("Please enter a product name  : ");
    scanf("%s" , Product_Name);
    printf("Please enter a First Date (ex: yyyy/mm/dd) : ");
    scanf("%s" , First_Date);
    date[0].year = atoi(strtok(First_Date , "/"));
    date[0].month = atoi(strtok(NULL , "/"));
    date[0].day = atoi(strtok(NULL , "/"));
    printf("Please enter a Last Date (ex: yyyy/mm/dd) : ");
    scanf("%s" , Last_Date);
    date[1].year = atoi(strtok(Last_Date , "/"));
    date[1].month = atoi(strtok(NULL , "/"));
    date[1].day = atoi(strtok(NULL , "/"));
    while (current != NULL)
    {
        if (strcmp(current->product.name_product , Product_Name) == 0)
        {
            Linked_lists_of_products_entering_and_exiting *current_1 = head_transfer_process_product;
            while (current_1 != NULL)
            {
                if (current_1->transfer_process.Product_ID == current->product.Product_ID)
                {
                    strcpy(Date_Transection , current_1->transfer_process.transfer_processDate);
                    date[2].year = atoi(strtok(Date_Transection , "/"));
                    date[2].month = atoi(strtok(NULL , "/"));
                    date[2].day = atoi(strtok(NULL , "/"));
                    if ((date[0].year <= date[2].year) && (date[1].year >= date[2].year))
                    {
                        if ((date[0].month <= date[2].month) || (date[1].month >= date[2].month))
                        {
                            if ((date[0].day <= date[2].day) || (date[1].day >= date[2].day))
                            {
                                count++;
                                printf("\n%d." , count);
                                printf("\n\tProduct ID : %d" , current_1->transfer_process.Product_ID);
                                printf("\n\tNumber Of Products In This Transaction : %d" , current_1->transfer_process.count_tra);
                                printf("\n\tTransaction Type : %s" , current_1->transfer_process.transfer_processDate);
                                printf("\n\tTransaction Date : %s" , current_1->transfer_process.transfer_processDate);
                            }
                        }
                    }
                }
                current_1 = current_1->next;
            }
        }
        current = current->next;
    }
    printf("\n\nenter any thing to exit this page...");
    getch();
}


void MainMenu()
{
    int choice;

    system("cls");
    printf("*~~> Welcome to Reports_Page_main_menu\n\t");
    printf("-------------------------------------------------\n\t");
    printf("1- The quantity of each type in the warehouse\n\t");
    printf("-------------------------------------------------\n\t");
    printf("2- List of products of which there are more than the specified quantity\n\t");
    printf("-------------------------------------------------\n\t");
    printf("3- List of products of which there is less than the specified quantity\n\t");
    printf("-------------------------------------------------\n\t");
    printf("4- The price of all products in the warehouse is in (( riyals ))\n\t");
    printf("-------------------------------------------------\n\t");
    printf("5- The price of a specific product in riyals\n\t");
    printf("-------------------------------------------------\n\t");
    printf("6- The number of products entered on a specific date\n\t");
    printf("-------------------------------------------------\n\t");
    printf("7- The number of products that came out on a specific date\n\t");
    printf("-------------------------------------------------\n\t");
    printf("8- A_report_on_the_products_entered_and_exited_on_a_specific_date\n\t");
    printf("9- Exit\n");
    printf("*~~>Please enter the number of your choice : ");
    scanf("%d" , &choice);
    system("cls");
    switch (choice)
    {
      case 1:
        The_quantity_of_each_type_in_the_warehouse(head_product);
        break;
        List_of_products_of_which_there_are_more_than_the_specified_quantity(head_product);
      case 2:
        break;
      case 3:
        List_of_products_of_which_there_is_less_than_the_specified_quantity(head_product);
        break;
      case 4:
        The_value_of_all_products_in_the_warehouse_is_in_riyals (head_product);
        break;
      case 5:
        The_value_of_a_specific_product_in_riyals (head_product);
        break;
      case 6:
        The_number_of_products_entered_on_a_specific_date(head_product);
        break;
      case 7:
        The_number_of_products_that_came_out_on_a_specific_date(head_product);
        break;
      case 8:
        A_report_on_the_products_entered_and_exited_on_a_specific_date();
        break;
      case 9:
       exit(0);
        break;
      default:
      main_menu();
    }
}

