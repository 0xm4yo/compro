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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll>cnt(10);
    rep(i,0,n){
        cnt[s[i]-'0']++;
    }
    ll ans = 0;
    rep(i,0,10000000){
        string t = to_string(i*i);
        if (t.size()>n)break;
        string k = "";
        while(t.size()+k.size()<n){
            k += '0';
        }
        auto t2 = k + t;
        vector<ll>cnt2(10);
        rep(j,0,n) cnt2[t2[j]-'0']++;
        if (cnt==cnt2) ans++;
    }
    cout << ans << endl;
    return 0;
}