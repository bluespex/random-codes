#include<iostream>
using namespace std;
class weight{
int kilogram;
int gram;

public:
void getdata ();
void putdata ();
void sum_weight (weight,weight) ;
} ;

void weight :: getdata(){
cout<<"Kilograms:";
cin>>kilogram;
cout<<"Grams:";
cin>>gram;
}
void weight :: putdata (){
cout<<kilogram<<" Kilograms and "<<gram<<" grams \n";
}

void weight :: sum_weight(weight wl,weight w2){
gram = wl.gram + w2.gram;
kilogram=gram/1000;
gram=gram%1000;
kilogram+=wl.kilogram+w2.kilogram;
}

int main (){
weight wl,w2 ,w3;
cout<<"Enter weight in kilograms and grams\n";
cout<<"\n Enter weight #1 " ;
wl.getdata();
cout<<" \n Enter weight #2 " ;
w2.getdata();
w3.sum_weight(wl,w2);
cout<<"/n Weight #1 = ";
wl.putdata();
cout<<"Weight #2 = ";
w2.putdata();
cout<<"Total Weight = ";
w3.putdata();
return 0;
}
