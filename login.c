#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include "structs.h"

extern struct members_data member;
extern member_list *head_member;
extern int recognition;
extern char The_current_member_name[100];

int LogIn()
{
    char member_name[100] , Password[100];
    int check_login = 0;
    system("cls");
    printf("*~~>Welcome to the login page\n");
    fflush(stdin);

    printf("Username : ");
    gets(member_name);

    printf("Password : ");
    gets(Password);

    check_login = checkLogin(head_member, member_name, Password);
    return check_login;
}



int checkLogin(member_list *head, char member_name[], char password[])
{
    int recog = 0;
    member_list *current = head;

    while (current != NULL)
    {
        if ((strcmp(current->member.member_name, member_name) == 0) && (strcmp(current->member.Password, password) == 0))
        {
            recog = 1;
            recognition = 1;
            strcpy(The_current_member_name, member_name);
            
            Get_product_information_from_the_file();
            
            import_transfer_product_data_from_file();
            
            return recog;
        }
        current = current->next;
    }
    return recog;
}
