#include<iostream>
using namespace std;

int main(){
	int arr[3][3] = { {1,2,3},
					  {4,8,2},
					  {1,5,3}
					};

	int dp[3][3] = {};

	dp[0][0] = arr[0][0];

	for( int i = 0; i < 3; i++ ){
		for( int j = 0; j < 3; j++){
			if( i == 0 && j == 0 ) continue;

			if( i == 0 ){
				dp[i][j] = arr[i][j] + dp[i][j-1];
			}

			if( j == 0 ){
				dp[i][j] = arr[i][j] + dp[i-1][j];
			}

			if( i >= 1 && j >= 1){
				dp[i][j] = arr[i][j] + min( dp[i][j-1], dp[i-1][j] );
			}	
		}
	}
	for( int i = 0; i < 3; i++){
		for( int j = 0; j < 3; j++ ){
			cout<< dp[i][j] <<" ";

		}
		cout<< "\n";
	}
	cout << dp[2][2];
	return 0;
}