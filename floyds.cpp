#include<iostream>
#define INF 999;
using namespace std;

int min(int a,int b)
{
    if(a<b)return a;
    else return b;
}

void display(int D[][10],int num)
{
    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=num;j++)
        {
            cout<<D[i][j]<<" ";
        }
        cout<<endl;
    }
}

void floyds(int D[][10],int num)
{

    
    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=num;j++)
        {
            for(int k=1;k<=num;k++)
            {
                D[j][k]=min(D[j][k],D[j][i]+D[i][k]);
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the number of vertices in graph";
    cin>>n;
    int D[10][10];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>D[i][j];
        }
    }

    cout<<"The weighted matrix :"<<endl;
    display(D,n);

    floyds(D,n);
    cout<<endl<<"Shortest path matrix:"<<endl;
    display(D,n);
}