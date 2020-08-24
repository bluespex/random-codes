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
		cin>>n>>m;
		vector<vector<P> > g(n+1);
		for(int i = 0;i<m;i++){
			int x,y,r;
			cin>>x>>y>>r;
			g[x].pb({r,y});
			g[y].pb({r,x});
		}
		int s;
		cin>>s;
		priority_queue <P , vector<P>, greater<P> > q;
		vector<int> min_distance(n+1,INT_MAX);
		min_distance[s] = 0;
		q.push({0,s});
		bool vis[n+1] = {false};
		while(!q.empty()){
			P node = q.top();
			q.pop();
			int dis = node.F;
			if(vis[node.S])
				continue;
			min_distance[node.S] = dis;
			vis[node.S] = true;
			
			for(auto ele:g[node.S]){
				q.push({ dis+ele.F , ele.S });	
			}
		}
		for(int i = 1;i<=n;i++){
			if(i==s)
				continue;
			if(min_distance[i] == INT_MAX)
				cout<<-1<<" ";
			else
				cout<<min_distance[i]<<" ";
		}
		cout<<"\n";

	}
	return 0;
}