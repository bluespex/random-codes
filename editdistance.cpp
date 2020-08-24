#include<iostream>
#include<string>
using namespace std;

int main(){
	string a = "sunday";
	string b = "saturday";
	int n = a.length();
	int m = b.size();

	int dp [n+1][m+1] = {0};
	for(int i = 0; i<m+1; i++){
		dp[0][i] = i;
	}

	for(int i = 0; i<n+1; i++){
		dp[i][0] = i;
	}

	for(int i =1; i<n+1; i++){
		for(int j = 1; j<m+1; j++){
			if(a[i-1]==b[j-1]){
				dp[i][j] = 0 + dp[i-1][j-1];
			}else{
				dp[i][j] = min( 	min(	(1 + dp[i-1][j-1]),
											(1 + dp[i-1][j])	),
									(1 + dp[i][j-1])
								);

			}
		}
	}

	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < m+1; ++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}

	cout<<dp[n][m];
	return 0;
}