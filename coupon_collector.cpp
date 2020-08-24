#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int t; cin>>t; while(t--)
	{
		int n;
		cin>>n;
		float ans = 0;
		for(float i=1;i<=n;i++){
			//cout<<ans<<"\n";
			ans += 1.0/i;
		}
		ans *= n;
		printf("%.2f\n",ans);

	}
	return 0;
}