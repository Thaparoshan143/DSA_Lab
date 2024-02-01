// Implementation of Binary Search Tree (BST) Operation

#include<stdio.h>
#include<stdlib.h>

#define MENU_ITEM_COUNT 7

const char *menuItems[] = {
    "Insert Node",
    "Traverse in Inorder",
    "Traverse in Preorder",
    "Traverse in Postorder",
    "Searching",
    "Delete Node",
    "Exit"
};

typedef struct Node {
    int data;
    struct Node *left, *right;
}Node;

void seperator(const char symbol, int count)
{
    printf("\n");
    for(int i=0;i<count;i++)
    {
        printf("%c", symbol);
    }
    printf("\n");
}

void display_menu()
{
    printf("\n==> MAIN MENU <==\n");
    for(int i=0;i<MENU_ITEM_COUNT;i++)
    {
        printf("%d. %s\n", i+1, menuItems[i]);
    }
    seperator('_', 50);
    printf("\n");
}

int get_int_input(const char *label)
{
    int temp;
    printf("%s", label);
    scanf("%d", &temp);
    return temp;
}

void init_node(Node **root, int val)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    *root = temp;
}

Node* GetNewNode(int number)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = number;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void InsertRecNode(Node **root, Node *oth)
{
    if((*root) == NULL)
    {
        *root = oth;
        return;
    }
    Node *node = *root;
    if(node->data < oth->data)
    {
        if(node->right == NULL)
        {
            node->right = oth;
            return;
        }
        InsertRecNode(&(node->right), oth);
    }
    else if(node->data > oth->data)
    {
        if(node->left == NULL)
        {
            node->left = oth;
            return;
        }
        InsertRecNode(&(node->left), oth);
    }
}

void TravInOrder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    TravInOrder(root->left);
    printf("%d\t", root->data);
    TravInOrder(root->right);
}

void TravInPreOrder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d\t", root->data);
    TravInPreOrder(root->left);
    TravInPreOrder(root->right);
}

void TravInPostOrder(Node *root)
{
    if(root == NULL)
    {       
        return;
    }
    if(root->left == NULL && root->right == NULL)
    {
        printf("%d\t", root->data);
        return;
    }
    if(root->left != NULL)
    TravInPostOrder(root->left);
    if(root->right != NULL)
    TravInPostOrder(root->right);
    printf("%d\t", root->data);
}

Node* SearchElement(Node *root, int val)
{   
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == val)
    {
        printf("\nElement Found in BT");
        return root;
    }
    else 
    {
        SearchElement(root->left, val);
        SearchElement(root->right, val);
    }
    return NULL;
}

Node* DoesEleExist(Node *root, int ele)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == ele)
    {
        return root;
    }
    return NULL;
}

void StichNode(Node **root, Node *oth)
{
    if(oth->right == NULL)
    {
        *root = oth->left;
    }
    else 
    {
        *root = oth->right;
        InsertRecNode(root, oth->left);
    }
    free(oth);
}

void DeleteNode(Node **root, int ele)
{
    if(root == NULL)
    {
        return;
    }
    if((*root)->left == NULL && (*root)->right == NULL)
    {
        if((*root)->data == ele)
        {
            free(*root);
            *root = NULL;
        }
    }
    Node *searchNode = DoesEleExist((*root)->left, ele);

    if(searchNode != NULL)
    {
        StichNode(&((*root)->left), searchNode);
        return;
    }

    searchNode = DoesEleExist((*root)->right, ele);

    if(searchNode != NULL)
    {
        StichNode(&((*root)->right), searchNode);
        return;
    }

    DeleteNode(&((*root)->left), ele);
    DeleteNode(&((*root)->right), ele);
}

int main()
{
    Node *root = NULL, *temp = NULL;
    int choice, exit_status = 0;
    int inc = 0;

    while(!exit_status)
    {
        display_menu();

        choice = get_int_input("Enter your choice : ");

        switch(choice)
        {
            case 1:
            choice = get_int_input("Enter the Number to insert : ");
            temp = GetNewNode(choice);
            InsertRecNode(&root, temp);
            break;
            case 2:
            TravInOrder(root);
            break;
            case 3:
            TravInPreOrder(root);
            break;
            case 4:
            TravInPostOrder(root);
            break;
            case 5:
            choice = get_int_input("Enter the number to search : ");
            temp = SearchElement(root, choice);
            printf("Found Node at : %p\n", temp);
            break;
            case 6:
            choice = get_int_input("Enter element to delete : ");
            DeleteNode(&root, choice);
            break;
            case 7:
            exit_status = 1;
            printf("\nExiting program!");
            break;
            default:
            printf("\nPlease enter the valid number for emnu choice\n");
            break;
        }
    }

    return 0;
}
