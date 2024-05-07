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
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    bool flag = false;
    rep(dx1,-2,3)rep(dy1,-2,3)rep(dx2,-2,3)rep(dy2,-2,3){
        if (abs(dx1)+abs(dy1)!=3) continue;
        if (abs(dx2)+abs(dy2)!=3) continue;
        if (x1+dx1==x2+dx2&&y1+dy1==y2+dy2) flag = true; 
    }
    YesNo(flag);
    return 0;
}