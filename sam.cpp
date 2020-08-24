#include<bits/stdc++.h>
using namespace std;



int main(){
	string s;
	cin>>s;
	int n = s.size();
	long long arr[n][n] ;
	int number [n][n] ;
	memset(arr,0,sizeof(arr));
	memset(number,0,sizeof(number));
	
	for(int i = 0; i<n; i++){
		arr[i][i] = (s[i] - '0');
		number[i][i] = arr[i][i] ;
	}


	for(int i = 1; i<n ; i++){

		for(int j = 0; j<n-i; j++){
			int k = j + i;

			number[j][k] = number[j][k-1]*10 + number[k][k];

			arr[j][k] = arr[j][k-1] + arr[j+1][k] - arr[j+1][k-1] + number[j][k];		
						
		}

	}

	for(int i = 0; i<n; i++){
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<" ";
		cout<<"\n";
	}

	// for(int i = 0; i<n; i++){
	// 	cout<<arr[i]<<" ";
	// }

	cout<<arr[0][n-1];
	return 0;
}