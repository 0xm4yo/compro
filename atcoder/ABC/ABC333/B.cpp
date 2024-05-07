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
    string ss, tt;
    cin>>ss>>tt;
    sort(all(ss));
    sort(all(tt));
    ll d1 = 1;
    ll d2 = 1;
    if (char(ss[0]+1)!=ss[1]){
        if (ss[0]=='A'&&ss[1]=='E'){
            d1 = 1;
        }else{
            d1 = 2;
        }
    }
    if (char(tt[0]+1)!=tt[1]){
        if (tt[0]=='A'&&tt[1]=='E'){
            d2 = 1;
        }else{
            d2 = 2;
        }
    }
    YesNo(d1==d2);
    return 0;
}