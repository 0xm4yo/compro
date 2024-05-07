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
#define int long long

int main()
{
    ll n;
    cin>>n;
    vector<string> s(n);
    rep(i,0,n)cin>>s[i];
    vector<ll> cnt(n);
    rep(i,0,n)rep(j,0,n){
        if (s[i][j]=='o') cnt[i]++;
    }
    vector<ll>cnt2(n);
    rep(j,0,n)rep(i,0,n){
        if (s[i][j]=='o') cnt2[j]++;
    }
    ll ans = 0;
    rep(i,0,n){
        rep(j,0,n){
            if(s[i][j]=='x')continue;
            ans += (cnt[i]-1) * (cnt2[j]-1);
        }
    }
    cout << ans << endl;
    return 0;
}