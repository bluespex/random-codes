#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Tnode{
	int data;
	Tnode* left;
	Tnode* right;
}*root;

Tnode* input(Tnode* parent, Tnode* temp){
	if(parent == NULL){
        parent = temp;
		return parent;
	}else{
		if((temp->data)<((parent)->data)){
			parent->left = input(parent->left,temp);
		}else{
			parent->right = input(parent->right,temp);
		}
	}
	return parent;
}

void preorder(Tnode* temp){
    if(temp == NULL){
        return;
    }
	printf("%d  ", (temp)->data);
	preorder((temp)->left);
	preorder((temp)->right);
}

void inorder(Tnode* temp){
    if(temp == NULL){
        return;
    }
    inorder(temp->left);
    printf("%d  ",temp->data);
    inorder(temp->right);
}
int main(){

   // root = NULL;
    for(int i=0;i<5;i++){
            int data;
        cin>>data;
        Tnode* temp = (Tnode*)malloc(sizeof(Tnode));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        root = input(root,temp);
    }
    printf("preorder\n");
	preorder(root);
	printf("\ninorder\n");
	inorder(root);
	return 0;
}
