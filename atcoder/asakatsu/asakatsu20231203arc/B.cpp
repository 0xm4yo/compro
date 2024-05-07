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
    vector<vector<ll>> a(n,vector<ll>(n));
    ll cnt = 0;
    rep(i,0,n)rep(j,0,n){
        cnt++;
        a[i][j] = cnt;
    }
    rep(i,1,n-1)rep(j,0,n-1){
        if (j%2)continue;
        swap(a[i][j],a[i][j+1]);
    }
    for (auto arr: a){
        for (auto x: arr){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}