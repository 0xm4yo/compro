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
    vector<ll>arr(4);
    rep(i,0,4)cin>>arr[i];
    bool flag = false;
    
    rep(s,1,1LL<<4){
        ll rem = 0;
        ll tot = 0;
        rep(i,0,4){
            if (s&(1LL<<i)) tot += arr[i];
            else rem += arr[i];
        }
        if (tot==rem) flag = true;
    }
    YesNo(flag);
    return 0;
}