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
		ll i,j,k,n,ans=0,max;
		cin>>n;
		vector<ll> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
			ans^=v[i];
		}
		max = ans;
		for(int i=0;i<n;i++){
			if((ans^v[i])>max){
				max = ans^v[i];
			}
		}
		cout<<max;

	}
	return 0;
}