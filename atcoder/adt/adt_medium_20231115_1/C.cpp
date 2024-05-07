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
const ll INF = (ll)1e18+10;

int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n),b(k);
    rep(i,0,n)cin>>a[i];
    rep(i,0,k)cin>>b[i];
    bool flag = false;
    ll me = *max_element(all(a));
    vector<ll>arr;
    rep(i,0,n)if(a[i]==me)arr.push_back(i+1);
    for (auto x: arr){
        if (find(all(b), x) != b.end()) flag = true;
    }
    YesNo(flag);
    return 0;
}