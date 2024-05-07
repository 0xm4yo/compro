#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = numeric_limits<ll>::max();

int main()
{
    ll n;
    cin>>n;
    string t;
    cin>>t;
    vector<ll>dx = {1,0,-1,0};
    vector<ll>dy = {0,-1,0,1};
    ll x = 0;
    ll y = 0;
    ll mode = 0;
    rep(i,0,n){
        if (t[i]=='S'){
            x += dx[mode];
            y += dy[mode];
        }else{
            mode++;
            mode%=4;
        }
    }
    cout << x << " " << y << endl;
    return 0;
}