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
		int i,x,y,n,ans=0;
		cin>>x>>y;
		for(i = x;i<=y;i++){
			ans+= __builtin_popcount(i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}