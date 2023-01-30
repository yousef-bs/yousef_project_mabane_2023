#include<stdio.h>
#include<string.h>
#include "structs.h"

extern LL_prodoct *head_product;

extern struct new_products product;

int CheckUsedID(LL_prodoct *head , int Product_ID)
{
    LL_prodoct *current = head;
    while (current != NULL)
    {
        if (current->product.Product_ID == Product_ID )
        {
            printf("Your Product_id is being used in another product :( \nPlease enter another Product_id :) \n");
            return 1;
        }
        current = current->next;
    }
    return 0;
}




void NewProductRegistration()
{
    int check;
    fflush(stdin);
    printf("*~~>Welcome to the new product registration page<====\n\n");
    printf("We need some information about the new product, please enter this information....\n\n");
    do
    {
        printf("Product ID : ");
        scanf("%d" , &product.Product_ID);
        check = CheckUsedID(head_product , product.Product_ID);
    }while(check != 0);
    fflush(stdin);

    printf("Name of the product : ");
    gets(product.name_product);

    printf("Brand of the product : ");
    gets(product.Product_brand);

    printf("Model of the product : ");
    gets(product.Product_model);

    printf("Product price : ");
    gets(product.Product_price);

    printf("Product_explanations : ");
    gets(product.Product_explanations);
    product.count = 0;

    Send_the_product_from_a_file_to_the_linked_lists(head_product, product);

}
