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
		cin>>n>>m;
		int arr[n][m];
		int dp[n][m];
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin>>arr[i][j];
				if(arr[i][j]){
					dp[i][j] = 1;
				}
			}
		}

		for(i=1;i<n;i++){
			for(j=1;j<m;j++){
				if(dp[i][j]){
					int x = dp[i-1][j-1];
					if(x==0){
						continue;
					}
					int k = 1;
					for(; k <= x; k++){
						if(i-k == -1)
							break;
						if(j-k == -1)
							break;
						if(arr[i-k][j]!=1)
							break;
						if(arr[i][j-k]!=1)
							break;
					}
					dp[i][j] += k-1;
				}
				ans = max(dp[i][j],ans);
			}
		}

		// for(i=0;i<n;i++){
		// 	for(j=0;j<m;j++){
		// 		cout<<dp[i][j]<<" ";
		// 	}
		// 	cout<<"\n";
		// }
		cout<<ans;


	}
	return 0;
}