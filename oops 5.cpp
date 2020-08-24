#include<bits/stdc++.h>
using namespace std;

class father;

class son
{
	int acc_bal;
	

public:
	friend class father;
	friend int totalsum(father &f,son &s);
	son(int a){
		acc_bal = a;
	}


	void fname(father &f);
	
};

class father
{
	int acc_bal;
	string name;

	
//	friend class son;
public:
	friend class son;
	friend void son::fname(father &f);
	friend int totalsum(father &f,son &s);
	friend void fdisplay(father &f);
	father(int a,string s){
		acc_bal = a;
		name = s;
	}
	
	int diff(son &s){
		return acc_bal - s.acc_bal;
	}
	
	
	
};



void son :: fname(father &f){
	cout<<f.name;
}

int totalsum (father &f, son &s){
	return f.acc_bal + s.acc_bal;
}

void fdisplay(father &f){
	cout<<f.acc_bal<<"\n";
}

int main(){
	father f(20,"father");
	son s(10);
	fdisplay(f);
	cout<<totalsum(f,s)<<"\n";
	cout<<f.diff(s)<<"\n";
	s.fname(f);
	return 0;

}