
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int itr;
    cout<< "give me the number of iterartor\n";
    cin>>itr;
    float  x[itr+1],y[itr+1],z[itr+1],Ex[itr+1],Ey[itr+1],Ez[itr+1],MaE[itr+1];

    x[0]=1.0/27*(85-6*0+0);
    y[0]=1.0/15*(72-6*x[0]-2*0);;
    z[0]=1.0/54*(110-x[0]-y[0]);
    for(int i=0;i<itr;i++)
    {
       x[i+1]=1.0/27*(85-6*y[i]+z[i]);
       y[i+1]=1.0/15*(72-6*x[i+1]-2*z[i]);
       z[i+1]=1.0/54*(110-x[i+1]-y[i+1]);
    }
    for(int i=0;i<=itr;i++)
    {
        cout<<x[i]<< ",, "<< y[i]<< ",, "<< z[i]<< endl;
    }
}
