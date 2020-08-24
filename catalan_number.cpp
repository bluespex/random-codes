#include<bits/stdc++.h>
using namespace std;

#define ll long long

float fact(int a){
	float ans =1;
	for(int i=2;i<=a;i++){
		ans*=i;
	}
	return ans;
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
		float i,j,k,n,ans=1;
		cin>>n;
		// if(n==0){
		// 	cout<<1;
		// 	return 0;
		// }


		ans = fact(2*n)/(fact(n)*fact(n));
		ans = ans/n+1;

		cout<<ans;


	}
	return 0;
}