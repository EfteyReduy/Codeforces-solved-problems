#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;
typedef set<int> si;
typedef set<ll> sll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
const double pi = acos(-1.0);
const long long INF = 2e18;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define in insert
#define endl "\n"
#define sqr(a) ((a) * (a))
#define jor(a) !(a&1)// jor means EVEN number
#define bjor(a) (a&1)// bjor means ODD number
#define all(a)  a.begin(), a.end()
#define mem(arr, b) memset(arr, b, sizeof(arr)) //memset only for -1 and 0
//fill(a, a+n, 5) //fill for any value
#define for0(i,b) for(int i=0;i<(b);i++)
#define for1(i,b) for(int i=1;i<=(b);i++)
#define forab(i,a,b) for(int i=(a);i<=(b);i++)
#define forba(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fileRead freopen("input.txt", "r", stdin);
#define fileWrite freopen("output.txt", "w", stdout);
void print(int a[], int n){ // for testing or debugging
    for(int i=0;i<n;i++)cout<<a[i]<<" "; cout<<endl;
}
//-------------------------------------------------------------------

int main()
{
    IOS;
    int tc = 1;
    cin>>tc;
    while(tc--)
    {
        ll n; cin>>n;
        vll pos, neg;
        for0(i,n){
            int x; cin>>x;
            if(x<0) neg.pb(x);
            else pos.pb(x);
        }
        sort(all(pos)); sort(all(neg));
        ll N = neg.sz, P = pos.sz;
        int c=0;
        ll ans=1;
        if(P==0){
           forba(i, neg.sz-1, 0)
           {
               if(c==5) break;
               ans*=neg[i], c++;
           }
           cout<<ans<<endl;
        }
        else if(N==0){
           forba(i, pos.sz-1, 0)
           {
               if(c==5) break;
               ans*=pos[i], c++;
           }
           cout<<ans<<endl;
        }
        else if(N==1){
            ll tem=1;
            forba(i, pos.sz-1, 0)
            {
               if(c==5) break;
               tem*=pos[i], c++;
            }
            if(c==5) cout<<tem;
            else cout<<tem*neg[0];
            cout<<endl;
        }
        else if(N==2){
            ll tem1=-1e18;
            if(P>2) tem1= neg[0]*neg[1]*pos[P-1]*pos[P-2]*pos[P-3];
            ll tem=1;
            forba(i, pos.sz-1, 0)
            {
               if(c==5) break;
               tem*=pos[i], c++;
            }
            if(c==5) cout<<max(tem,tem1)<<endl;
            else cout<<tem1<<endl;
        }
        else if(N==3){
            ll tem1=-1e18;
            if(P>2) tem1= neg[0]*neg[1]*pos[P-1]*pos[P-2]*pos[P-3];
            ll tem=1;
            forba(i, pos.sz-1, 0)
            {
               if(c==5) break;
               tem*=pos[i], c++;
            }
            ll tem2=-1e18;
            if(P>1) tem2 = neg[0]*neg[1]*neg[2]*pos[P-1]*pos[P-2];
            if(c==5) cout<<max({tem,tem1,tem2})<<endl;
            else cout<<max(tem1, tem2)<<endl;
        }
        else if(N>=4){
            ll tem1=-1e18;
            if(P>2) tem1= neg[0]*neg[1]*pos[P-1]*pos[P-2]*pos[P-3];
            ll tem=1;
            forba(i, pos.sz-1, 0)
            {
               if(c==5) break;
               tem*=pos[i], c++;
            }
            ll tem2=-1e18;
            if(P>1) tem2 = neg[0]*neg[1]*neg[2]*pos[P-1]*pos[P-2];
            ll tem3 = neg[0]*neg[1]*neg[2]*neg[3]*pos[P-1];
            if(c==5) cout<<max({tem,tem1,tem3,tem2})<<endl;
            else cout<<max({tem1,tem3,tem2})<<endl;
        }
    }
}
