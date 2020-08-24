#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int mod = 98765431;
int sz;
struct Mat
{
	
	vector<vector<int> > m;

	Mat()
	{
		m.resize(sz,vector<int> (sz,0));
	}	

	void Matr(int i)
	{
		m.clear();
		m.resize(sz,vector<int> (sz,i));
	}

	void eye()
	{
		for (int i = 0; i < sz; i++)
			m[i][i] = 1;
	}

	Mat operator* (const Mat &a) const
	{
		Mat r;
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				for (int k = 0; k < sz; k++)
					r.m[i][j] = (r.m[i][j] + m[i][k] * 1ll * a.m[k][j] + mod) % mod;
		return r;
	}
};

void solve(int n)
{
	Mat r, a;
	r.eye();
	a.Matr(1);
	for(int i=0;i<sz;i++){
		a.m[i][i] = 0;
	}
	//a.m[0][0] = a.m[0][sz - 1] = a.m[1][0] = 1;
	while (n)
	{
		if (n & 1)
			r = r * a;
		a = a * a;
		n >>= 1;
	}

	Mat ans;
	for(int i=0;i<sz;i++){
		cin>>ans.m[i][0];
	}
	ans = r*ans;

	for(int i=0; i<sz;i++){
		cout<<ans.m[i][0]<<"\n";
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
		int i,j,k,m;
		cin>>sz>>k;
		
		solve(k);


	}
	return 0;
}