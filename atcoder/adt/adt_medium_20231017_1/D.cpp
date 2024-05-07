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
    ll n,m;
    cin>>n>>m;
    vector<vector<bool>> arr(n, vector<bool>(n));
    rep(i,0,m){
        ll k;
        cin>>k;
        vector<ll> v;
        rep(j,0,k){
            ll x;
            cin>>x;
            x--;
            v.push_back(x);
        }
        for (auto x: v){
            for (auto y: v){
                arr[x][y] = true;
                arr[y][x] = true;
            }
        }
    }
    bool flag = true;
    rep(i,0,n)rep(j,0,n)if(!arr[i][j]) flag = false;
    YesNo(flag);
    return 0;
}