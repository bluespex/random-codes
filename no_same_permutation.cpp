#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	//int t; cin>>t; while(t--)
	{
		int i,j,k,n,m,ans=0;
		cin>>n;
		vector<int> v(n);
		for(i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v.begin(), v.end());
		for(i=0;i<n;i++)
			cout<<v[i]<<" ";
		cout<<"\n";
		while(next_permutation(v.begin(), v.end())){
			for(i=0;i<n;i++)
				cout<<v[i]<<" ";
			cout<<"\n";
		}


	}
	return 0;
}