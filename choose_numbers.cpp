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
		ll i,j,k,n,ans=0;
		cin>>n;
		if(n<3){
			cout<<"NO";
			return 0;
		}
		vector<ll> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v.begin(), v.end());
		if(v[n-1] + v[n-2] >= v[0]){
			cout<<"YES";
		}else{
			cout<<"NO";
		}


	}
	return 0;
}