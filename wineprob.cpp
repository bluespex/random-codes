#include<iostream>
#include<algorithm>
using namespace std;

int dp[5][5] = {};


// -----------------memoization---------------------

// int memo[5][5] = {};
// int maxprofit(int arr[],int i,int j,int year){
// 	if(i>j){
// 		return 0;
// 	}

// 	if(memo[i][j] != -1) return memo[i][j];

// 	int a1 = year*arr[i] + maxprofit(arr,i+1,j,year+1);
// 	int a2 = year*arr[j] + maxprofit(arr,i,j-1,year+1);
// 	memo[i][j] = max(a1,a2);

// 	return memo[i][j];
// }
//----------------------------------------------------


int main(){
	int arr[10] = {2,3,5,1,4};

//greedy   ------------  wrong

	// int n = 4;
	// // int profit = 0;
	// // int i=0,j=3;
	// // int year = 1;
	// // while(i<=j){
	// // 	if(arr[i]<arr[j]){
	// // 		profit += arr[i++]*(year++);
	// // 	}else{
	// // 		profit += arr[j--]*(year++);
	// // 	}
		
	// // }


//------------------bottom-up-------------------------------------------

	int year = 4;
	for(int i=0;i<5;i++){
		dp[i][i] = arr[i]*5;
	}


	for(int j = 1;j<5;j++){
		int i=0;
		while(i!=5){
			int k=i+j;
			if(k<5){
				dp[i][k] = max(arr[k]*year + dp[i][k-1] , arr[i]*year +dp[i+1][k]);
			}
			i++;
		}
		year--;

	}

	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}

	cout<<"\n"<<dp[0][4];

	// for(int i=0;i<5;i++){
	// 	for(int j=0;j<5;j++){
	// 		memo[i][j] = -1;
	// 	}
	// }

	// cout<<"profit"<<maxprofit(arr,0,4,1)<<"\t"<<cnt;



	return 0;
}