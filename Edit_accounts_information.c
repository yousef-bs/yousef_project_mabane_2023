#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include "structs.h"


extern char The_current_member_name[100];
extern member_list *head_member;
extern struct members_data member;


void edit_account_information()
{
    int m , length , n = 1 , num , choice;
    char temp , y;
    char member_name[100] , Password[100];

    fflush(stdin);
    system("cls");
    member_list *current = head_member;

    while (current != NULL)
    {
        if (strcmp(current->member.member_name, The_current_member_name) == 0 )
        {
            break;
        }
        current = current->next;
    }
    printf("*~~>Welcome to Warehouse Management account settings<====\n\n");
    printf("1.Name : %s\n" , current->member.Name);
    printf("2.surname : %s\n" , current->member.surname);
    printf("3.the_national_ID : %s\n" , current->member.the_national_ID);
    printf("4.Phone Number : %s\n" , current->member.mobile_Number);
    printf("5.Email : %s\n" , current->member.Email);
    printf("6.Password : %s\n" , current->member.Password);
    printf("7.Exit\n*~~>Please enter the number of your choice for change this information : ");
    
    scanf("%d" , &choice);
    system("cls");
    fflush(stdin);
    switch (choice)
    {
      case 1:
          {
            printf("Name : ");
            gets(current->member.Name);
            break;
          }
      case 2:
          {
            printf("surname : ");
            gets(current->member.surname);
            break;
          }
      case 3:
          {
            do
            {
              n = 1;
              printf("the_national_ID (ex:0~>9) : ");
              gets(current->member.the_national_ID);
              length = strlen(current->member.the_national_ID);
              for ( m = 0 ; m < length ; m++ )
              {
                  num = current->member.the_national_ID[m];
                  if (num < 48 || num > 57)
                  {
                      break;
                  }
              }
              if (num >= 48 && num <= 57)
              {
                 n = 0;
              }
              else
              {
                  printf("You must enter only numbers and ten numbers only, as shown in the example, please enter it again : \n");
                  current->member.the_national_ID[length] = ".";
              }
            }while (n != 0);
            break;
          }
      case 4:
          {
            do
            {
              n = 1;
              printf("mobile Number (ex:0~>11 number) : ");
              gets(current->member.mobile_Number);
              length = strlen(current->member.mobile_Number);
              for ( m = 0 ; m < length ; m++ )
                {
                     num = current->member.mobile_Number[m];
                    if (num < 48 || num > 57)
                     {
                         break;
                     }
                }
              if (num >= 48 && num <= 57)
               {
                   n = 0;
               }
             else
               {
                      printf("You must enter only numbers and eleven numbers only, as shown in the example, please enter it again : \n");
                       current->member.mobile_Number[length] = ".";
               }
            }while (n != 0);
            break;
          }
      case 5:
          {
            do
            {
              n = 1;
              printf("Email (ex:******@****.com) : ");
              gets(current->member.Email);
              length = strlen(current->member.Email);
              for ( m = 0 ; m < length ; m++ )
              {
                  temp = current->member.Email[m];
                  if (temp == ' ')
                  {
                      break;
                  }
              }
              if (temp != ' ')
              {
                 n = 0;
              }
              else
              {
                  printf("You do not have to enter a space in the Email, please enter it again : \n");
                  current->member.Email[length] = ".";
              }
            }while (n != 0);
            break;
          }
      case 6:
          {
            printf("New Password : ");
            gets(current->member.Password);
            do
            {
               n = 1;
               printf("Confirm Your New Password : ");
               gets(current->member.ConfirmYourPassword);
               if (strcmp(current->member.ConfirmYourPassword , current->member.Password) != 0)
               {
                   printf("Those passwords didn�t match. Try again.\n");
               }
               else
               {
                   n = 0;
               }
            }while (n != 0);
            break;
          }

      case 7:
        main_menu();
        break;
      default:
        edit_account_information();
    }
    do
    {
        n = 0;
        printf("Are you want change another information ? (ans : y or n) : ");
        scanf("%c" , &y);
        if (y == 'y')
            edit_account_information();
        else if (y == 'n')
            main_menu();
        else
            n = 1;
    }while (n != 0);
}
