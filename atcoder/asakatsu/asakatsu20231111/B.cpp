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
    string s;
    cin>>s;
    sort(all(s));
    ll ans = 0;
    do{
        rep(i,1,s.size()){
            string l = "";
            rep(j,0,i) l += s[j];
            string r = "";
            rep(j,i,s.size()) r += s[j];
            chmax(ans, stoll(l)*stoll(r));
        }
    }while(next_permutation(all(s)));
    cout << ans << endl;
    return 0;
}