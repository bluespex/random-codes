#include<bits/stdc++.h>
using namespace std;

#define int long long
#define push_back pb
#define F first
#define S second


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
		vector< pair<int,int> > v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i].F;
			v[i].S = i;
		}
		vector<int> temp(n,0);
		sort(v.begin(), v.end());
		for(auto ele:v){
			temp[ele.S] = 1;
			int sum = accumulate(temp.begin()+ele.S+1,temp.end(),0);
			ans+=sum;
		}
		cout<<ans<<"\n";

	}
	return 0;
}