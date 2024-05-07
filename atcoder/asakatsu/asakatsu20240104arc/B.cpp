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
    vector<vector<ll>>ans(n,vector<ll>(n));
    ll now = 0;
    rep(i,0,n)rep(j,0,n){
        now++;
        ans[i][j] = now;
    }
    rep(i,0,n)rep(j,0,n){
        if (j%2) continue;
        if (j+1>=n)continue;
        swap(ans[i][j], ans[i][j+1]);
    }
    for (auto a: ans){
        for (auto b: a){
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}