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
    vector<vector<ll>> a(n+1,vector<ll>(n+1));
    a[0][0] = 1;
    rep(i,0,n)rep(j,0,i+1){
        a[i+1][j] += a[i][j];
        a[i+1][j+1] += a[i][j];
    }
    rep(i,0,n){
        rep(j,0,i+1){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}