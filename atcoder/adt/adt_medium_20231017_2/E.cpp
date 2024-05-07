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
    ll h,w;
    cin>>h>>w;
    vector<string> s(h),t(h);
    rep(i,0,h)cin>>s[i];
    rep(i,0,h)cin>>t[i];
    vector<string>ss, tt;
    rep(j,0,w){
        string stemp = "";
        string ttemp = "";
        rep(i,0,h){
            stemp += s[i][j];
            ttemp += t[i][j];
        }
        ss.push_back(stemp);
        tt.push_back(ttemp);
    }
    sort(all(ss));
    sort(all(tt));
    bool flag = true;
    rep(j,0,w) if(ss[j]!=tt[j]) flag = false;
    YesNo(flag);

    return 0;
}