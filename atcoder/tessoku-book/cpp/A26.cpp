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
const ll INF = (ll)1e15;

int main()
{
    ll q;
    cin>>q;
    vector<bool> p(300300, true);
    rep(i,2,300010){
        if (!p[i])continue;
        ll pos = i+i;
        while (pos <= 300010){
            p[pos] = false;
            pos += i;
        }
    }
    while (q){
        q--;
        ll x;
        cin>>x;
        YesNo(p[x]);
    }

    return 0;
}