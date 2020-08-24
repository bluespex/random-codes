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
		int i,j,k,n,ans=0;
		cin>>n;
		vector<int> v(2*n);
		for(int i=0;i<2*n;i++){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		cout<<v[n-1];


	}
	return 0;
}