#include<stdio.h>

int arr[100],count=0;

void swap(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void upheapify(int ci){
	if(ci==0){
		return;
	}
	int pi = (ci-1)/2;
	if(arr[pi]>arr[ci]){
		swap(&arr[pi],&arr[ci]);
	}
	upheapify(pi);                                
}

void insert(int data){
	
	arr[count] = data;
	upheapify(count);
	count++;
}

void downheapify(int pi){
	
	int lci = (2*pi)+1;
	int rci = (2*pi) +2;
	int mini = pi;
	
	if(lci<count-1&&arr[lci]<arr[mini]){
		mini = lci;
	}
	if(rci<count-1&&arr[rci]<arr[mini]){
		mini = rci;
	}
	
	if(mini!=pi){
		printf("Swapping %d and %d\n",arr[mini],arr[pi]);
		swap(&arr[mini],&arr[pi]);
		downheapify(mini);
		printf("Calling downheapify for index %d\n",mini);
	}
}

void deletefromheap(){
	printf("%d ",arr[0]);
	swap(&arr[0],&arr[count-1]);
	count--;
	downheapify(0);
}

void Display(){
	int i;
	for(i=0;i<count;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
} 

void heapsort(){
	while(count>=0){
		deletefromheap();
		count--;
	}
	printf("\n");
}

main(){
	
	while(1){
		printf("1. Insert\n");
		printf("2. Delete an element\n");
		printf("3. HeapSort\n");
		printf("4 .Exit\n");
		int n ;
		scanf("%d",&n);
		switch(n){
			case 1: printf("Enter the element to be inserted: ");
					int data;
					scanf("%d",&data);
					insert(data);
					break;
					
			case 2: deletefromheap();
					break;
					
			case 3: heapsort();
					break;
					
			case 4: exit(0);
		}
	}
	
}

