#include<iostream>
using namespace std;

int lcs(int arr[],int arr1[], int n,int m, int k){
	if(n<0||m<0){
		return 0;
	}

	if(arr[n] == arr1[m]){
		return 1 + lcs(arr,arr1,n-1,m-1,k);
	}else{
		if(k>0){
			return max(max(lcs(arr,arr1,n-1,m,k),lcs(arr,arr1,n,m-1,k)),lcs(arr,arr1,n-1,m-1,k-1) + 1);
		}else
			return max(lcs(arr,arr1,n-1,m,k),lcs(arr,arr1,n,m-1,k));
	}

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

	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	for(int i = 0; i<m; i++){
		cin>>arr1[i];
	}

	cout<<lcs(arr,arr1,n,m,k);
	
	return 0;
}