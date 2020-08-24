#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second
#define ll long long

vector<int> arr;


int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif


	set<int> s;
	s.insert(1);
	for(auto ele:s){
		if(s.size() == 10005){
			break;
		}
		s.insert(ele*2);
		s.insert(ele*3);
		s.insert(ele*5);
		arr.pb(ele);
	}
	int t; cin>>t; while(t--)
	{
		int k,n,m,ans=0;
		cin>>n;
		cout<<arr[n-1]<<"\n";
	}
	return 0;
}