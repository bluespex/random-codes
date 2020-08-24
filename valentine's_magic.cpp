#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

vector<int> b;
vector<int> g;
vector<vector<int> > dp;
int n,m;

int magic(int i, int j){
	if(dp[i][j] != -1)
		return dp[i][j];
	if(i<n && j==m)
		return 1e9;

	if(i==n)
		return 0;

	dp[i][j] = min( abs(b[i]-g[j]) + magic(i+1,j+1) ,
					magic(i,j+1)
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
		int i,j,k,ans=0;
		cin>>n>>m;
		b.resize(n);
		g.resize(m);
		dp.resize(n+1,vector<int>(m+1,-1));
		for(i=0;i<n;i++)
			cin>>b[i];
		
		for(i=0;i<m;i++)
			cin>>g[i];

		sort(b.begin(), b.end());
		sort(g.begin(), g.end());
		cout<<magic(0,0);
	}
	return 0;
}