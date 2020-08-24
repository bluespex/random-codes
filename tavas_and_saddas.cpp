#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second
int N = 1000000000;
map<int,int> m;
void rec(int p,int x){
	if(p>=N){
		return;
	}
	m[x*10 + 4] = 0;
	m[x*10 + 7] = 0;
	rec(p*10,x*10 + 4);
	rec(p*10,x*10 + 7);
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
		int i,j,k,n,ans=0;
		cin>>n;
		rec(1,0);
		cout<<distance(m.begin(),m.find(n)) + 1;
		

	}
	return 0;
}