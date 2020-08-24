#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

vector<int> sum;
vector<int> v;
vector<vector<int> > dp;

int mixtures(int i, int j){
	if(dp[i][j] != INT_MAX){
		return dp[i][j];
	}
	if(i>=j){
		return 0;
	}
	// if(j-i==1){
	// 	return v[i]*v[j];
	// }
	for(int k=i;k<j;k++){
		dp[i][j] = min(dp[i][j] , mixtures(i,k) + mixtures(k+1,j) + (((sum[k]-sum[i]+v[i])%100) * ((sum[j]-sum[k])%100) ) );	
	}
	return dp[i][j];
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
		int i,j,k,n,m,ans=0;
		cin>>n;
		sum.resize(n);
		dp.resize(n,vector<int>(n,INT_MAX));
		v.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
			if(i==0){
				sum[i] = v[i];
				continue;
			}
			sum[i] = (sum[i-1] + v[i]);
		}
		cout<<mixtures(0,n-1);


	}
	return 0;
}