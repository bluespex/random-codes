#include <bits/stdc++.h>
using namespace std;

char ch [4] = {'R','G','B'};

string check (int size, int n){
	string str;
	for(int i=0;i<size;i++){
		str+=ch[(n+i)%3];
	}
	return str;
}

int main() {
	int q;
	cin>>q;
	while(q--){
		int n ,k;
		cin>>n>>k;
		string s;
		cin>>s;
		int change=k;
		for(int i=0;i<n-k+1;i++){
			string word=s.substr(i,k);
			for(int l=0;l<3;l++){
				int change2=0;
				string str = check(k,l);
				for(int j=0;j<k;j++){
					if(word[j]!=str[j]){
						change2++;
					}
				}
				if(change>change2){
					change=change2;
				}
			}
		}
		cout<<change<<"\n";
	}
	return 0;
}