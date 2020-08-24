#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n,min=1e9;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		int t=0;
		for(int j=0;j<n;j++){
			if(abs(arr[i]-arr[j])%2==1){
				t++;
			}
		}
		if(t<min){
			min=t;
		}
	}
	cout<<min;
	return 0;
}