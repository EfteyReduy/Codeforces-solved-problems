
#include<bits/stdc++.h>


typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define PP pop_back
#define F first
#define S second
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define I insert
#define E erase
#define B back
#define C clear
#define SZ size
#define Vi vector<int>
#define Vll vector<ll>
#define Vpii vector<pair<int, int> >
#define Vpll vector<pair< ll, ll> >

#define precision(x) cout<<fixed<<setprecision(x);

using namespace std;


/// Siv's algorithm  ==================================================================================
///====================================================================================================
bool status[400000];
int dif[100000]={0};

void siv(int N) {
    int sq = sqrt(N);

    for (int i = 4; i <= N; i += 2) {
        status[i] = 1;
    }

    for (int i = 3; i <= sq; i += 2) {
        if (status[i] == 0) {
            for (int j = i * i; j <= N; j += i)
                status[j] = 1;
        }
    }

    status[1] = 1;
}

void setDif(){
    int j=0;
    for(int i=2; i<400000 ; i++)
    {
        if(status[i]==0)
        {
            dif[j]=(i);
            j++;
        }
    }
}
///==================================================================================================

//#define SSA(s) sort(s.begin(), s.end(), [](string a, string b) -> bool {return a.size() < b.size();});//sorting array of string in ascending order
//#define SSD(s) sort(s.begin(), s.end(), [](string a, string b) -> bool {return a.size() > b.size();});//sorting array of string in descending order



typedef long long ll;
///       pair         ///////////////////////////////////////////////
/*  Declaring array of pair::   pair<int , int>var[10];
    making pair :: var[i]=make_pair(a, b); or, var[i].first=a;
                                              var[i].second=b;

    Declaring vector of pair::  vector<pair<int, int> >
    Sorting array of pair :: sort(var, var+n, sortinrev );

*/
///Boolian function to sort an array of pair in descending order
bool sortinrev(const pair<int,int> &a,  const pair<int,int> &b)
{
       return (a.first > b.first);
}

///Boolian compare function for sorting array in descending order..
bool desc(const int &a, const int &b)
{
    return a>b;
}



main()
{
    //Start code from here........
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Vi graph[n+1];
        for(int i=0; i<n-1; i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].PB(b);
            graph[b].PB(a);
        }
        Pii p[n+1];
        for(int i=0; i<=n; i++)
        {
            p[i] = make_pair(graph[i].size(),i);
        }
        sort(p, p+n+1, sortinrev);


        if(p[0].first==p[1].first)
        {
            for(int i=0; i<=p[1].first; i++)
            {

                if(graph[p[1].second][i]!=p[0].second)
                {
                    cout<<p[1].second<<" "<<graph[p[1].second][i]<<endl;
                    cout<<p[0].second<<" "<<graph[p[1].second][i]<<endl;
                    break;
                }

            }
        }
        else
        {
            cout<<p[0].second<<" "<<graph[p[0].second][0]<<endl;
            cout<<p[0].second<<" "<<graph[p[0].second][0]<<endl;
        }
    }


    return 0;
}
