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

using mint = modint998244353;

int main()
{
    ll h,w;
    cin>>h>>w;
    vector<string>ss(h);
    rep(i,0,h)cin>>ss[i];
    vector<vector<char>> s(h,vector<char>(w));
    rep(i,0,h)rep(j,0,w) s[i][j] = ss[i][j];

    rep(i,0,h-1)rep(j,0,w-1){
        if (s[i][j+1] == '.'){
            if (s[i+1][j] == 'R') s[i][j+1] = 'R';
            if (s[i+1][j] == 'B') s[i][j+1] = 'B';
        }
        if (s[i+1][j] == '.'){
            if (s[i][j+1] == 'R') s[i+1][j] = 'R';
            if (s[i][j+1] == 'B') s[i+1][j] = 'B';
        }        
    }
    rrep(i,h-2,0)rrep(j,w-2,0){
        if (s[i][j+1] == '.'){
            if (s[i+1][j] == 'R') s[i][j+1] = 'R';
            if (s[i+1][j] == 'B') s[i][j+1] = 'B';
        }
        if (s[i+1][j] == '.'){
            if (s[i][j+1] == 'R') s[i+1][j] = 'R';
            if (s[i][j+1] == 'B') s[i+1][j] = 'B';
        }        
    }

    mint ans = 1;
    vector<vector<bool>> v(h,vector<bool>(w));
    rep(i,0,h-1)rep(j,0,w-1){
        if (s[i][j+1] != s[i+1][j]){
            ans *= 0;
        }else{
            if (s[i][j+1]=='.'){
                if (!v[i][j+1] && !v[i+1][j]) ans *= 2;
                v[i][j+1] = true;
                v[i+1][j] = true;
            }
        }
    }

    if (s[0][0]=='.') ans*=2;
    if (s[h-1][w-1]=='.') ans*=2;
    cout << ans.val() << endl;
    return 0;
}