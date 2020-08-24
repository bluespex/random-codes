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
		ll i,j,k,n,ans;
		bool check = false;
		cin>>n>>ans;
		vector<ll> v(n);
		for (ll i = 0; i < n; ++i)
		{
			cin>>v[i];
		}

		ll total = (1<<n);

		for(ll i =1; i<total; i++){
			ll sum = 0;
			ll j=0;
			ll bin = i;
			while(bin){
				if(bin&1){
					sum += v[j];
				}
				j++;
				bin = bin>>1;
			}
			if(sum == ans){
				check = true;
				break;
			}
		}

		(check) ? cout<<"Yes\n" : cout<<"No\n";

	}
	return 0;
}