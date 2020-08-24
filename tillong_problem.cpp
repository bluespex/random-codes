#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

vector<int> dp;
const int mod = 1000000007;

int tilling(int n,int m){
	if(n<0){
		return 0;
	}
	if(dp[n]!=0){
		return dp[n];
	}
	if(n==0){
		dp[0] = 1;
		return dp[0];
	}

	dp[n] = (tilling(n-1,m)%mod + tilling(n-m,m)%mod)%mod;
	return dp[n];
}

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int t; cin>>t; while(t--)
	{
		int i,j,k,n,m,ans=0;
		cin>>n>>m;
		dp.clear();
		dp.resize(n+5,0);
		cout<<tilling(n,m)<<"\n";
	}
	return 0;
}
