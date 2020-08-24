#include<bits/stdc++.h>
using namespace std;

#define ll long long

int gcd(int a,int b){
	if(b==0){
		return a;
	}

	return gcd(b,a%b);
}

ll x,y,GCD;
void extended_gcd(ll a, ll b){
	if(b==0){
		x = 1;
		y = 0;
		GCD = a;
		return;
	}

	extended_gcd(b,a%b);
	ll x1 = x;
	x = y;
	y = x1 - floor(a/b)*y;
}

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	//int t; cin>>t; while(t--)
	{
		ll i,j,k,m,n,a,b,ans=0;
		cin>>a>>b;
		//cout<<gcd(x,y);
		//ax + by = gcd(a,b)
		extended_gcd(a,b);
		cout<<x<<" "<<y;


	}
	return 0;
}