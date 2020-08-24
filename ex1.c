#include<iostream>
	using namespace std;
	class Cars{
		int prices[10];

		public :
		  void getdata();
	}c;
	void Cars :: getdata(){
		cout<<"Enter the numbers of the cars :"<<endl;
		int n;
		cin>>n;
		cout<<"Enter the prices of the cars :"<<endl;
		for(int i=0;i<n;i++){
			cin>>c.prices[i];
		}
}
int main(){
		c.getdata();
		return 0;
}
