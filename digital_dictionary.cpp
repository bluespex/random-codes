#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

class node{
public:
	char data;
	bool is_end;
	map<char,node*> characters;
	node(char data){
		data = data;
		is_end = false;
	}
};

class Dictionary{
	node* root;
public:
	Dictionary(){
		root = new node('\0');
	}

	void add(string s){
		node *temp = root;
		for(int i=0;i<s.size();i++){
			char ch = s[i];
			if(temp->characters.count(ch) == 0){
				node* child = new node(ch);
				temp->characters[ch] = child;
				temp = child;
			}else{
				temp = temp->characters[ch];
			}
		}
		temp->is_end = true;
	}

	void allwords(node* temp,string s){
		if(temp->is_end){
			cout<<s<<"\n";
		}
		if(temp->characters.empty()){
			return;
		}
		for(auto ele:temp->characters){
			allwords(ele.S , s+ele.F);
		}
	}

	bool search(string s){
		node* temp = root;
		for(int i=0;i<s.size();i++){
			char ch = s[i];
			if(temp->characters.count(ch) == 0){
				add(s);
				cout<<"No suggestions\n";
				return false;
			}else{
				temp = temp->characters[ch];
			}
		}
		
		allwords(temp,s);
		return false;
	}
}d;

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	//int t; cin>>t; while(t--)
	{
		int i,j,k,n,m,ans=0;
		cin>>n;
		for(i=0;i<n;i++){
			string s;
			cin>>s;
			d.add(s);
		}
		cin>>m;
		for(i=0;i<m;i++){
			string s;
			cin>>s;
			d.search(s);
		}


	}
	return 0;
}