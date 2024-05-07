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
    string s;
    cin>>s;
    vector<ll>cnt(26);
    rep(i,0,s.size())cnt[s[i]-'a']++;
    ll cnt1 = 0;
    rep(i,0,26)if(cnt[i]%2){ cnt1++; cnt[i]--; }
    ll cnt2 = 0;
    rep(i,0,26)if(cnt[i]%2==0){ cnt2 += cnt[i]/2; }
    if (cnt1==0)cout<<s.size();
    else cout << 1 + cnt2/cnt1 * 2 << endl;;
    
    return 0;
}