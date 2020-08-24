#include<bits/stdc++.h>
using namespace std;

int main(){
	int m,n,p;
	cin>>m>>n>>p;

	int arr[m+1][n+1] ;

	memset(arr,0,sizeof(arr));

	for(int i = 0; i<p; i++){
		int x,y;
		cin>>x>>y;
		arr[x][y] = -1;
	}

	for(int i = 1; i<=n; i++){
		if(arr[1][i] == -1){
			arr[1][i] = 0;
			break;
		}
		arr[1][i] = 1;
	}

	for(int i = 1; i<=m; i++){
		if(arr[i][1] == -1){
			arr[i][1] = 0;
			break;
		}
		arr[i][1] = 1;
	}

	for(int i = 2; i<=m; i++){
		for(int j = 2; j<=n; j++){
			if(arr[i][j]==-1){
				arr[i][j] = 0;
			}else{
				arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % 1000000007;
			}	
		}
	}

	// for(int i = 0 ;i<=m;i++){
	// 	for(int j =0;j<=n;j++){
	// 		cout<<arr[i][j]<<" ";

	// 	}
	// 	cout<<"\n";
	// }

	cout<<arr[m][n];
	return 0;
}