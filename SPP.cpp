#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

int mod = 1e9;

int sz;
struct Mat
{
	
	vector<vector<int> > m;

	Mat()
	{
		m.resize(sz,vector<int> (sz,0));
	}	

	// void Matr(int i)
	// {
	// 	m.clear();
	// 	m.resize(sz,vector<int> (sz,i));
	// }

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

Mat solve(int n, vector<int>& c)
{
	Mat r, a;
	r.eye();
	a.m[0][0] = c[0];
	for(int i=1;i<sz;i++){
		a.m[0][i] = c[i];
		a.m[i][i-1] = 1;
	}
	//a.m[0][0] = a.m[0][sz - 1] = a.m[1][0] = 1;
	while (n)
	{
		if (n & 1)
			r = r * a;
		a = a * a;
		n >>= 1;
	}

	// Mat ans;
	// for(int i=0;i<sz;i++){
	// 	cin>>ans.m[i][0];
	// }
	// ans = r*ans;

	// for(int i=0; i<sz;i++){
	// 	cout<<ans.m[i][0]<<"\n";
	// }
	return r;
	
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
		cin>>k;
		sz = k;
		vector<int> c(k);
		Mat b;
		for(i=0;i<k;i++)
			cin>>b.m[k-i-1][0];
		for(i=0;i<k;i++)
			cin>>c[i];

		cin>>m>>n>>mod;
		for(i=m;i<=n;i++){
			if(i<=k){
				ans += b.m[k-i][0]%mod;
				continue;
			}
			
			Mat temp = solve(i-k,c) * b;
			ans += temp.m[0][0]%mod;

		}
		cout<<ans%mod<<"\n";


	}
	return 0;
}