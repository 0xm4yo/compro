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
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>>p(n, vector<ll>(3));
    vector<ll>arr;
    rep(i,0,n){
        ll tot = 0;
        rep(j,0,3){
            cin >> p[i][j];
            tot += p[i][j];
        }
        arr.push_back(tot);
    }
    sort(all(arr));
    reverse(all(arr));
    ll b = arr[k-1];
    rep(i,0,n){
        ll tot = 0;
        rep(j,0,3) tot += p[i][j];
        bool flag = false;
        if (tot+300>=b) flag = true;
        YesNo(flag);
    }
    return 0;
}