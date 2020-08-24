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
		ll i,j,k,n,ans=0,max_x=0,max_y=0;
		cin>>n;
		vector<ll> x(n);
		vector<ll> y(n);
		for(i = 0; i<n; i++){
			cin>>x[i];
			cin>>y[i];
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());

		for(i=1;i<n;i++){
			max_x = max(max_x,x[i]-x[i-1]);
			max_y = max(max_y,y[i]-y[i-1]);
		}
		cout<<(max_y-1)*(max_x-1);
	}
	return 0;
}