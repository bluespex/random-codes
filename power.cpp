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
		ll i,j,k,x,n,ans=1;
		cin>>x>>n;
		while(n){
			if(n&1){
				ans *= x;
			}
			x *= x;
			n /= 2;
		}
		cout<<ans;

	}
	return 0;
}