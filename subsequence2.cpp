#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin>>q;
	while(q--){
		long long int n,k,tt;
        cin>>n>>k;
        tt=k;
        long long int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long int i=0,tmp=0;
        vector<int> idx;
        while(i<n && k>1){
            tmp+=a[i];;
            if(tmp%2==1){
                k--;
                idx.push_back(i+1);
                tmp=0;
            }
            i++;
        }
        if(k==1 && i<n){
            tmp=0;
            while(i<n){
                tmp+=a[i];
                i++;
            }
            if(tmp%2==1){
                k--;
                idx.push_back(n);
            }
        }
        if(k<=0 && idx.size()==tt){
            cout<<"YES"<<endl;
            for(int i=0;i<idx.size();i++){
                cout<<idx[i]<<" ";
            }
            cout<<endl;
        }else{
            cout<<"NO"<<endl;
        }
	}
	return 0;
}