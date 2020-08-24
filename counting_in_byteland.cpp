#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 102;
int val[N][N][N];

struct fenwick {
	int fn[N][N][N];
	// void init(int _n) {
	// 	n = _n + 10;
	// 	fn.clear(); fn.resize(n, 0);
	// }
	void add(int x,int y,int z, int val) {
		x++;y++;z++;// 1 based indexing

		for(int i=x;i<N; i += (i & (-i))){
			for(int j=y;j<N; j += (j & (-j))){
				for(int k=z;k<N; k += (k & (-k))){
					fn[i][j][k] += val;
				}
			}
		}

	}
	int sum(int x,int y,int z) {
		x++;y++;z++;// 1 based indexing
		int ans = 0;

		for(int i=x; i>0; i -= (i & (-i))){
			for(int j=y; j>0; j -= (j & (-j))){
				for(int k=z; k>0; k -= (k & (-k))){
					ans += fn[i][j][k];
				}
			}
		}

		return ans;
	}
	int query(int x1,int y1,int z1,int x2, int y2, int z2){
        int j4 = sum(x1-1, y1-1, z1-1);
        int j1 = sum(x2, y1-1, z1-1) - j4;
        int j2 = sum(x1-1, y2, z1-1) - j4;
        int j3 = sum(x1-1, y1-1, z2) - j4;

        return sum(x2, y2, z2) - sum(x2, y1-1, z2) - sum(x1-1, y2, z2) - sum(x2, y2, z1-1) + 2*j4 + j1 + j2 + j3;

    }
} bit;

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int i,j,k,n,m,people=0,ans = 0;
	cin>>n;

	for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            for(k=0;k<N;k++){
                bit.fn[i][j][k]=0;
            }
        }        
    }
	
	int t; cin>>t; while(t--)
	{
		int ch;
		cin>>ch;
		if(ch == 1){
			int x,y,z,val;
			cin>>x>>y>>z>>val;
			bit.add(x, y, z, val);
			people += val;
		}else{
			int x,y,z,X,Y,Z;
			cin>>x>>y>>z>>X>>Y>>Z;
			ans = bit.query(x,y,z,X,Y,Z);
			ans = people - ans;
			cout<<ans<<"\n";
		}

	}
	return 0;
}