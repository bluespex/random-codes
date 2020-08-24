#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

unordered_map<int,int> dp;

int exchange(int n){
	if(dp.count(n)){
		return dp[n];
	}
	if(n==1){
		return 1;
	}
	if(n==0){
		return 0;
	}

	int temp = exchange(n/4) + exchange(n/3) + exchange(n/2);
	dp[n] = max(n,temp);
	return dp[n];
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
		// vector<int> dp(n+1);

		// for(i = 1;i<=n;i++){
		// 	int temp = 0;
		// 	if(i%2 == 0)
		// 		temp += dp[i/2];
		// 	if(i%3 == 0)
		// 		temp += dp[i/3];
		// 	if(i%4 == 0)
		// 		temp += dp[i/4];

		// 	dp[i] = max(i,temp);

		// }

		cout<<exchange(n);


	}
	return 0;
}