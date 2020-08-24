#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string n;
int sz;
void keypad(int i,string ans){
	if(i==sz){
		cout<<ans<<"\n";
		return;
	}
	for(auto ele:table[n[i]-'0']){
		keypad(i+1,ans+ele);
	}
}

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	//int t; cin>>t; while(t--)
	{
		int i,j,k,m,ans=0;

		cin>>n;
		sz = n.size();
		keypad(0,"");
	}
	return 0;
}