#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;

char a[N];

struct segmentTree
{
	vector<vector<int> > st;
	void init(int n){
		st.resize(4*n,vector<int>(26,0));
	}
	void build(int start, int end, int node){			
		if(start == end){
			st[node][a[start] - 'a'] = 1;
			return;
		}
		int mid = start + ((end-start)>>1);
		build(start,mid,2*node+1);
		build(mid+1,end,2*node+2);
		vector<int> temp(26,0);
		for(int i=0;i<26;i++){
			temp[i] = st[2*node+1][i] + st[2*node+2][i];
		}
		st[node] = temp;
	}
	vector<int> query(int start,int end,int node, int left, int right){
		if( right < start || left > end){
			vector<int> temp(26,0);
			return temp;
		}
		if(end<=right && start>=left){
			return st[node];
		}

		int mid = start + ((end - start)>>1);
		vector<int> l = query(start,mid,2*node+1,left,right);
		vector<int> r = query(mid+1,end,2*node+2,left,right);
		vector<int> temp(26,0);
		for(int i=0;i<26;i++){
			temp[i] = l[i] + r[i];
		}
		return temp;
	}
	void update(int start,int end,int node,int index,char value){
		if(start == end){
			a[index] = value;
			fill(st[node].begin(), st[node].end(),0);
			st[node][value - 'a'] = 1;
			return;
		}
		int mid = start + ((end-start)>>1);
		if(index<=mid){
			update(start,mid,2*node+1,index,value);
		}else{
			update(mid+1,end,2*node+2,index,value);
		}
		vector<int> temp(26,0);
		for(int i=0;i<26;i++){
			temp[i] = st[2*node+1][i] + st[2*node+2][i];
		}
		st[node] = temp;
	}
}g;

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int i,j,k,n,m,t,ans=0;
	cin>>n>>t;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	g.init(n);
	g.build(0,n-1,0);
	while(t--)
	{
		int ch;
		cin>>ch;
		if(ch == 1){
			int l;
			char x;
			cin>>l>>x;
			g.update(0,n-1,0,l-1,x);
		}else if(ch == 2){
			int l,r;
			cin>>l>>r;
			int even=0,odd=0;

			vector<int> temp = g.query(0,n-1,0,l-1,r-1);
			for(i=0;i<26;i++){
				if(temp[i]%2 == 0){
					even++;
				}else{
					odd++;
				}
			}
			if(odd<=1){
				cout<<"yes\n";
			}else{
				cout<<"no\n";
			}

		}


	}
	return 0;
}