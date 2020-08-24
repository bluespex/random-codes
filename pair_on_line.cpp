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
		ll i,j,k,n,m,c,ans=0;
		cin>>n>>m>>c;
		vector<ll> v(n);
		unordered_map <int,int> y;
		unordered_map <int,int> freq;
		
		for(ll i =0;i<n;i++){
			cin>>v[i];
			freq[v[i]]++;
			y[v[i]] = m*v[i] + c;
		}

		for(i = 0;i<n;i++){
			//cout<<v[i]<<" "<<y[v[i]]<<"\n";
			ans += freq[y[v[i]]];
			if(v[i] == y[v[i]]) ans--;
		}


		cout<<ans;

	}
	return 0;
}