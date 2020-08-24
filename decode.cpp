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
	
	//int t; cin>>t; while(t--)
	{
		int i,j=0,k,n,temp=0;
		cin>>n;
		cin>>k;
		std::vector<int> v(n);
		map <int,int> m;
		for(i=0; i<n; i++){
			cin>>v[i];
			m.insert(make_pair(v[i], i));
		}


		for(auto t = m.rbegin(); t!= m.rend(); t++){

			if(temp == k){
				break;
			}
			if(v[j]!=t->first){
				int x= t->second;
				m[v[j]] = x;
				m[v[x]] = j;
				swap(v[j],v[x]);
				temp++;
			}
			j++;
		}

		for(i=0; i<n; i++){
			cout<<v[i]<<" ";
		}



	}
	return 0;
}