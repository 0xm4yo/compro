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
    vector<string> s(10);
    rep(i,0,10) cin >> s[i];
    ll a = 11;
    ll b = -1;
    ll c = 11;
    ll d = -1;
    rep(i,0,10)rep(j,0,10){
        if (s[i][j]=='#'){
            chmin(a, i+1);
            chmax(b, i+1);
            chmin(c, j+1);
            chmax(d, j+1);
        }
    }
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
    return 0; 
}