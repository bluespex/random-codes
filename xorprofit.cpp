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
	
	//int t; cin>>t; while(t--)
	{
		int i,j,k,n,ans=0;
		cin>>i>>k;
		for(i;i<k;i++){
			for(j=i+1;j<=k;j++){
				if(i^j > ans){
					ans = i^j;
				}
			}
		}

		cout<<ans;


	}
	return 0;
}