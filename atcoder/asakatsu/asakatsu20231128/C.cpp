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
    ll n,m;
    cin>>n>>m;
    vector<string>s(n);
    rep(i,0,n)cin>>s[i];
    vector<ll>cnt(2);
    rep(i,0,n){
        ll temp = 0;
        rep(j,0,m){
            if (s[i][j]=='0') temp^=1;
        }
        cnt[temp]++;
    }
    ll ans = n*(n-1)/2 - (cnt[0]*(cnt[0]-1)/2 + cnt[1]*(cnt[1]-1)/2);
    cout << ans << endl;
    return 0;
}