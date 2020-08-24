#include<bits/stdc++.h>
using namespace std;

#define int long long
#define push_back pb

const int N = 50;
vector<int> dp1(N,-1);
vector<int> dp2(N,-1);

int number(int n,int x){
	if(n==0){
		return 1;
	}
	if(x==1){
		if(dp1[n-1] == -1){
			dp1[n-1] = number(n-1,1);
		}
		if(dp2[n-1] == -1){
			dp2[n-1] = number(n-1,2);
		}
		return dp1[n-1] + dp2[n-1];
	}else{
		if(dp1[n-1] == -1){
			dp1[n-1] = number(n-1,1);
		}
		return dp1[n-1];
	}
	
}


int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif

	// dp1[0] = 1;
	// dp2[0] = 1;
	
	int t; cin>>t;
	for(int i=1;i<=t;i++)
	{
		int j,k,n,m,ans=0;
		cin>>n;
		cout<<"#"<<i<<" : "<< number(n-1,1) + number(n-1,2)<<"\n";
	}

	return 0;
}