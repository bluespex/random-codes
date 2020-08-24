#include <stdio.h>
#include<conio.h>
#define max 10
int st[max],top;
void push(int);
void pop();
void display();
int main() {
    int item=0;
    int ch=0;
    int choice=0;
    top=-1;
    do{
    	printf("\n 1.Push");
    	printf("\n 2.Pop");
    	printf("\n 3.Display");
    	printf("\n Enter your choice :");
    	scanf("%d",&choice);
    	switch(choice){
    		case 1:printf("\n Enter the item to be inserted : ");
    		       scanf("%d",&item);
    		       push(item);
    		       break;
    		case 2:pop();
    		       break;
    		case 3:display();
                    printf("prabh");
    		       break;
    		default:printf("\n Wrong choice!!!");
    	}
    	printf("\n Do you want to continue : ");
    	scanf("%d",&ch);
    }while(ch==1);

}
void push(int item){
if(top==max-1){
    printf("\n Stack is full ");
    return;
}
top++;
st[top]=item;
}

void pop(){

	if(top==-1){
		printf("\n Stack is empty");
		return;
	}
	int delitem=st[top];
	top--;
}
void display(){
	int i=0;
	if(top==-1){
		printf("\n Stack is empty");
		return;
	}
	printf("\n%d",st[top]);
	for(i=top-1;i>=0;i--){
		printf("\n%d",st[i]);
	}
	printf("\n\n\n");
}

