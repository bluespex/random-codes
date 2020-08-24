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
	
	int t; cin>>t; while(t--)
	{
		int i,j,k,n,ans=0;
		string s1,s2,s3;
		cin>>s1>>s2;
		for(int i=0;i<s1.size();i++){
			int temp = (s1[i]-'0')^(s2[i]-'0');
			cout<<temp;
		}
		cout<<"\n";

	}
	return 0;
}