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
    vector<string>s(3);
    rep(i,0,3)cin>>s[i];
    ll now = 0;
    vector<ll>pos(3);
    ll ans = 0;
    while(1){
        if (pos[now]==s[now].size()){
            ans = now;
            break;
        }
        ll nex = s[now][pos[now]] - 'a';
        pos[now]++;
        now = nex;
    }
    char a = ans + 'A';
    cout << a << endl;
}