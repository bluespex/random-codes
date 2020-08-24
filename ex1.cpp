#include<iostream>
	using namespace std;
	class Cars{
		int prices[10];

		public :
		  void getdata();
		  void display(int n);
	}c;

	void Cars:: display(int n){
    cout<<"Prices of the cars are:"<<endl;
    for(int i=0;i<n;i++){
        cout<<c.prices[i]<<endl;
    }
}
	void Cars :: getdata(){
		cout<<"Enter the numbers of the cars :"<<endl;
		int n;
		cin>>n;
		cout<<"Enter the prices of the cars :"<<endl;
		for(int i=0;i<n;i++){
			cin>>c.prices[i];
		}
		c.display(n);
}

int main(){
		c.getdata();
		return 0;
}
