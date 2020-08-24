#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define F first
#define S second


int bfs(vector<vector<int> > g, int source, int n){
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
				visited[ele] = visited[node] + 1;
			}
		}
	}
	return visited[100];
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
		cin>>n;
		map<int,int> ladder;
		map<int,int> snake;
		for(i = 0;i<n;i++){
			int temp;
			cin>>temp;
			cin>>ladder[temp];
		}
		cin>>m;
		for(i = 0;i<m;i++){
			int temp;
			cin>>temp;
			cin>>snake[temp];
		}
		vector<vector<int> > g(101);
		for(i = 1; i<100; i++){
			for(j = 1;j<=6;j++){
				if(i+j>100)
					continue;

				int end = i+j;

				if(ladder.find(i+j) != ladder.end()){
					end = ladder[i+j];
				}else if(snake.find(i+j) != snake.end()){
					end = snake[i+j];
				}
				g[i].pb(end);
			}
		}
		cout<<bfs(g,1,100)<<"\n";


	}
	return 0;
}