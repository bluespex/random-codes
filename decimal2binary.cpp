#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	//int t; cin>>t; while(t--)
	{
		//int i,j,k,n,ans=0;
		int n;
		cin>>n;
		string s="";
		while(n){
			s+= (n&1) + '0';
			n=(n>>1);
		}
		reverse(s.begin(),s.end());
		cout<<s;


	}
	return 0;
}