#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back


vector<int> bfs(vector<vector<int> > g, int source, int n){
	queue<int> q;
	vector<int> visited(n+1,-1);
	q.push(source);
	visited[source] = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		
		for(auto ele:g[node]){
			if(visited[ele] == -1){
				q.push(ele);
				visited[ele] = visited[node] + 6;
			}
		}
	}
	return visited;
}

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
		vector<vector<int> > g(n+1);
		for(i = 0; i<m; i++){
			int u,v;
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		int s;
		cin>>s;
		vector<int> vis = bfs(g,s,n);
		for(int i = 1;i<=n;i++){
			if(i == s)
				continue;
			cout<<vis[i]<<" ";
		}
		cout<<"\n";


	}
	return 0;
}