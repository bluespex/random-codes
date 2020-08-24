#include<bits/stdc++.h>
using namespace std;



int main(){
	string s;
	cin>>s;
	int n = s.size();
	int arr[n];
    int number = 0;
	for(int i = 0; i<n; i++){
		arr[i] = (s[i] - '0');

		number += arr[i] * round(pow(10,n-1-i));
	}

	//cout<<number<<"\n";

	for(int i = 1; i<n ; i++){
		arr[i] += (arr[i-1]);
		for(int j = i-1; j>=0; j--){

            int x = number / round(pow(10,n-1-i));
            cout<<x/round(pow(10,i-j+1))<<"DSfsdf";
            x = x - (x/round(pow(10,i-j+1)));

            arr[i] += x;
						
		}
		arr[i] = arr[i]%1000000007;
		cout<<arr[i]<<" ";
	}

	// for(int i = 0; i<n; i++){
	// 	cout<<arr[i]<<" ";
	// }

	//cout<<arr[n-1];
	return 0;
}

