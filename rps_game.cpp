#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

vector<vector<vector<double> > > dp;

double rock_survives(int r, int p, int s){
	if(r == 0 || s == 0)
		return 0.0;

	if(p == 0)
		return 1.0;

	if(dp[r][p][s] != -1)
		return dp[r][p][s];

	double rv = 0.0;
	double total = r*p + r*s + s*p;
	rv += rock_survives(r-1,p,s) * ((r*p)/total);
	rv += rock_survives(r,p-1,s) * ((s*p)/total);
	rv += rock_survives(r,p,s-1) * ((s*r)/total);

	return dp[r][p][s] = rv;
}

double paper_survives(int r, int p, int s){
	if(r == 0 || p == 0)
		return 0.0;

	if(s == 0)
		return 1.0;

	if(dp[r][p][s] != -1)
		return dp[r][p][s];
	double rv = 0.0;
	double total = r*p + r*s + s*p;
	rv += paper_survives(r-1,p,s) * ((r*p)/total);
	rv += paper_survives(r,p-1,s) * ((s*p)/total);
	rv += paper_survives(r,p,s-1) * ((s*r)/total);

	return dp[r][p][s] = rv;
}

double scissor_survives(int r, int p, int s){
	if(s == 0 || p == 0)
		return 0.0;

	if(r == 0)
		return 1.0;

	if(dp[r][p][s] != -1)
		return dp[r][p][s];
	double rv = 0.0;
	double total = r*p + r*s + s*p;
	rv += scissor_survives(r-1,p,s) * ((r*p)/total);
	rv += scissor_survives(r,p-1,s) * ((s*p)/total);
	rv += scissor_survives(r,p,s-1) * ((s*r)/total);

	return dp[r][p][s] = rv;
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
		int r,s,p;
		cin>>r>>s>>p;
		dp.clear();
		dp.resize(102,vector<vector<double> >(102,vector<double>(102,-1)));
		double ans1 = rock_survives(r,p,s);
		dp.clear();
		dp.resize(102,vector<vector<double> >(102,vector<double>(102,-1)));
		double ans2 = scissor_survives(r,p,s);
		dp.clear();
		dp.resize(102,vector<vector<double> >(102,vector<double>(102,-1)));
		double ans3 = paper_survives(r,p,s);

		cout<<fixed<<setprecision(9)<<ans1<<" "<<ans2<<" "<<ans3;
		cout<<"\n";

	}
	return 0;
}