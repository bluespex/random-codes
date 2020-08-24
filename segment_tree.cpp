#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 200005;

int a[N];

struct segmentTree
{
	vector<int> st;
	void init(int n){
		st.resize(4*n);
	}
	void build(int start, int end, int node){			//start at 0,n-1,0  {0th node for the segment tree vector.}
		if(start == end){
			st[node] = a[start];
			return;
		}
		int mid = start + ((end-start)>>1);
		build(start,mid,2*node+1);
		build(mid+1,end,2*node+2);
		st[node] = st[2*node+1] + st[2*node+2];
	}
	int query(int start,int end,int node, int left, int right){
		if( right < start || left > end){
			return 0;
		}
		if(end<=right && start>=left){
			return st[node];
		}

		int mid = start + ((end - start)>>1);
		return query(start,mid,2*node+1,left,right) + query(mid+1,end,2*node+2,left,right);
	}
	void update(int start,int end,int node,int index,int value){
		if(start == end){
			a[index] = st[node] = value;
			return;
		}
		int mid = start + ((end-start)>>1);
		if(index<=mid){
			update(start,mid,2*node+1,index,value);
		}else{
			update(mid+1,end,2*node+2,index,value);
		}
		st[node] = st[2*node+1] + st[2*node+2];
	}
}g;

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	//int t; cin>>t; while(t--)
	{
		int i,j,k,n,ans=0;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		g.init(n);
		g.build(0,n-1,0);
		cout<<g.query(0,n-1,0,4,7);



	}
	return 0;
}