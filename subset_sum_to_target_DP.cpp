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
		int sum;
		cin>>sum;
		vector<int> v(n+1);
		for(i=1;i<=n;i++){
			cin>>v[i];
		}
		
		vector<vector<bool> > dp(n+1,vector<bool> (sum+1,false));
		dp[0][0] = true;
		//cout<<dp[0][1];
		for(i=1;i<=n;i++){
			for(j=0;j<= sum;j++){
				if(j<v[i]){
					dp[i][j] = dp[i-1][j];
					continue;
				}
				dp[i][j] = dp[i-1][j-v[i]] || dp[i-1][j];
			}
		}
		cout<<dp[n][sum];

	}
	return 0;
}