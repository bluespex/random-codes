#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int sum=0;
	    for(int j=0;j<n;j++){
	        int s2=0;
	        int arr2[n] ;
	        for(int i=0;i<n;i++){
	        	arr2[i]=arr[i];
	        }
    	    for(int i=j;i<n-1;i+=2){
    	        if(arr[i]>arr[i+1]){
    	            swap(arr2[i],arr2[i+1]);
    	        }
    	    }
    	    for(int i=0;i<n;i++){
    	        s2+=arr2[i]*(i+1);
    	    }
    	    sum=max(s2,sum);
    	    
	    }
	    cout<<sum<<"\n";
	}
	return 0;
}