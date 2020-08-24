#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* head = NULL;

struct node* newnode(int data){
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
};

void create(struct node** node){

    if(*node==head){
        int data;
        printf("\tEnter the data of the new node:");
        scanf("%d",&data);
        struct node* temp = newnode(data);
        *node = temp;
        head = temp;
    }
    printf("\nIt has a left child ???:0 or1 ");
    int lc;
    scanf("%d",&lc);
    if(lc==1){
        int data;
        printf("\nEnter the data of the left node <==>: ");
        scanf("%d",&data);
         struct node* l = newnode(data);
         (*node)->left = l;
        create((*node)->left);
    }
    int rc;
    printf("\nIt has a right child ???:0 or1  ");
    scanf("%d",&rc);
    if(rc==1){
         int data;
        printf("\nEnter the data of the right node <==>:");
        scanf("%d",&data);
            struct node* r = newnode(data);
         (*node)->right = r;
        create((*node)->right);
    }

}

void preorder(struct node* node){
    if(node==NULL){
        return;
    }
    printf("%d ",node->data);
    preorder(node->left);
    preorder(node->right);

}

void inorder(struct node* node){
    if(node==NULL){
        return;
    }
    preorder(node->left);
    printf("%d ",node->data);
    preorder(node->right);

}

main(){

    create(&head);
    preorder(head);
    printf("\n");
    inorder(head);

}
