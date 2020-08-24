#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define mod 1000000007

ll mod_expo(ll a, ll b){
		ll ans=1;
		
		while(b){
			if(b&1){
				ans = (ans*a)%mod;
			}
			a = (a*a)%mod;
			b = b/2;
		}
		return ans%mod;
}

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	//int t; cin>>t; while(t--)
	{
		int i,j,r,n;
		cin>>n>>r;
		ll ans = r+1;
		for(int i=2; i < n-r+1; i++){
			ans = (ans * (r+i)%mod ) * (mod_expo(i,mod-2) % mod);
			ans = ans%mod;
		}
		cout<<ans;

	}
	return 0;
}