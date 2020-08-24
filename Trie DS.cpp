#include<bits/stdc++.h>

using namespace std;

#define hashmap unordered_map<char,node*>

class node
{
public:
	char data;
	bool isTerminal;
	hashmap h;

	node(char d){
		data=d;
		isTerminal=false;
	}
	
};

class Trie
{
	node* root;
public:
	Trie(){
		root = new node('\0');
	}

	//Insertion
	void addWord(char *word){
		node* temp = root;
		for(int i=0; word[i]!='\0',i++){

			char ch=word[i];
			if(temp->h.count(ch)==0){
				node* child =new node(ch);
				temp->h[ch] = child;
				temp= child;
			}else{
				temp = temp->h[ch];
			}
		}
		temp->isTerminal = true;
	}

	//lookup
	bool search(char* word){
		node* temp = root;

		for(int i=0; word[i]!='\0';i++){
			char ch = word[i];

			if(temp->h.count(ch)){
				temp = temp->h[ch];
			}else{
				return false;
			}
		}
		return temp->isTerminal;
	}
};

int main(){
	
	return 0;
}