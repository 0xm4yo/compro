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

using mint = modint1000000007;

int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    mint ans = 1;

    vector<ll>cnt(26);
    rep(i,0,n) cnt[s[i]-'a']++;
    rep(i,0,26){
        ans *= cnt[i]+1;
    }
    cout << ans.val()-1 << endl;

    return 0;
}