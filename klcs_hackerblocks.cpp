#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

int dp[2005][2005][7];

vector<int>v1;
vector<int>v2;
int klcs(int k,int i,int j){
	if(i<0||j<0){
		return 0;
	}
	if(dp[i][j][k]!=0){
		return dp[i][j][k];
	}
	if(v1[i] == v2[j]){
		dp[i][j][k] = 1 + klcs(k,i-1,j-1);
		return dp[i][j][k];
	}
	if(k>0){
		dp[i][j][k] = max({klcs(k,i-1,j) , klcs(k,i,j-1), 1+klcs(k-1,i-1,j-1)});
		return dp[i][j][k];
	}else{
		dp[i][j][k] = max(klcs(k,i-1,j) , klcs(k,i,j-1));
		return dp[i][j][k];
	}
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
		cin>>n>>m>>k;
		v1.resize(n);
		v2.resize(m);
		for(i=0;i<n;i++){
			cin>>v1[i];
		}
		for(i=0;i<m;i++){
			cin>>v2[i];
		}
		cout<<klcs(k,n-1,m-1);

	}
	return 0;
}