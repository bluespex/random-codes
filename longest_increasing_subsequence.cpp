#include<iostream>
using namespace std;

//---------------------bottom up---------------------------------

int main(){
	int n;
	cin>>n;

	int arr[n] ;
	int dp[n];

	for(int i=0; i<n; i++){
		cin>>arr[i];
		dp[i] = 1;
	}

	int best = 0;
	for(int i=1; i<n; i++){
		int maximum = 0;
		for(int j=i-1; j>=0; j--){
			if(arr[i]>arr[j]){
				if(dp[j]>maximum){
					maximum = dp[j];
				}
			}

		}
		dp[i] += maximum;
		best = max(best,dp[i]);
	}

	cout<<best;

}