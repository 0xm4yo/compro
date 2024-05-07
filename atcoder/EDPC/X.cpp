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
const ll INF = (ll)3e15;

int main()
{
    ll n;
    cin>>n;
    vector<ll>w(n), s(n), v(n);
    rep(i,0,n)cin>>w[i]>>s[i]>>v[i];
    
    auto cmp = [&](ll a, ll b){
        return s[a]+w[a] < s[b]+w[b];
    };
    vector<ll>arr;
    rep(i,0,n)arr.push_back(i);
    stable_sort(all(arr), cmp);
    ll SMAX = 20010;
    vector<vector<ll>>dp(n+1, vector<ll>(SMAX, -INF));
    dp[0][0] = 0;
    rep(i,0,n)rep(j,0,SMAX){
        ll x = arr[i];
        chmax(dp[i+1][j], dp[i][j]);
        if (j>s[x])continue;
        if (j+w[x]<SMAX) chmax(dp[i+1][j+w[x]], dp[i][j]+v[x]);
    }

    cout << *max_element(all(dp[n])) << endl;

    return 0;
}