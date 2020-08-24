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
		ll i,j=0,k=0,n,ans=0;
		cin>>n;
		vector<ll> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
			if(v[i] == 2){
			    j++;
			}
			if(v[i] == 0){
			    k++;
			}

		}

		ans = ((j*(j-1))/2) + ((k*(k-1))/2);

		cout<<ans<<"\n";

	}
	return 0;
}