#include<bits/stdc++.h>
using namespace std;
/*
double f(double x)
{
    return x*x-4*x-10;
}
*/

double f1(double x)
{
    return 2*x-4;
}
void secant()
{
    {
    double x1,x2,x3;
    cout<< " give x1, x2\n" ;
    cin>>x1>>x2;
    for(int i=0;i<10;i++)
    {


    x3=x2-(f(x2)*(x2-x1))/(f(x2)-f(x1));
    if(f(x3)==0)
    {
        cout<< "in secant method ans is = "<< x3<<endl;
        return ;
    }
    else
{
    x1=x2;
    x2=x3;
}
    }
cout<<"in secant method ans is = "<< x3<<endl;

    }
}

/*void newton_raphson()
{
    double x0=0,x1;
for(int i=0;i<10;i++){
    x1=x0-(f(x0)/f1(x0));
    if(f(x1)==0)
    {
      cout<<"in newton raphson method ans is = "<< x1<<endl;
      return;
    }
    x0=x1;
}
 cout<<"in newton raphson method ans is = "<< x1<<endl;
}*/
int main()
{
   secant();
   //newton_raphson();
}
