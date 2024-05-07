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
    ll n;
    cin>>n;
    vector<ll>a(n),p(n);
    rep(i,0,n)cin>>a[i];
    rep(i,1,n)cin>>p[i];
    vector<vector<ll>> g(n);
    rep(i,1,n){
        p[i]--;
        g[p[i]].push_back(i);
    }
    vector<ll>dp(n),tot(n+1);
    rep(i,0,n){
        for (auto nex: g[i]){
            dp[nex] += dp[i] + 1;
        }
    }
    rep(i,0,n){
        tot[dp[i]] += a[i];
    }
    rrep(i,n,0){
        if (tot[i]!=0){
            if (tot[i]>0){
                cout << '+' << endl;
                return 0;
            }
            if (tot[i]<0){
                cout << '-' << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}