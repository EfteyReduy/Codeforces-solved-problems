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
int main(){
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[(2*n)+1];

        for(int i=0; i<2*n+1; i++)
        {
            arr[i]=0;
        }
        for(int i=0; i<n; i++)
        {
            int a;
            cin>>a;
            arr[a]=1;
        }
        int temp=0, ans=0, aan=n;
        set<int>s;
        for(int i=2*n; i>n; i--)
        {
            temp+=arr[i];
            aan-=arr[i]
            if(arr[i]==0)
            {
                temp--;
                //if(temp<0)
                    //temp=0;
            }
            s.insert(temp);
            ans=max(ans,temp);
        }
        temp=0;
        for(int i=1; i<=n; i++)
        {
            temp-=arr[i];
            if(arr[i]==0)
            {
                temp++;
                //if(temp<0)
                    //temp=0;
            }
            s.insert(temp);
            ans=max(ans,temp);
        }
        cout<<s.size()<<endl;
        cout<<n-ans<<endl;

    }

}

