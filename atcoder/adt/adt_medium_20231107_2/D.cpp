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
    ll r,c;
    cin>>r>>c;
    vector<string> s(r);
    rep(i,0,r)cin>>s[i];
    vector<vector<char>>ans(r, vector<char>(c, '#'));
    rep(i,0,r)rep(j,0,c){
        if (s[i][j]=='.'){ ans[i][j]='.'; continue; }
        if (s[i][j]=='#')continue;
        ll cnt = s[i][j]-'0';
        rep(h,i-cnt,i+cnt+1)rep(w,j-cnt,j+cnt+1){
            if (0<=h && h<r && 0<=w && w<c){
                if (abs(h-i)+abs(w-j)<=cnt) ans[h][w] = '.';
            }
        }
    }
    rep(i,0,r){
        rep(j,0,c)cout<<ans[i][j];
        cout<<endl;
    }

    return 0;
}