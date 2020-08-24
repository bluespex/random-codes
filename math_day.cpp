#include<bits/stdc++.h>
using namespace std;

#define ll long long

// ll fact(ll b){
// 	ll ans=1;
// 	for(ll i=2;i<=b;i++){
// 		ans*=i;
// 	}
// 	return ans;
// }

ll mod_expo(ll a,ll b,ll c){
	ll ans = 1;
	while(b){
		if(b&1){
			ans = (ans*a)%c;
		}
		a = (a*a)%c;
		b = b/2;
	}
	return ans;
}

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int t; cin>>t; while(t--)
	{
		//int i,j,k,n,ans=0;
		ll a,b,c,n;
		cin>>a>>b>>c;
		ll ans = a;
		for(ll i=2;i<=b;i++){
			ans = mod_expo(ans,i,c);
		}
		cout<<ans%c<<"\n";


	}
	return 0;
}