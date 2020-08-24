#include<iostream>
using namespace std;

int sud [9][9]=
    {{5,3,0,0,7,0,0,0,0},
     {6,0,0,1,9,5,0,0,0},
     {0,9,8,0,0,0,0,6,0},
     {8,0,0,0,6,0,0,0,3},
     {4,0,0,8,0,3,0,0,1},
     {7,0,0,0,2,0,0,0,6},
     {0,6,0,0,0,0,2,8,0},
     {0,0,0,4,1,9,0,0,5},
     {0,0,0,0,8,0,0,7,9}
    };

bool check(int sud[9][9],int r, int c, int x)
{
    for(int i=0;i<9;i++){
        if(sud[r][i]==x||sud[i][c]==x)
            return false;
    }

     for(int i=((r/3)*3);i<((r/3)*3)+3;i++){
            for(int j=((c/3)*3);j<((r/3)*3)+3;j++){
                if(sud[i][j]==x)
               return false;
            }

    }
    return true;
}

bool sudo(int sud[9][9],int r,int c)
{
    if(r==9){
         for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
               {
                   cout<<(sud[i][j])<<" ";
               }
                cout<<endl;
            } return true;
    }

    if(sud[r][c]!=0){
       return  sudo(sud,r,c+1);
    }
    if(c==9){
       return  sudo(sud,r+1,0);
    }
    for(int x=1;x<=9;x++){
        if(check(sud,r,c,x)==true){
            sud[r][c]=x;}
    }
            bool s=sudo(sud,r,c+1);
            if(s==true){
                return true;}
            sud[r][c]=0;





    return false;


}
int main()
{  
    sudo(sud,0,0);

    return 0;
}
