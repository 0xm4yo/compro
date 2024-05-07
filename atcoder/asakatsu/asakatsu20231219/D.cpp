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
    vector<string>a(n),b(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,m)cin>>b[i];
    if (n<m){
        cout << "No" << endl;
        return 0;
    }
    rep(i,0,n)rep(j,0,n){
        if (i+m>n) continue;
        if (j+m>n) continue;
        bool flag = true;
        rep(k,s,m)rep(l,0,m){
            if (a[i+k][j+l]!=b[k][l])flag = false;
        }
        if (flag){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;    
    return 0;
}