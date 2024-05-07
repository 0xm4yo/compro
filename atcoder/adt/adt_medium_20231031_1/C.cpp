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
    string s;
    cin>>s;
    ll fb = 0, lb = 0;
    ll pos = -1;
    rep(i,0,s.size()){
        if (s[i]=='K') pos=i;
        if (s[i]!='B') continue;
        if (fb==0){
            fb=i+1;
        }else{
            lb=i+1;
        }
    }
    if (fb%2==lb%2){
        cout << "No" << endl;
        return 0;
    }
    bool f1 = false;
    bool f2 = false;
    rep(i,0,pos) if(s[i]=='R') f1 = true;
    rep(i,pos,s.size()) if(s[i]=='R') f2 = true;
    YesNo(f1&f2);

    return 0;
}