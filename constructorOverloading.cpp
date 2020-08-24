#include<iostream>
using namespace std;

class A{
    int a;

	A(int b){
        a = b;
	   cout<<"private constructor is invoked\n";
	   display();
    }


public:
    A(){
        a = 0;
	  A d(10) ;
    }
    A(A& c){
        a = c.a;
    }
    void display(){
        cout<<a<<"\n";
    }
};

int main()
{
    A one,three;
    three = A(one);
    one.display();
    three.display();
    return 0;
}
