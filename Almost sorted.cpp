#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n] ;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int change=0;
    vector <int> index;
    int arr2[n] = arr;
    sort(arr2,arr2+n);
    bool continuous = true;
    for(int i=0;i<n;i++){
        if(arr2[i]!=arr[i]){
            change++;
            index.push_back(i);
            if(index[change-1]+1!=i) continuous=false;
        }
    }

    if(change==2){
        cout<<"yes\nswap "<<index[0]+1<<" "<<index[1]+1;
        return 0;
    }else{
        if(continuous){
            int n2=index.size();
            for(int i=0;i<n2/2;i++){
                if(arr[index[0]]!=arr2[index[n2-i]]){
                    break;
                }
            }
            if(i==n2){
                cout<<"yes\nreverse "<<index[0]+1<<" "<<index[n2-1]+1;
                return 0;
            }
        }
    }

    sort(arr2, arr2+n, greater<int>()); 
    continuous = true;
    for(int i=0;i<n;i++){
        if(arr2[i]!=arr[i]){
            change++;
            index.push_back(i);
            if(index[change-1]+1!=i) continuous=false;
        }
    }

    if(change==2){
        cout<<"yes\nswap "<<index[0]+1<<" "<<index[1]+1;
        return 0;
    }else{
        if(continuous){
            int n2=index.size();
            for(int i=0;i<n2/2;i++){
                if(arr[index[0]]!=arr2[index[n2-i]]){
                    break;
                }
            }
            if(i==n2){
                cout<<"yes\nreverse "<<index[0]+1<<" "<<index[n2-1]+1;
                return 0;
            }
        }
    }
    cout<<"no";
    return 0;
}
