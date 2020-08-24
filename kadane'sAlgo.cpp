#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int dp[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
		dp[i] = arr[i];
	}
	int max = 0;

	if(dp[0]<0){
		dp[0] = 0;
	}
	
	for(int i = 1; i<n; i++){
		dp[i] += dp[i-1];
		if(dp[i]<0){
			dp[i] = 0;
			continue;
		}

		if(dp[i]>max){
			max = dp[i];
		}
	}

	cout<<max;
	return 0;
}