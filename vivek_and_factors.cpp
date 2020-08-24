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

	//sieve();
	// vector<vector<P> > ans(100001);
	// ans[0] = {{}};
	// ans[1] = {{1,1}};

	map<int,int> sum;
	for(int i=2; i<100001; i++){
		int ans = 0;
		for(int j=1;j*j<=i;j++){
			if(i%j == 0){
				if(j == i/j){
					ans += j;
					continue;
				}
				ans += i/j;
				ans += j;
			}
		}
		sum[ans] = i;
	}
	sum[1] = 1;
	
	int t,n;
	while(cin>>n && n!=0)
	{
		int i,j,k,m;
		// cin>>n;
		if(sum.count(n) == 0){
			cout<<-1<<"\n";
			//cin>>n;
			continue;
		}
		cout<<sum[n]<<"\n";





	}
	return 0;
}