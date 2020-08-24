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
	
	int t; cin>>t; while(t--)
	{
		int i,j,k,n,m,maximum = 0;
		cin>>n;
		vector<P> s(n);
		for(i=0;i<n;i++){
			cin>>s[i].F;
		}
		for(i=0;i<n;i++){
			cin>>s[i].S;
		}
		vector<int> dp(n,1);
		sort(s.begin(), s.end());
		for(i=0;i<n;i++){
			for(j=0;j<i;j++){
				if( s[i].S >= s[j].S && dp[i] < 1 + dp[j]){
					dp[i] = 1 + dp[j];
				}
			}
			maximum = max(dp[i],maximum);
		}
		cout<<maximum<<"\n";


	}
	return 0;
}