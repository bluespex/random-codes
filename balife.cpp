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
	
	int n;
	while(cin>>n && n != -1)
	{
		int i,j,k,m,ans=0,avg=0;
		vector<int> v(n);
		for(i=0;i<n;i++){
			cin>>v[i];
			avg += v[i];
		}
		if(avg%n != 0){
			cout<<-1<<"\n";
			continue;
		}
		avg /= n;
		for(i = 0 ;i<n ; i++){
			v[i] = v[i] - avg;
		}
		ans = max(abs(v[0]),ans);
		for(i=1;i<n;i++){
			v[i] += v[i-1];
			ans = max(ans,abs(v[i]));
		}

		cout<<ans<<"\n";
	}
	return 0;
}