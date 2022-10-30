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
#define db(x) cout<<#x<<" = "<<x<<endl


using namespace std;


// function for extended Euclidean Algorithm
int gcdExtended(ll a, ll b, ll* x, ll* y)
{
	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}
	ll x1, y1;
	ll gcd = gcdExtended(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}


ll modInverse(ll a, ll m)
{
	ll x, y;
	ll g = gcdExtended(a, m, &x, &y);
	if (g != 1)
        return -1;
		//printf("Inverse doesn't exist");
	else
	{
		ll res = (x % m + m) % m;
		//printf("Modular multiplicative inverse is %d", res);
		return res;
	}
}


void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void print(int arr[], int n){
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



int main()
{
    int t=1;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n;
        ll arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cin>>m;
        ll brr[m];
        for(int i=0; i<m; i++)
        {
            cin>>brr[i];
        }
        long long an1=0, an2=0, tem=0;
        for(int i=0; i<n; i++)
        {
            tem+=arr[i];
//            if(tem<0)
//                tem=0;
            an1=max(tem,an1);
        }
        tem=0;
        for(int i=0; i<m; i++)
        {
            tem+=brr[i];
//            if(tem<0)
//                tem=0;
            an2=max(tem,an2);
        }
        cout<<an1+an2<<endl;

    }

}

