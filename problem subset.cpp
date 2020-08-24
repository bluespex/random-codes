#include <iostream>
using namespace std;

int main() {
	int q;
	cin>>q;
	while(q--){
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		bool check = true;
		int t=0;
		int arr2[k];
		
		for(int i=0;i<k;i++){
			if(t>=n){
				cout<<"NO\n";
				check=false;
				break;
			}
			int temp=arr[t];
			while(temp%2==0){
				temp+=arr[++t];
				if(t>=n){
					cout<<"NO\n";
					check=false;
					break;
				}
			}
			arr2[i]=++t;	
		}
		
		if(check){
			cout<<"YES\n";
			for(int i=0;i<k;i++){
				cout<<arr2[i]<<" ";
			}
			cout<<"\n";
		}
		
	}
	return 0;
}