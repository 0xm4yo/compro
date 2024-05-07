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
const ll INF = (ll)1e15;

int main()
{
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    vector<ll> arr(200000);
    rep(i,0,100020){
        vector<bool> vis(3);
        if (i-x>=0) vis[arr[i-x]] = true;
        if (i-y>=0) vis[arr[i-y]] = true;
        rep(j,0,3){
            if (!vis[j]){
                arr[i] = j;
                break;
            }
        }
    }
    ll g = 0;
    rep(i,0,n){
        g ^= arr[a[i]];
    }
    if (g){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }
    return 0;
}