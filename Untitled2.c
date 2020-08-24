#include <iostream>
#include<stack>

using namespace std;

int main(){
    stack <int> pesticide,temp;
    bool check;
    int n,days=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        pesticide.push(t);
    }

    int t1,t2;
    while(true){
        check=true;
        t1=pesticide.top();
        pesticide.pop();
        while(!pesticide.empty()){
            t2=pesticide.top();
            pesticide.pop();
            if(t1<t2){
                temp.push(t1);
            }else{
                check=false;
            }
            t1=t2;
            if(pesticide.empty()){
                temp.push(t2);
            }
        }
        days++;
        if(check){
            break;
        }
        while(!temp.empty()){
            pesticide.push(temp.top());
            temp.pop();
        }

    }
    cout<<days-1;
    return 0;

}
