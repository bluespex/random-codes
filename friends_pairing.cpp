#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	vector<int> ways(31,0);
	ways[1] = 1;
	ways[2] = 2;
	for(int i=3;i<31;i++){
		ways[i] = ways[i-1] + (i-1)*ways[i-2];
	}

	int t; cin>>t; while(t--)
	{
		int j,k,n,m,ans=0;
		cin>>n;
		cout<<ways[n]<<"\n";
	}
	return 0;
}