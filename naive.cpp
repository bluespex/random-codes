#include<iostream>
using namespace std;

int main(){
	string s1;
	string s2;

	cin>>s1>>s2;

	
	for(int i =0; i < s1.size() ; i++){
		int j =i;
		int k =i;
		while(j-i<s2.size()&&k<s1.size()){
			if(s1[k++] != s2[(j++)-i]){
				break;
			}
		}

		if(j-i == s2.size()){
			cout<< i <<" ";
		}
	}
	return 0;
}