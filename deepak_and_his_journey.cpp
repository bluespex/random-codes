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
		int i,j,k,n,m,ans=0;
		cin>>n;
		vector<P> cost(n);
		vector<P> dist(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>cost[i].F;
			cost[i].S = i;
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>dist[i].F;
			dist[i].S = 0;
		}
		sort(cost.begin(), cost.end());

		for( i = 0; i < n; i++ ){
			int temp = 0;
			j = cost[i].S;
			while(dist[j].S != 1 && j<n){
				dist[j].S = 1;
				temp += dist[j].F;
				j++;
			}
			ans += cost[i].F * temp;
		}

		cout<<ans<<"\n";

	}
	return 0;
}