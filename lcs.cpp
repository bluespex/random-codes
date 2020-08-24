#include<iostream>
#include<string>
using namespace std;


// int lcs(string s1, string s2, int i, int j, int m, int n){
// 	if(i==m||j==n){
// 		return 0;
// 	}

// 	if(s1[i]==s2[j]){
// 		cout<<s1[i];
// 		return 1+lcs(s1,s2,i+1,j+1,m,n);
// 	}

// 	return max(lcs(s1,s2,i+1,j,m,n), lcs(s1,s2,i,j+1,m,n));
// }

int lcs_bu(string s1,string s2, int m, int n){
	int arr[m+1][n+1] ;

	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
			arr[i][j] = 0;
		}
	}

	for(int i=m-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			if(s1[i] == s2[j]){
				arr[i][j] = 1+arr[i+1][j+1];
			}else{
				
				arr[i][j] = max(arr[i][j+1],arr[i+1][j]);
			}
			
		}
	}

	cout<<arr[0][0]<<"\n";


	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;

}


int main(){

	string s1 = "nematode";
	string s2 = "empty";

	int n = s2.size();
	int m = s1.size();

	lcs_bu(s1,s2,m,n);
	return 0;
}