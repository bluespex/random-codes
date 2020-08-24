#include<iostream>
using namespace std;

int dp[100001];

int main(){
	int n;
	cin>>n;
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;
	for(int i = 4; i<=n;i++){
		if(i%6==0){
			dp[i] = 1+min(min(dp[i/2],dp[i/3]),dp[i-1]);
		}else if(i%2==0){
			dp[i] = 1 + min(dp[i/2],dp[i-1]);
		}else if(i%3 == 0){
			dp[i] = 1+min(dp[i/3],dp[i-1]);
		}else{
			dp[i] = 1+dp[i-1];
		}
	}
	cout<<dp[n];
	return 0;
}