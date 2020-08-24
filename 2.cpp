#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        int t=0;
        cin>>n;
        int arr[n];
        stack<int> s;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i==0){
              s.push(arr[i]);  
            }else{
                while((!s.empty())&&arr[i]<s.top()){
                    t++;
                    s.pop();
                }
                s.push(arr[i]);
            }
        }
        
        cout<<t<<"\n";
    }
    return 0;
}