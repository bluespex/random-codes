#include<iostream>
using namespace std;


int main(){
	int n;
	int x,y,z;
	cin>>n;
	cin>>x>>y>>z;
	int dp[n+1];
	dp[1] = 0;

	for(int i = 2; i<=n; i++){
		if(i%2==0){
			dp[i] = min( x + dp[i/2], y + dp[i-1]);
		}else{
			dp[i] = min( y + dp[i-1], dp[(i+1)/2] + x + z);
		}
	}

	cout<<dp[n];

	return 0;
}