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
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> b(n, vector<ll>(m));
    rep(i,0,n)rep(j,0,m)cin>>b[i][j];
    rep(i,0,n)rep(j,0,m)b[i][j]--;
    bool flag = true;
    rep(i,0,n){
        ll st = b[i][0];
        if (st%7+m-1>=7){
            flag = false;
        }
        rep(j,0,m){
            if (b[i][j]!=st+j){
                flag = false;
            }
        }
    }
    rep(j,0,m){
        ll st = b[0][j];
        rep(i,0,n){
            if (b[i][j]!=st+7*i){
                flag =false;
            }
        }
    }
    YesNo(flag);
    return 0;
}