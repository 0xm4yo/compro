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
    ll n,K;
    cin>>n>>K;
    string s;
    cin>>s;
    ll ans = INF;
    rep(i,1,n+1){
        if (n%i)continue;
        ll temp = 0;
        rep(j,0,i){
            vector<ll>cnt(26);
            rep(k,0,n/i){
                cnt[s[j+i*k]-'a']++;
            }
            ll mx = *max_element(all(cnt));
            ll sm = accumulate(all(cnt),0LL);
            temp += sm - mx;
        }
        if (temp<=K) chmin(ans, i);
    }
    cout << ans << endl;
    return 0;
}