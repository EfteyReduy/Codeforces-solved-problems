#include<bits/stdc++.h>
using namespace std;


main()
{
    double a1, a2, a3, a4, a5, a6;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a1>>a2>>a3>>a4>>a5>>a6;
        a1=a1*a1;
        a2=a2*a2;
        a3=a3*a3;
        a4*=a4;
        a5*=a5;
        a6*=a6;
        double v=a1*a5*(0-a1 +a2+ a3+ a4- a5+ a6);
        v=v+(a2*a6*(a1- a2+ a3+ a4+ a5- a6))+(a4*a3*(a1+ a2- a3- a4+ a5+ a6));
        v-=(a1*a2*a4+a3*a2*a5+a1*a3*a6+a5*a4*a6);
        v/=144;
        cout<<fixed<<setprecision(5);
        cout<<sqrt(v)<<endl;
    }
}
