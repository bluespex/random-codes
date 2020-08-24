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
	
	//int t; cin>>t; while(t--)
	{
		int i,j,k,n,m,ans=0;
		cin>>n;
		vector<int> v(n);
		vector<int> dp(n,INT_MAX);
		for(i=0;i<n;i++){
			cin>>v[i];
		}
		dp[0] = 0;
		for(i=0;i<n;i++){
			if(v[i] == 0)
				continue;
			for(j=1;j<=v[i];j++){
				if(i+j >= n)
					continue;
				dp[i+j] = min(dp[i+j],dp[i]+1);
			}
		}
		cout<<dp[n-1];


	}
	return 0;
}