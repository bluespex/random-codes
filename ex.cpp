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
		int i=-1,j=0,k,n=0,ans=0;
		string a,b;
		cin>>a>>b;
		while((++i) < b.size()){
			j += (1<<i) * (b[2-i] - '0');
		}
		cout<<j;
		// while B is greater than 0:
  //       U = A XOR B
  //       V = A AND B
  //       A = U
  //       B = V * 2

	}
	return 0;
}