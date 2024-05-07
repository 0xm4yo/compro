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
    vector<vector<ll>> a(9,vector<ll>(9));
    rep(i,0,9)rep(j,0,9) cin>>a[i][j];
    rep(i,0,9)rep(j,0,9) a[i][j]--;
    bool flag = true;
    rep(i,0,9){
        vector<ll> cnt(9);
        rep(j,0,9) cnt[a[i][j]]++;
        if (count(all(cnt),0)) flag = false;
    }
    rep(j,0,9){
        vector<ll> cnt(9);
        rep(i,0,9) cnt[a[i][j]]++;
        if (count(all(cnt),0)) flag = false;
    }
    rep(i,0,9)rep(j,0,9){
        if (i%3 || j%3) continue;
        vector<ll> cnt(9);
        rep(k,0,3){
            rep(l,0,3){
                cnt[a[i+k][j+l]]++;
            }
        }
        if (count(all(cnt),0)) flag = false;
    }
    YesNo(flag);
    return 0;
}