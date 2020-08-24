#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int t; cin>>t; while(t--)
	{
		int i,j,k,n,ans=0;

		cin>>n;
		int arr[n];
		int dp[n];
		for(int i = 0; i<n; i++){
			cin>>arr[i];
			dp[i] = arr[i];
		}
		int max = 0;

		if(dp[0]<0){
			dp[0] = 0;
		}
		
		for(int i = 1; i<n; i++){
			dp[i] += dp[i-1];
			if(dp[i]<0){
				dp[i] = 0;
				continue;
			}

			if(dp[i]>max){
				max = dp[i];
			}
		}

		cout<<max<<"\n";

	}
	return 0;
}