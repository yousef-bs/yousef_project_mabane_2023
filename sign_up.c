#include<stdio.h>
#include<string.h>
#include "structs.h"


extern member_list *head_member;
extern struct members_data member;


int Check_Used_member_name(member_list *head , char member_name[])
{
    member_list *current = head;
    while (current != NULL)
    {
        if (strcmp(current->member.member_name, member_name) == 0 )
        {
            printf("Your username is being used by someone else.\nPlease enter another username...\n");
            return 1;
        }
        current = current->next;
    }
    return 0;
}



void SignUp()
{
    // struct members_data member;
    int i , length , n = 1 , num , choice;
    char temp , robot_check;
    printf("====>Welcome to the sign up page<====\n\n");
    printf("We need some information, please enter this information....\n\n");
    fflush(stdin);
    do
    {
        printf("Username : ");
        gets(member.member_name);
        length = strlen(member.member_name);
        for ( i = 0 ; i < length ; i++ )
        {
            temp = member.member_name[i];
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
            printf("You do not have to enter a space in the username, please enter it again : \n");
            member.member_name[length] = ".";
        }
        n = Check_Used_member_name(head_member , member.member_name);
    }while (n != 0);
    printf("Password : ");
    gets(member.Password);
    do
    {
        n = 1;
        printf("Confirm Your Password : ");
        gets(member.ConfirmYourPassword);
        if (strcmp(member.ConfirmYourPassword , member.Password) != 0)
        {
            printf("Those passwords didn't match. Try again.\n");
        }
        else
        {
            n = 0;
        }
    }while (n != 0);
    printf("Name : ");
    gets(member.Name);
    printf("Last Name : ");
    gets(member.surname);
    do
    {
        n = 1;
        printf("the_national_ID (ex:0123456789) : ");
        gets(member.the_national_ID);
        length = strlen(member.the_national_ID);
        for ( i = 0 ; i < length ; i++ )
        {
            num = member.the_national_ID[i];
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
            member.the_national_ID[length] = ".";
        }
    }while (n != 0);
    do
    {
        n = 1;
        printf("mobile Number (ex:09123456789) : ");
        gets(member.mobile_Number);
        length = strlen(member.mobile_Number);
        for ( i = 0 ; i < length ; i++ )
        {
            num = member.mobile_Number[i];
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
            member.mobile_Number[length] = ".";
        }
    }while (n != 0);
    do
    {
        n = 1;
        printf("Email (ex:******@****.com) : ");
        gets(member.Email);
        length = strlen(member.Email);
        for ( i = 0 ; i < length ; i++ )
        {
            temp = member.Email[i];
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
            member.Email[length] = ".";
        }
   
       }while (n != 0);
    Transfer_accounts_from_files_to_linked_lists(head_member , member);
    fflush(stdin);
    do
    {
        n = 0;
        printf("If you are not a robot please enter (y) : \n");
        scanf("%c" , &robot_check);
        if (robot_check != 'y')
            n = 1;
    }while (n != 0);
    printf("Your data has been saved........\nThank you for this information....\n");
    sleep(2);
    system("cls");
}

