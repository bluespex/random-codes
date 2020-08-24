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
	
	int n;
	while(cin>>n && n)
	{
		int i,j,k,m;
		cin>>m;
		vector<vector<P> > g(n+1);
		for(int i = 0;i<m;i++){
			int x,y,r;
			cin>>x>>y>>r;
			g[x].pb({r,y});
			g[y].pb({r,x});
		}
		priority_queue <pair<double,int> > q;
		vector<double> max_probab(n+1,0);
		//min_distance[s] = 0;
		q.push({1.00,1});
		bool vis[n+1] = {false};
		while(!q.empty()){
			pair<double,int> node = q.top();
			q.pop();
			double dis = node.F;
			if(vis[node.S])
				continue;
			max_probab[node.S] = dis;
			vis[node.S] = true;
			
			for(auto ele:g[node.S]){
				q.push({ dis * (((double)ele.F)/100) , ele.S });	
			}
		}
		
		double ans = max_probab[n]*100;
		printf("%.6lf percent\n",ans);

		// int t;
		// cin>>t;
		// if(t==0){
		// 	return 0;
		// }

	}
	return 0;
}