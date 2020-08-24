#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
	    
	    long long n,m,sum=0,ans,t;
    	cin>>n>>m;
    	t=n/m;
    	m=m%10;
    	if(m%2==0){
    	    
    	    sum = m + (m*2)%10 + (m*3)%10 +(m*4)%10; 
    	    sum=(t/5)*sum;
    	    for(int i=1;i<=t%5;i++){
    	        sum+=(m*i)%10;
    	    }
    	}else{
    	    for(int i=1;i<10;i++){
    	        sum+=(m*i)%10;
    	    }
    	    sum=(t/10)*sum;
    	    for(int i=1;i<=t%10;i++){
    	        sum+=(m*i)%10;
    	    }
    	}
    	
    	cout<<sum<<"\n";
	}
	return 0;
}