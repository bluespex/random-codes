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
	
	vector<int> dp(20000001);
	dp[1] = 0;
	for(int i=2;i<20000001;i++){
		int temp = INT_MAX;
		if(i%2 == 0)
			temp = min(temp,dp[i/2]+1);
		if(i%3 == 0)
			temp = min(temp,dp[i/3]+1);
		dp[i] = min(dp[i-1]+1,temp);
	}

	int t; cin>>t; 
	for(int cnt=1;cnt<=t;cnt++)
	{
		int i,j,k,n,m,ans=0;
		cin>>n;
		cout<<"Case "<<cnt<<": "<<dp[n]<<"\n";
	}
	return 0;
}