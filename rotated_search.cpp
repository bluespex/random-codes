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
		ll i,j,k,n,temp=0,ans=0;
		cin>>n;
		vector<ll> v(n);
		unordered_map<ll,ll> m;
		for(ll i=0;i<n;i++){
			cin>>v[i];
			m[v[i]] = i;
		}
		
		cin>>k;
		
		if(m.find(k)!=m.end()){
			cout<<m[k];
		}


	}
	return 0;
}