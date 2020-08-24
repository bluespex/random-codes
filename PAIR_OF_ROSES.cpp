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
	
	int t; cin>>t; while(t--)
	{
		int i,j,k,n,m;
		P ans = {0,INT_MAX};
		cin>>n;
		vector<int> v(n);
		for(i=0;i<n;i++){
			cin>>v[i];
		}
		cin>>m;
		sort(v.begin(), v.end());
		for(i=0;i<n;i++){
			j=i+1;
			while(j<n){
				if(v[i]+v[j]==m){
					if(ans.S - ans.F > j-i){
						ans.F = i;
						ans.S = j;
					}
				}
				if(v[i]+v[j]>m){
					break;
				}
				j++;
				
			}
		}
		cout<<"Deepak should buy roses whose prices are "<<v[ans.F]<<" and "<<v[ans.S]<<".\n";
	}
	return 0;
}