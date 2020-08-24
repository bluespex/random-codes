#include<iostream>
using namespace std;

class A{
    int a;
    
public:
    A(){
        cout<<"A is created\n";
    }
    
};

class B{
    int b;
    A obj;
public:
    B(){
        cout<<"B is created\n";
    }
}

int main()
{
    B object;
    return 0;
}