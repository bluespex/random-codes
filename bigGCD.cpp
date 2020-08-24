#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

int gcd(int a,int b){
	if(a==0){
		return b;
	}
	return gcd(b%a,a);
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
		int i,j,k,n,m_=0,ans=0;
		cin>>n;
		string m;
		cin>>m;
		if(n == 0){
			cout<<m;
			return 0;
		}
		for(auto ele:m){
			m_ = ((m_ * 10)%n + (ele - '0')%n )%n;
		}
		cout<<gcd(m_,n);


	}
	return 0;
}