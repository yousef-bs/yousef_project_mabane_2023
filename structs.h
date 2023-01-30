struct members_data
{
    char member_name[100];
    char Name[100];
    char surname[100];
    char the_national_ID[11];
    char mobile_Number[12];
    char Email[100];
    char Password[100];
    char ConfirmYourPassword[100];

};


typedef struct Node
{
    struct members_data member;
    struct Node *next;
} member_list;


struct Entry_and_exit_of_the_product_from_the_warehouse
{
    int Product_ID;
    int count_tra;
    char member_name[100];
    char transfer_processType[100];
    char transfer_processDate[100];
};


typedef struct Product_pull_and_push_node
{
    struct Entry_and_exit_of_the_product_from_the_warehouse transfer_process;
    struct Product_pull_and_push_node *next;
} Linked_lists_of_products_entering_and_exiting;


struct new_products
{
    int count;
    int Product_ID;
    char name_product[100];
    char Product_brand[100];
    char Product_model[100];
    char Product_price[100];
    char Product_explanations[100];

};


typedef struct ProductNode
{
    struct new_products product;
    struct ProductNode *next;
} LL_prodoct;
