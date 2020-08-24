#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

int n,m;
vector<vector<int> > maze;
void path(int i, int j){
	if(i == n-1 && j == m-1){
		maze[0][0] = 1;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(maze[i][j] == -1)
					maze[i][j] = 0;
				cout<<maze[i][j]<<" ";
			}
			cout<<"\n";
		}
		exit(0);
		return;
	}
	if(j!=m-1 && maze[i][j+1] != -1){
		maze[i][j+1] = 1;
		path(i,j+1);
		maze[i][j+1] = 0;
	}
	if(i!=n-1 && maze[i+1][j] != -1){
		maze[i+1][j] = 1;
		path(i+1,j);
		maze[i+1][j] = 0;
	}

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
		int i,j,k,ans=0;
		cin>>n>>m;
		maze.resize(n,vector<int>(m,0));
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				char x;
				cin>>x;
				if(x=='O'){
					maze[i][j] = 0;
				}else{
					maze[i][j] = -1;
				}
			}
		}

		path(0,0);
		cout<<-1;


	}
	return 0;
}