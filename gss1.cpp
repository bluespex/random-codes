#include<bits/stdc++.h>
using namespace std;

#define int long long
#define push_back pb

const int N = 100005;

int a[N];

struct segmentTree
{
	vector<vector<int> > st;			// max , total_sum , prefix_sum , suffix_sum
	void init(int n){
		st.resize(4*n, vector<int> (4));
	}
	void build(int start, int end, int node){			
		if(start == end){
			st[node][0] = st[node][1] = st[node][2] = st[node][3] = a[start];
			return;
		}
		int mid = start + ((end-start)>>1);
		build(start,mid,2*node+1);
		build(mid+1,end,2*node+2);

		int total_sum = st[2*node+1][1] + st[2*node+2][1];
		int prefix_sum = max ( st[2*node+1][2] , st[2*node+1][1]+st[2*node+2][2] );
		int suffix_sum = max ( st[2*node+2][3] , st[2*node+2][1]+st[2*node+1][3] );
		int maximum = max({ st[2*node+1][0] , st[2*node+2][0] , st[2*node+1][3] + st[2*node+2][2]});

		st[node] = { maximum , total_sum , prefix_sum , suffix_sum};
	}
	vector<int> query(int start,int end,int node, int left, int right){
		if( right < start || left > end){
			vector<int> rv = { INT_MIN , 0 , INT_MIN , INT_MIN };
			return rv;
		}
		if(end<=right && start>=left){
			return st[node];
		}

		int mid = start + ((end - start)>>1);
		vector<int> temp(4);

		vector<int> q1 = query(start,mid,2*node+1,left,right);
		vector<int> q2 = query(mid+1,end,2*node+2,left,right);

		int total_sum = q1[1] + q2[1];
		int prefix_sum = max ( q1[2] , q1[1]+q2[2] );
		int suffix_sum = max ( q2[3] , q2[1]+q1[3] );
		int maximum = max({ q1[0] , q2[0] , q1[3] + q2[2]});

		temp = { maximum , total_sum , prefix_sum , suffix_sum};


		return temp;
	}
	
}g;

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	g.init(n);
	g.build(0,n-1,0);
	int t; cin>>t; while(t--)
	{
		int l,r;
		cin>>l>>r;
		vector<int> v = g.query(0,n-1,0,l-1,r-1);
		cout<<v[0]<<"\n";
	}
	return 0;
}