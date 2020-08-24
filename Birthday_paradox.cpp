#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int t; cin>>t; while(t--)
	{
		int i=1,k,n;
		int day =365;
		float p=1;
		float prob;
		float den = 365;
		cin>>prob;
		n=0;
		while(p>(1-prob)){
			p*=(day/den);
			day--;
			
			n++;
		}
		cout<<n<<" ";
		
	}
	return 0;
}