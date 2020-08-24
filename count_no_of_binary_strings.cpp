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
	
	vector<int> dp(91);
	dp[1] = 2;
	dp[2] = 3;
	for(int i = 3; i<=90; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	int t; cin>>t; while(t--)
	{
		int j,k,m,ans=0;
		cin>>k;
		cout<<dp[k]<<"\n";


	}
	return 0;
}