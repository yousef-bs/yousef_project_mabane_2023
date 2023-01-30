#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

#include "structs.h"

extern struct members_data member;
extern member_list *head_member;


extern int recognition;
extern char The_current_member_name;


void LogOut()
{
    fflush(stdin);
    char y;
    printf("Are you sure??? (ans : y or n) : ");
    scanf("%c" , &y);
    if (y == 'y'){
        recognition = 0;
        The_current_member_name = '\0';
        LoginPage();
    }
    else if (y == 'n')
        main_menu();
    else
        LogOut();
}
