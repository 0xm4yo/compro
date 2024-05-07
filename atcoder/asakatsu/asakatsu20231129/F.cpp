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
const ll INF = (ll)1e10+10;

int main()
{
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>>a(n, vector<ll>(n));
    rep(i,0,n)rep(j,0,n)cin>>a[i][j];

    ll pos = k*k/2 + 1;

    ll l = 0;
    ll r = INF;
    while(r-l>1){
        ll mid = (l+r)/2;
        bool flag = true;
        vector<vector<ll>> b(n,vector<ll>(n));
        rep(i,0,n){
            rep(j,0,n){
                if (a[i][j]>=mid){
                    b[i][j] = 1;
                }else{
                    b[i][j] = 0;
                }
            }
        }
        vector<vector<ll>> cum(n+1, vector<ll>(n+1));
        rep(i,0,n)rep(j,0,n){
            cum[i+1][j+1] = cum[i+1][j] + cum[i][j+1] - cum[i][j] + b[i][j];
        }
        rep(i,0,n){
            if (i+k>n)break;
            rep(j,0,n){
                if (j+k>n)break;
                ll cnt = cum[i+k][j+k] - cum[i+k][j] - cum[i][j+k] + cum[i][j];
                if (cnt<pos) flag = false;
            }        
        }
        if (!flag){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << l << endl;

    return 0;
}