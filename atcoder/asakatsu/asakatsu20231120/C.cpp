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
ll INF = (ll)1e9;

int main()
{
    ll n,k,s;
    cin>>n>>k>>s;
    vector<ll>arr;
    rep(i,0,k)arr.push_back(s);
    if (s==INF) INF -= 100;
    while(arr.size()<n){
        arr.push_back(INF);
    }
    for (auto a: arr){
        cout << a << endl;
    }

    return 0;
}