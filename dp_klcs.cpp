#include<bits/stdc++.h>
using namespace std;

int dp [101][101][8];

int lcs(int arr[],int arr1[],int i,int j, int n,int m, int k){
	if(i==n||j==m){
		return 0;
	}
	if(dp[i][j][k]!=-1){
		return dp[i][j][k];
	}

	int ans = 0;
	if(arr[i] == arr1[j]){
		ans = 1 + lcs(arr,arr1,i+1,j+1,n,m,k);
	}else{
		if(k>0){
			ans = max(max(lcs(arr,arr1,i+1,j,n,m,k),lcs(arr,arr1,i,j+1,n,m,k)),lcs(arr,arr1,i+1,j+1,n,m,k-1) + 1);
		}else
			ans = max(lcs(arr,arr1,i+1,j,n,m,k),lcs(arr,arr1,i,j+1,n,m,k));
	}

	dp[i][j][k] = ans;

	return dp[i][j][k];

}

int main(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	int k;
	cin>>k;
	int arr[n];
	int arr1[m];

	memset(dp,-1,sizeof(dp));

	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	for(int i = 0; i<m; i++){
		cin>>arr1[i];
	}

	



	cout<<lcs(arr,arr1,0,0,n,m,k);
	
	return 0;
}