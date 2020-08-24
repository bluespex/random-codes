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
	
	//int t; cin>>t; while(t--)
	{
		int a,b,c,n,ans=1;
		cin>>a>>b>>c;
		while(b){
			if(b&1){
				ans = (ans*a)%c;
			}
			a = (a*a)%c;
			b = b/2;
		}
		cout<<ans;


	}
	return 0;
}