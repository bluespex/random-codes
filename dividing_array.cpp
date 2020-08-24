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
		ll i,j=0,k=0,n,max=0,minimum=0;
		cin>>n;
		vector<ll> v(n);
		for(ll i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v.begin(), v.end());
		i=0;j=n-1;
		while(j>i){
			max += abs(v[j]-v[i]);
			i++;
			j--;
		}
		j=n-1;
		while(j>=1){
			minimum += abs(v[j] - v[j-1]);
			j -= 2;
		}
		cout<<minimum<<" "<<max<<"\n";

	}
	return 0;
}