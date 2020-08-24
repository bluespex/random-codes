#include <iostream>
using namespace std;

class Batch{

    public :
    int marks;

    static int allmax;
    static int yearmax;


    void update(){
        yearmax = marks>yearmax ? marks : yearmax;
        allmax = yearmax>allmax ? yearmax : allmax;
    }


}b[4];

int Batch::allmax = 0;
int Batch::yearmax = 0;

int main() {

    //array for storing the yearsmax and to calculate the allmax
    int max[4];
    Batch b[3];
    //for respective batches of the year
    for(int i=0;i<3;i++){

        cout<<"Enter the marks of the students for batch:"<<i+1<<endl;
        for(int j=0;j<5;j++){
            cin>>b[i].marks;
            b[i].update();
        }
        cout<<"Years Maximum marks is :"<<Batch::yearmax<<endl;
        max[i] = Batch::yearmax;
        Batch::yearmax = 0;
    }

    cout<<"Maximum marks of all batches are :"<<Batch::allmax<<endl;

    cout<<"Maximum Scholarship is :"<<Batch::allmax * 10000;
    return 0;
}
