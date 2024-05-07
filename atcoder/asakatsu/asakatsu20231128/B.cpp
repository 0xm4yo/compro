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
    ll h,w;
    cin>>h>>w;
    vector<string>s(h);
    rep(i,0,h)cin>>s[i];
    vector<string>ans(h+2);
    rep(j,0,w+2)ans[0]+='#';
    rep(j,0,w+2)ans[h+1]+='#';
    rep(i,1,h+1){
        string temp = "#";
        temp += s[i-1];
        temp += '#';
        ans[i] = temp;
    }
    for (auto a: ans){
        cout << a << endl;
    }
    return 0;
}