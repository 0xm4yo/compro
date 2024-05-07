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
    ll n,a,b;
    cin>>n>>a>>b;
    vector<vector<char>> ans(n*a, vector<char>(n*b));
    rep(i,0,n*a)rep(j,0,n*b){
        if (((i/a)%2 + (j/b)%2)%2) ans[i][j] = '#';
        else ans[i][j] = '.';
    }
    rep(i,0,n*a){
        rep(j,0,n*b){
            cout << ans[i][j];
        }
        cout << endl;
    }
    
    return 0;
}