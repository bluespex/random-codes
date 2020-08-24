#include<iostream>
using namespace std;


int main(){
	int n;
	cin>>n;
	int dp[n] = {};
	// int arr[n] = {1,3,2,5};
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	dp[1] = arr[0];

	for(int i=2;i<=n;i++){
		int max = arr[0];
		for(int j=0; j<i;j++){
			int cost = 0;
			cost = arr[j] + dp[i-j-1];
			if(cost>max){
				max = cost;
			}
		}
		dp[i] = max;
	}

	cout<<dp[n];
	return 0;
}