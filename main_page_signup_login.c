#include <stdio.h>
#include <stdlib.h>
#include "structs.h"


extern member_list head_member;
extern int recognition;

void LoginPage()
{
    int choice;
    printf("*~~>\tWelcome to Warehouse Management program\t<~~*\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*--*-*\n");
    printf("\t1.SignUp\n\t2.LogIn\n\t3.Exit\n~~>\tPlease enter the number of your choice : \n ");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*--*-*");
    scanf("%d" , &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        SignUp();
        LoginPage();
        break;
    case 2:
        LogIn();
        system("cls");
        if (!recognition)
        {
            printf("\n\n\n\t\tWrong credentials\n\t\tsorry..Invalid username or password...\n\t\tPlease try agian\n\n\n");
        }
        break;
    case 3:
        Transferring_member_information_from_the_linked_lists_to_the_file(head_member);
        exit(0);
        break;
    }
}
