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
	
	int n;
	cin>>n;
	int t; cin>>t; 
	string s;
	cin>>s;

	while(t--)
	{
		int l,r,k,ans=0;
		cin>>l>>r;
		map<char,int> m;
		for(int i = l-1;i<r;i++){
			m[s[i]]++;
		}

		for(auto ele:m){
			ans ^= ele.second;
		}
		cout<<ans<<"\n";

	}
	return 0;
}