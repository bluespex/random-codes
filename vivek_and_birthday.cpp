#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second
vector<int> ans;
vector<int> visited;
vector<vector<int> > g;

void topo(int cur,int i,int p) {
	int check1 = 0;
	visited[cur] = 1;
	for (auto ele:g[cur]) {
		check1 = 1;
		if(visited[ele] == 1 && ele == p){
			ans.pb(i);
		}
		if (visited[ele]==0) {
			topo(ele,i+1,p);
		}
	}
	if(check1 == 0){
		ans.pb(1);
	}
	//order.pb(cur);
	// visited[cur] = 2;
}

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	//int t; cin>>t; while(t--)
	{
		int i,j,k,n,m,min=1e9;
		cin>>n>>m;
		visited.resize(n+1,0);
		g.resize(n+1);
		for(i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			g[x].pb(y);
		}

		for(i=1;i<=n;i++){
			visited.clear();
			visited.resize(n+1);
			// cout<<visited[i]<<"\n";
			// if(visited[i]){
			// 	continue;
			// }
			topo(i,1,i);
		}

		for(auto ele:ans){
			if(ele<min){
				min = ele;
			}
			//cout<<ele<<" ";
		}

		cout<<min;

	}
	return 0;
}