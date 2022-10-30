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
ll gcdExtended(ll a, ll b, ll * x, ll * y)
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


typedef long long ll;


///comparison structure to use customized set.............
struct cmpStruct {
    bool operator() (pair<int, int> const & lhs, pair<int, int> const & rhs) const
    {
        if(lhs.first!=rhs.first)
            return lhs.first < rhs.first;
        else{
            return lhs.second<rhs.second;
        }
    }
};

//set<pair<int, int>, cmpStruct> s;


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

void NO(){
    cout<<"NO"<<"\n";
}
void YES(){
    cout<<"YES"<<"\n";
}
void No(){
    cout<<"No"<<"\n";
}
void Yes(){
    cout<<"Yes"<<"\n";
}


main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        long long n=s.length();
        long long ans=n*(n+1)/2;

        int las=0;
        long long temp=0;
        for(int i=1; i<s.length(); i++)
        {
            int j=i, cou=0;
            if(s[i]==s[i-1] and s[i]!='?')
            {
                temp+=(i-las)*(n-i);
                las=i;
                continue;
            }

            while(s[j]=='?' and j<s.length())
            {
                cou++;
                j++;
            }
            if(cou)
            {
                ll x=0;
                if(j==n){
                    i=j;
                    continue;
                }
                if(cou%2)
                {
                    if(s[i-1]=='0' and s[j]=='1')
                    {
                        temp+=(i-las)*(n-j);
                        las=i;
                    }
                    else if(s[i-1]=='1' and s[j]=='0')
                    {
                        temp+=(i-las)*(n-j);
                        las=i;
                    }
                }
                else{
                    if(s[i-1]=='0' and s[j]=='0')
                    {
                        temp+=(i-las)*(n-j);
                        las=i;
                    }
                    else if(s[i-1]=='1' and s[j]=='1')
                    {
                        temp+=(i-las)*(n-j);
                        las=i;
                    }
                }
            }
            i+=cou;

        }
        cout<<ans-temp<<endl;
    }

    return 0;
}






