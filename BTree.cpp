#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;

	node(int data){
		data = data;
		left = NULL;
		right = NULL;
	}

};

class tree
{
	node* root;



public:
	tree(){
		root = input(NULL,true);
	}
	node* input(node* parent, bool isleft){
		if(parent == NULL){
			cout<<"enter data for root node\n";
		}else if(isleft){
			cout<<"enter data for left child of "<<parent->data<<"\n";
		}else{
			cout<<"enter data for right child of "<<parent->data<<"\n";
		}
		int data;
		cin>>data;
		node* nn = new node(data);
		cout<<"does it have a left child\n";
		bool choice ;
		cin>>choice;
		if(choice){
			nn->left = input(nn, true);
		}

		cout<<"does it have a right child\n";
		cin>>choice;
		if(choice){
			nn->right = input(nn, false);
		}

		return nn;
	}

	void display(node* parent){
		string s = "";
		if(parent->left!=NULL){
			s += parent->left->data;
			s+="=>";
		}
		s += parent->data;
		if(parent->right!=NULL){
			s+="<=";
			s+=parent->right->data;
		}
		cout<<s<<"\n";

		if(parent->left!=NULL) {
			display(parent->left);
		}
		if(parent->right!=NULL) {
			display(parent->right);
		}
	}

	void display(){
		display(root);
	}

};

int main(){
	tree T;
	T.display();
	return 0;
}
