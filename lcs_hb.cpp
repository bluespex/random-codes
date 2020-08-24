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
		string s1,s2;
		string s = "";
		cin>>s1>>s2;
		//cout<<s1[];
		n = s1.size(); m = s2.size();
		vector<vector<int> > dp( n+1, vector<int> (m+1,0));
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(s1[i-1] == s2[j-1]){
					dp[i][j] = 1 + dp[i-1][j-1];
				}else{
					dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
				}
			}
		}

		i=n;j=m;
		while(i>0&&j>0){
			if(s1[i-1] == s2[j-1]){
				s += s1[i-1];
				i--; j--;
			}else{
				if(dp[i-1][j] > dp[i][j-1])
					i--;
				else
					j--;
			}
		}
		reverse(s.begin(), s.end());
		cout<<s;

	}
	return 0;
}