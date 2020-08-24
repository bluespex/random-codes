#include <stdio.h>
#include<stdlib.h>
struct sNode {
    int data;
    struct sNode* next;
};

void push(struct sNode** top_ref, int new_data)
{
    /* allocate node */
    struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode));
    if (new_node == NULL) {
        printf("Stack overflow \n");
        getchar();
        exit(0);
    }

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*top_ref);

    /* move the head to point to the new node */
    (*top_ref) = new_node;
}

/* Function to pop an item from stack*/
int pop(struct sNode** top_ref)
{
    int res;
    struct sNode* top;

    /*If stack is empty then error */
    if (*top_ref == NULL) {
        printf("Stack underflow \n");
        getchar();
        exit(0);
    }
    else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

int main()
{
    sNode* pesticide;
    sNode* temp;
    int check;
    int n,days=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        push(*pesticide,t);
    }

    int t1,t2;
    while(1){
        check=1;
        t1=pesticide->data;
        pop();
        while(pesticide!=nullptr){
            t2=pesticide->data;
            pop(pesticide);
            if(t1<t2){
                push(temp,t1);
            }else{
                check=0;
            }
            t1=t2;
            if(pesticide==nullptr){
                push(temp,t2);
            }
        }
        days++;
        if(check==1){
            break;
        }
        while(temp!=nullptr){
            push(pesticide,temp->data);
            pop(temp);
        }

    }
    printf("%d",days-1);
    return 0;

}
