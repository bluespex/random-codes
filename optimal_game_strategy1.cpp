#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

vector<int> v;
vector<vector<int> > dp;

int strategy(int i,int j){
	
	if(i>j){
		return 0;
	}
	if(j-i==1){
		return max(v[i],v[j]);;
	}
    if(dp[i][j] != -1){
        return dp[i][j];
    }

	dp[i][j] =  max( v[i] + min(strategy(i+2,j) , strategy(i+1,j-1)),
					 v[j] + min(strategy(i,j-2) , strategy(i+1,j-1))
					);

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
		v.resize(n);
		dp.resize(n,vector<int>(n,-1));
		for(i = 0; i<n; i++){
			cin>>v[i];
		}
		cout<<strategy(0,n-1);

	}
	return 0;
}