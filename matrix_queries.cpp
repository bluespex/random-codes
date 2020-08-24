#include<bits/stdc++.h>
using namespace std;

#define int long long
#define push_back pb

const int N = 100005;

int mod;
vector<vector<int> > temp(2,vector<int> (2,0));
vector<vector<vector<int> > > a ( N, vector<vector<int> >( 2 , vector<int>(2) ) );

vector<vector<int> > m_mul(vector<vector<int> > a, vector<vector<int> > b){
	vector <vector<int> > rv (2, vector<int> (2,0));
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				rv[i][j] += (a[i][k] * b[k][j])%mod;
				rv[i][j] %= mod;
			}
		}	
	}
	return rv;
}

struct segmentTree
{
	vector< vector<vector<int> > > st;
	void init(int n){
		st.resize( 4*n );
	}
	void build(int start, int end, int node){			
		if(start == end){
			st[node] = a[start];
			return;
		}
		int mid = start + ((end-start)>>1);
		build(start,mid,2*node+1);
		build(mid+1,end,2*node+2);
		st[node] = m_mul(st[2*node+1] , st[2*node+2]);
	}
	vector<vector<int> > query(int start,int end,int node, int left, int right){
		if( right < start || left > end){
			return temp;
		}
		if(end<=right && start>=left){
			return st[node];
		}

		int mid = start + ((end - start)>>1);
		return m_mul( query(start,mid,2*node+1,left,right) , query(mid+1,end,2*node+2,left,right) );
	}
}g;

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int i,j,k,n,m,ans=0;
	cin>>mod;
	cin>>n;
	int t; cin>>t; 
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i][0][0]>>a[i][0][1]>>a[i][1][0]>>a[i][1][1];
	}
	g.init(n);
	g.build(0,n-1,0);

	temp[0][0] = temp[1][1] = 1;

	while(t--)
	{
		int l,r;
		cin>>l>>r;
		vector <vector<int> > rv = g.query(0,n-1,0,l-1,r-1);
		for(int i = 0; i < 2; i++){
			for(int j = 0; j<2; j++){
				cout<<rv[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}